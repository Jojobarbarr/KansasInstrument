cmake_minimum_required(VERSION 3.10)

# set the project name
project(KansasInstrument VERSION 1.0)

# specify the C++ standard
# use the CMAKE_CXX_STANDARD variable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#add libraries
add_subdirectory(src/basic)

#add executable
option(KANSASINSTRUMENT_WITH_EXECUTABLES "Compile mains" ON)

if(KANSASINSTRUMENT_WITH_EXECUTABLES)
	message(STATUS "Configuring KansasInstrument with executables")
	add_subdirectory(mains)
endif()

#add tests
option(KANSASINSTRUMENT_WITH_TESTS "Compile tests" ON)

if(KANSASINSTRUMENT_WITH_TESTS)
	enable_testing()
	message(STATUS "Configuring KansasInstrument with tests")
	add_subdirectory(tests)
endif()

# Configure CPack
if(WIN32)
	set(CPACK_GENERATOR "ZIP")
else()
	set(CPACK_GENERATOR "TGZ")
endif()

# This must always be last!
include(CPack)