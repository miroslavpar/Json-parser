//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_MOVECOMMAND_H
#define JSON_PARSER_MOVECOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class MoveCommand : public ICommand {
    MoveCommand(): ICommand (std::string("move")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_MOVECOMMAND_H
