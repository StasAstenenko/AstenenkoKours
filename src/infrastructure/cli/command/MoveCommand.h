
#ifndef ASTENENKO_MOVECOMMAND_H
#define ASTENENKO_MOVECOMMAND_H

#include <utility>
#include "../ICommand.h"


template<typename ZooController>
class MoveCommand : public ICommand{
    IController<ZooController>* zooController;
public:
    MoveCommand(IController<ZooController>* zooController) :
            zooController(zooController) {}
    void handle(AppContext *context, std::vector<std::string> args) override {
        std::string animalName;
        std::string zooFrom;
        std::string zooTo;
        std::cout<<"Zoo from > ";
        std::cin>>zooFrom;
        std::cout<<"Zoo to > ";
        std::cin>>zooTo;
        std::cout<<"Animal name > ";
        std::cin>>animalName;
        zooController->moveAnimal(zooFrom, zooTo, animalName);

    }

    std::string getName() override {
        return "move";
    }

    std::string getAliases() override {
        return "delivery to the zoo";
    }
};

#endif //ASTENENKO_MOVECOMMAND_H
