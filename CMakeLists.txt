cmake_minimum_required(VERSION 3.14)
project(JSON_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(JSON_parser main.cpp commands/ICommand.h commands/ValidateCommand.h commands/PrintCommand.h commands/SearchCommand.h commands/SetCommand.h commands/CreateCommand.h commands/DeleteCommand.h commands/MoveCommand.h commands/SaveCommand.h commands/SaveAsCommand.h dbmanager/JsonManager.cpp dbmanager/JsonManager.h model/JsonString.h model/JsonValue.h model/JsonNumber.h model/JsonObject.h model/JsonBoolean.h model/JsonArray.h model/JsonArray.cpp model/JsonBoolean.cpp model/JsonNumber.cpp model/JsonObject.cpp model/JsonString.cpp Invoker.cpp Invoker.h commands/OpenFileCommand.h commands/HelpCommand.h commands/CloseCommand.h)