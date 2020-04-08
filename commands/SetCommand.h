//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SETCOMMAND_H
#define JSON_PARSER_SETCOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SetCommand : public ICommand {
    SetCommand(): ICommand (std::string("set")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_SETCOMMAND_H
