//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SAVECOMMAND_H
#define JSON_PARSER_SAVECOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SaveCommand : public ICommand {
    SaveCommand(): ICommand (std::string("save")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_SAVECOMMAND_H
