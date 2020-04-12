//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_VALIDATECOMMAND_H
#define JSON_PARSER_VALIDATECOMMAND_H


#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class ValidateCommand : public ICommand {
public:
    ValidateCommand(): ICommand (std::string("validate")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.empty());
        jsonManager.validateJsonFile();
    }
};



#endif //JSON_PARSER_VALIDATECOMMAND_H
