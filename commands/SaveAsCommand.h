//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SAVEASCOMMAND_H
#define JSON_PARSER_SAVEASCOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SaveAsCommand : public ICommand {
    SaveAsCommand(): ICommand (std::string("saveas")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_SAVEASCOMMAND_H
