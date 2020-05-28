//
// Created by Miroslav Parapanov on 2020-04-26.
//

#include "Invoker.h"
#include "commands/OpenFileCommand.h"
#include "commands/ValidateCommand.h"
#include "commands/SearchCommand.h"
#include "commands/PrintCommand.h"
#include "commands/HelpCommand.h"
#include "commands/CloseCommand.h"
#include "commands/SaveCommand.h"
#include "commands/SaveAsCommand.h"
#include "commands/ExitCommand.h"
#include "commands/SetCommand.h"




Invoker::Invoker() {
    commands.push_back(make_unique<OpenFileCommand>());
    commands.push_back(make_unique<ValidateCommand>());
    commands.push_back(make_unique<SearchCommand>());
    commands.push_back(make_unique<PrintCommand>());
    commands.push_back(make_unique<HelpCommand>());
    commands.push_back(make_unique<CloseCommand>());
    commands.push_back(make_unique<SaveCommand>());
    commands.push_back(make_unique<SaveAsCommand>());
    commands.push_back(make_unique<ExitCommand>());
    commands.push_back(make_unique<SetCommand>());


}
void Invoker::run() {
    string line;
    for(;;){
        cout << "$: ";
        getline(cin, line);
        parseLine(line);
    }
}
void Invoker::parseLine(string& line) {
    stringstream stream;
    stream << line;
    string commandName;
    stream >> commandName;
    vector<string> arguments;
    string argument;
    while(stream >> argument) {
        arguments.push_back(argument);
    }
    applyArguments(commandName, arguments);
}
void Invoker::applyArguments(const string &commandName, vector<string> arguments) {
    int counterForCommands = 0;
    for(auto& command: commands) {
        if(command->convertToString() == commandName) {
            command->setArguments(arguments);
            command->execute(jsonManager);
            counterForCommands++;
        }
    }
    if(counterForCommands == 0){
        cout << "WRONG COMMAND\n";
        cout << "Please use \"help\" coomand to see supported commands!\n";
    }
}