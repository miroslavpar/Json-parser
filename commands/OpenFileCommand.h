//
// Created by Miroslav Parapanov on 2020-04-26.
//

#ifndef JSON_PARSER_OPENFILECOMMAND_H
#define JSON_PARSER_OPENFILECOMMAND_H

#include "ICommand.h"
#include <unistd.h>
class OpenFileCommand: public ICommand{
public:
    OpenFileCommand(): ICommand (std::string("open")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.size() == 1);
        cout << " File is opening . . .\n ";
        jsonManager.openFile(arguments[0]);
    }
};
#endif //JSON_PARSER_OPENFILECOMMAND_H
