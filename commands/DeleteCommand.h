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
        assert(arguments.size() == 1);
        jsonManager.deleteByPath(arguments[0]);
    }
};
#endif //JSON_PARSER_DELETECOMMAND_H
