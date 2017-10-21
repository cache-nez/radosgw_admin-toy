//
// Created by cache-nez on 20.10.17.
//

#ifndef RADOSGW_ADMIN_USER_COMMANDS_H
#define RADOSGW_ADMIN_USER_COMMANDS_H

#include <boost/program_options.hpp>

void handle_user_commands(const boost::program_options::parsed_options& options,
                          boost::program_options::variables_map& var_map);

#endif //RADOSGW_ADMIN_USER_COMMANDS_H
