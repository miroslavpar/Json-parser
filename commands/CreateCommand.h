//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_CREATECOMMAND_H
#define JSON_PARSER_CREATECOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"


class CreateCommand : public ICommand {
    CreateCommand(): ICommand (std::string("create")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_CREATECOMMAND_H
