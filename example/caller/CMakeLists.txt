set(SRC_LIST CallerUser.cc ../User.pb.cc ../Friend.pb.cc)

add_executable(consumer ${SRC_LIST})
target_link_libraries(consumer rpc protobuf)