//
// Created by cache-nez on 20.10.17.
//

#include "radosgw_admin.h"

#include <boost/program_options.hpp>
#include <iostream>
#include "user_commands.h"
#include "common.h"

using namespace boost::program_options;

namespace {
    constexpr char HELP_COMMAND[] = "help";

    description set_general_options_description() {
        options_description desc{"General options"};
        desc.add_options()
                (HELP_COMMAND, "Help screen")
                (COMMAND_GROUP, value<std::vector<std::string>>(), "Command");

        positional_options_description pos_desc;
        pos_desc.add(COMMAND_GROUP, -1);
        return {desc, pos_desc};
    }
} // namespace

void handle_commands(int argc, const char *argv[]) {
    variables_map var_map;
    description general = set_general_options_description();
    parsed_options parsed_options = command_line_parser{argc, argv}
            .options(general.named_options)
            .positional(general.pos_options)
            .allow_unregistered()
            .run();
    store(parsed_options, var_map);
    notify(var_map);

    if (var_map.count(HELP_COMMAND))
        help_message();
    else if (var_map.count(COMMAND_GROUP)) {
        std::string command_group = var_map[COMMAND_GROUP].as<std::vector<std::string>>()[0];
        if (command_group == "user") {
            handle_user_commands(parsed_options, var_map);
        }
        else {
            unrecognized_command_message(command_group);
            help_message();
        }
    }
}