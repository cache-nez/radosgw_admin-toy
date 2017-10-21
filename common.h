//
// Created by cache-nez on 20.10.17.
//

#ifndef RADOSGW_ADMIN_COMMON_H
#define RADOSGW_ADMIN_COMMON_H

#include <boost/program_options/options_description.hpp>
#include <boost/program_options.hpp>

constexpr char COMMAND_GROUP[] = "command_group";
constexpr char COMMAND[] = "command";

struct description {
    boost::program_options::options_description named_options;
    boost::program_options::positional_options_description pos_options;
};

void help_message();
void unrecognized_command_message(const std::string& command);

#endif //RADOSGW_ADMIN_COMMON_H
