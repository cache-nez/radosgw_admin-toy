//
// Created by cache-nez on 20.10.17.
//

#include <iostream>
#include "common.h"

using std::cout;

void unrecognized_command_message(const std::string& command) {
    cout << "Unrecognized command: " << command << std::endl;
}

void help_message() {
    cout << "usage: radosgw-admin <cmd> [options...]" << std::endl;
    cout << "commands:\n";
    cout << "  user create                create a new user\n" ;
    cout << "  user modify                modify user\n";
    cout << "  user info                  get user info\n";
    cout << "options:\n";
    cout << "   --uid=<id>                user id\n";
    cout << "   --email=<email>\n";
    cout << "   --display-name=<name>\n";
    cout << "\n";
}