set(SRC_LIST main.cc ../User.pb.cc ../Friend.pb.cc FriendService.cc UserService.cc)

add_executable(provider ${SRC_LIST})
target_link_libraries(provider rpc protobuf)