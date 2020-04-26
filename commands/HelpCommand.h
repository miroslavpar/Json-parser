//
// Created by Miroslav Parapanov on 2020-04-26.
//

#ifndef JSON_PARSER_HELPCOMMAND_H
#define JSON_PARSER_HELPCOMMAND_H

#include "ICommand.h"

class HelpCommand : public ICommand{
public:
    HelpCommand(): ICommand (std::string("help")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.empty());
        jsonManager.help();
    }
};
#endif //JSON_PARSER_HELPCOMMAND_H
