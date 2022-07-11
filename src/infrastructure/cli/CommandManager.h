

#ifndef ASTENENKO_COMMANDMANAGER_H
#define ASTENENKO_COMMANDMANAGER_H


#include <memory>
#include "ICommand.h"
#include "../AppContext.h"

class CommandManager {
private:
    std::vector<ICommand*> commands;

    ICommand* getCommand(std::string command_name){
        for (auto &command: commands){
            if(command->getName() == command_name){
                return command;
            }
        }
        throw std::runtime_error("command not found");
    }
public:
    void addCommand(ICommand* command){
        commands.push_back(command);
    }
    void handle(AppContext* context, std::string input){
        getCommand(input)->handle(context, {input});
    }
    friend std::ostream& operator<<(std::ostream& os, const CommandManager& dt){
        for (const auto &command: dt.commands){
            os<<command->getName() << " - " << command->getAliases()<<"\n";
        }
        os<<">";
        return os;
    }
};

#endif //ASTENENKO_COMMANDMANAGER_H
