//
// Created by Miroslav Parapanov on 2020-05-21.
//

#ifndef JSON_PARSER_EXITCOMMAND_H
#define JSON_PARSER_EXITCOMMAND_H

#include "ICommand.h"

class ExitCommand : public ICommand{
public:
    ExitCommand(): ICommand (std::string("exit")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.empty());
        jsonManager.exitFromFunction();

    }
};
#endif //JSON_PARSER_EXITCOMMAND_H
