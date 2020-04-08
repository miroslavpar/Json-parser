//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_PRINTCOMMAND_H
#define JSON_PARSER_PRINTCOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class PrintCommand : public ICommand {
public:
    PrintCommand(): ICommand (std::string("print")) {};
    void execute(JsonManager& jsonManager) {
        //TODO JSON-Manager , assert, calling function from JSON-Manager

    }
};
#endif //JSON_PARSER_PRINTCOMMAND_H
