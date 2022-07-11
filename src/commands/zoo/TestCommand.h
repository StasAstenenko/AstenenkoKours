

#ifndef ASTENENKO_TESTCOMMAND_H
#define ASTENENKO_TESTCOMMAND_H


#include "../../infrastructure/cli/ICommand.h"

class TestCommand : public ICommand{

public:
    void handle(AppContext *context, std::vector<std::string> args) override {
        std::cout<<"test output command works\n";
    }

    std::string getName() override {
        return "test";
    }

    std::string getAliases() override {
        return "test command";
    }

};


#endif //ASTENENKO_TESTCOMMAND_H
