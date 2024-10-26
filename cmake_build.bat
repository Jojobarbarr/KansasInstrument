if exist build rmdir build /s /q
cmake -D HELLOWORLD_WITH_EXECUTABLES="OFF" -D HELLOWORLD_WITH_TESTS="ON" -B build
cmake --build build --config Release