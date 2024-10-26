add_executable(test_lexer test_lexer.cpp)
target_link_libraries(test_lexer PUBLIC basic)
add_test(NAME test_lexer COMMAND test_lexer)

add_executable(test_custom_string test_custom_string.cpp)
target_link_libraries(test_custom_string PUBLIC basic)
add_test(NAME test_custom_string COMMAND test_custom_string)

add_executable(test_word test_word.cpp)
target_link_libraries(test_word PUBLIC basic)
add_test(NAME test_word COMMAND test_word)

add_executable(test_operator_sign test_operator_sign.cpp)
target_link_libraries(test_operator_sign PUBLIC basic)
add_test(NAME test_operator_sign COMMAND test_operator_sign)

add_executable(test_parser test_parser.cpp)
target_link_libraries(test_parser PUBLIC basic)
add_test(NAME test_parser COMMAND test_parser)
