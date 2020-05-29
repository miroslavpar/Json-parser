//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_CREATECOMMAND_H
#define JSON_PARSER_CREATECOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"


class CreateCommand : public ICommand {
public:
    CreateCommand(): ICommand (std::string("create")) {};
    void execute(JsonManager& jsonManager) {
        assert(!arguments.empty());
        stringstream argFromConsole;
        for (int i = 1 ; i <= arguments.size(); i++){
            argFromConsole << arguments[i];
        }
        jsonManager.create(arguments[0],argFromConsole);
    }
};
#endif //JSON_PARSER_CREATECOMMAND_H
