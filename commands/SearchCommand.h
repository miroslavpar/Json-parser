//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_SEARCHCOMMAND_H
#define JSON_PARSER_SEARCHCOMMAND_H

#include "ICommand.h"
#include "../dbmanager/JsonManager.h"

class SearchCommand : public ICommand {
public:
    SearchCommand(): ICommand (std::string("search")) {};
    void execute(JsonManager& jsonManager) {
        assert(arguments.size() == 1);
        jsonManager.search(arguments[0]);
    }
};
#endif //JSON_PARSER_SEARCHCOMMAND_H
