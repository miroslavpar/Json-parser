//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_ICOMMAND_H
#define JSON_PARSER_ICOMMAND_H

#include <vector>
#include <string>
#include "../dbmanager/JsonManager.h"

class ICommand {
protected:
    std::string commandName;
    std::vector<std::string> arguments;

public:
    ICommand(){};
    ICommand(const std::string& commandNameTemp): commandName(commandNameTemp) {};
    virtual void execute(JsonManager &) {};
    void setArguments(std::vector<std::string>& _arguments) {
        this->arguments = _arguments;
    }
    std::string& convertToString() {
        return commandName;
    }
    virtual ~ICommand() {};
};



#endif //JSON_PARSER_ICOMMAND_H
