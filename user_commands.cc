//
// Created by cache-nez on 20.10.17.
//

#include <iostream>
#include "user_commands.h"

#include "common.h"

using namespace boost::program_options;

namespace {
    const char DISPLAY_NAME[] = "display-name";
    const char EMAIL[] = "email";
    const char UID[] = "uid";

    options_description set_user_commands_description() {
        options_description user_desc{"Options of user command"};
        user_desc.add_options()
                (UID, value<int>(), "user id")
                (COMMAND, value<std::string>(), "create, delete or info");
        return user_desc;
    }

    options_description set_user_create_options() {
        options_description user_create_desc{"Options of user create"};
        user_create_desc.add_options()
                (DISPLAY_NAME, value<std::string>(), "user display name")
                (EMAIL, value<std::string>(), "user email");
        return user_create_desc;
    }

    void handle_user_create(const parsed_options& parsed_options, variables_map& var_map) {
        options_description user_desc = set_user_create_options();
        std::vector<std::string> unrecognized = collect_unrecognized(parsed_options.options, exclude_positional);
        store(command_line_parser(unrecognized)
                      .options(user_desc)
                      .run(),
              var_map);
        std::cout << "User created with uid " << var_map[UID].as<int>()
                  << ", display name " << var_map[DISPLAY_NAME].as<std::string>()
                  << " and email " << var_map[EMAIL].as<std::string>() << std::endl;
    }

    void handle_user_delete(const variables_map& var_map) {
        std::cout << "Deleted user " << var_map[UID].as<std::string>() << std::endl;
    }

    void handle_user_info(const variables_map& var_map) {
        std::cout << "Information about user " << var_map[UID].as<std::string>() << std::endl;
    }
} // namespace

void handle_user_commands(const parsed_options& options, variables_map& var_map) {
    options_description description_user = set_user_commands_description();
    std::vector<std::string> unrecognized = collect_unrecognized(options.options, exclude_positional);
    try {
        parsed_options new_options = command_line_parser{unrecognized}
                .options(description_user)
                .allow_unregistered()
                .run();
        store(new_options, var_map);
        notify(var_map);

        std::string command = var_map[COMMAND_GROUP].as<std::vector<std::string>>()[1];
        if (command == "create") {
            handle_user_create(new_options, var_map);
            return;
        }
        if (command == "delete") {
            handle_user_delete(var_map);
            return;
        }
        if (command == "info") {
            handle_user_info(var_map);
            return;
        }
        unrecognized_command_message(command);
        help_message();
    } catch (const error& ex) {
        std::cout << "Failed to parse passed options" << std::endl;
        help_message();
    }
}