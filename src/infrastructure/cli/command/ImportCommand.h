
#ifndef ASTENENKO_IMPORTCOMMAND_H
#define ASTENENKO_IMPORTCOMMAND_H

#include <utility>
#include "../ICommand.h"

template<typename ZooController, typename AnimalController >
class ImportCommand : public ICommand{
    IController<ZooController>* zooController;
    IController<AnimalController>* animalController;
public:
    ImportCommand(IController<ZooController>* zooController, IController<AnimalController>* animalController) :
    zooController(zooController), animalController(animalController) {}
    void handle(AppContext *context, std::vector<std::string> args) override {
        std::string animalName;
        std::cout<<"Animal name > ";
        std::cin>>animalName;
        auto* pAnimal = animalController->popAnimal(animalName);
        if(pAnimal != nullptr){
            zooController->addAnimal(pAnimal);
        }
        else{
            std::cout<<"Animal \"" << animalName << "not found";
        }
    }

    std::string getName() override {
        return "import";
    }

    std::string getAliases() override {
        return "delivery to the zoo";
    }
};


#endif //ASTENENKO_IMPORTCOMMAND_H
