//
// Created by Miroslav Parapanov on 2020-04-26.
//

#ifndef JSON_PARSER_INVOKER_H
#define JSON_PARSER_INVOKER_H

#include <memory>
#include "dbmanager/JsonManager.h"
#include "commands/ICommand.h"

class Invoker {
private:
    vector<unique_ptr<ICommand>> commands;
    JsonManager jsonManager;
    void parseLine(string&);
    void applyArguments(const string& commandName, vector<string> arguments);
public:
    Invoker();
    void run();
};


#endif //JSON_PARSER_INVOKER_H
