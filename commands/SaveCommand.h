//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SAVECOMMAND_H
#define JSON_PARSER_SAVECOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SaveCommand : public ICommand {
public:
    SaveCommand(): ICommand (std::string("save")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.empty());
        jsonManager.save();
    }
};
#endif //JSON_PARSER_SAVECOMMAND_H
