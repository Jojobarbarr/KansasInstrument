# add the executable target named KansasInstrument
add_executable(KansasInstrument main.cpp)
target_link_libraries(KansasInstrument PRIVATE basic)

# add binary tree to the list of paths to search for include
# target_include_directories(KansasInstrument PUBLIC "${PROJECT_BINARY_DIR}")