

#ifndef ASTENENKO_DELETECOMMAND_H
#define ASTENENKO_DELETECOMMAND_H
#include <utility>
#include "../ICommand.h"

template<typename Controller>
class DeleteCommand : public ICommand{
    IController<Controller>* controller;
public:
    explicit DeleteCommand(IController<Controller>* controller) : controller(controller) {}

    void handle(AppContext *context, std::vector<std::string> args) override {
        controller->remove();
    }

    std::string getName() override {
        return "delete";
    }

    std::string getAliases() override {
        return "delete " + controller->name();
    }

};

#endif //ASTENENKO_DELETECOMMAND_H
