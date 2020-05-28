//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SAVEASCOMMAND_H
#define JSON_PARSER_SAVEASCOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SaveAsCommand : public ICommand {
public:
    SaveAsCommand(): ICommand (std::string("saveAs")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.size() == 1);
        jsonManager.saveAs(arguments[0]);

    }
};
#endif //JSON_PARSER_SAVEASCOMMAND_H
