//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_DELETECOMMAND_H
#define JSON_PARSER_DELETECOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class DeleteCommand : public ICommand {
    DeleteCommand(): ICommand (std::string("delete")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_DELETECOMMAND_H
