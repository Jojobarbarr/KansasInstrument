if exist build rmdir build /s /q
cmake -D HELLOWORLD_WITH_EXECUTABLES="OFF" -D HELLOWORLD_WITH_TESTS="ON" -B build
cmake --build build --config Release
ctest --test-dir build build -C Release
ctest --test-dir build --rerun-failed --output-on-failure -C Release