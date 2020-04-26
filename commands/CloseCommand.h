//
// Created by Miroslav Parapanov on 2020-04-26.
//

#ifndef JSON_PARSER_CLOSECOMMAND_H
#define JSON_PARSER_CLOSECOMMAND_H

#include "ICommand.h"

class CloseCommand: public ICommand{
public:
    CloseCommand(): ICommand (std::string("close")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.empty());
        jsonManager.closeFile();
    }
};
#endif //JSON_PARSER_CLOSECOMMAND_H
