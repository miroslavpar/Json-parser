//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SETCOMMAND_H
#define JSON_PARSER_SETCOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SetCommand : public ICommand {
public:
    SetCommand(): ICommand (std::string("set")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.empty());
        stringstream argFromConsole;
        for (int i = 1 ; i <= arguments.size(); i++){
            argFromConsole << arguments[i];
        }
        jsonManager.set(arguments[0],argFromConsole);
    }
};
#endif //JSON_PARSER_SETCOMMAND_H
