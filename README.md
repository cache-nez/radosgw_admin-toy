## A toy program illustrating usage of boost::program_options for arguments parsing
### Usage:

You may need to add the following line to CMakeLists.txt:

set(BOOST_ROOT /dir/containing/boost)

$ cmake .

$ make

$ ./radosgw-admin \<cmd> [options...]


Available commands and options:

--help

user create --pid=\<pid> --display-name=\<display-name> --email=\<email>

user delete --pid=\<pid>

user info --pid=\<pid>
