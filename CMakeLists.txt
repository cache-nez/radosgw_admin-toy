cmake_minimum_required(VERSION 3.5)
project(radosgw_admin)

set(BOOST_ROOT /usr/local/lib/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost COMPONENTS program_options REQUIRED)
set(SOURCE_FILES main.cc radosgw_admin.cc radosgw_admin.h user_commands.cc common.cc)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(radosgw_admin ${SOURCE_FILES})

if(Boost_FOUND)

    target_link_libraries(radosgw_admin ${Boost_LIBRARIES})

endif()