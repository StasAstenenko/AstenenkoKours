

#ifndef ASTENENKO_PRINT_H
#define ASTENENKO_PRINT_H


#include <utility>
#include "../ICommand.h"

template<typename Controller>
class PrintCommand : public ICommand{
    IController<Controller>* controller;
public:
    explicit PrintCommand(IController<Controller>* controller) : controller(controller){}

    void handle(AppContext *context, std::vector<std::string> args) override {
        controller->print();
    }

    std::string getName() override {
        return "print";
    }

    std::string getAliases() override {
        return "print info about " + controller->name();
    }

};


#endif //ASTENENKO_PRINT_H
