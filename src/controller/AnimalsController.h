

#ifndef ASTENENKO_ANIMALSCONTROLLER_H
#define ASTENENKO_ANIMALSCONTROLLER_H


#include "../infrastructure/controller/IController.h"
#include "../model/animal/Animal.h"
#include "../infrastructure/controller/AbstractStorageController.h"
#include <algorithm>

class AnimalsController : public AbstractStorageController<AnimalsController, Animal>{
private:
    static void printSep(){
        std::cout<<"+"<<std::setw(5)<<std::setfill('-')<<"";//type
        std::cout<<"+"<<std::setw(5)<<""; //name
        std::cout<<"+"<<std::setw(5)<<""; //age
        std::cout<<"+"<<std::setw(5)<<""; //weight
        std::cout<<"+"<<std::setw(5)<<""; //hunger
        std::cout<<"+"<<std::setw(20)<<""<<"+\n"; //additional

    }
public:
    void print() override {
        printSep();
        std::cout<<std::setfill(' ')<<std::left;
        std::cout<<"|"<<std::setw(5)<<"type";//type
        std::cout<<"|"<<std::setw(5)<<"name";//name
        std::cout<<"|"<<std::setw(5)<<"age"; //age
        std::cout<<"|"<<std::setw(5)<<"weight"; //weight
        std::cout<<"|"<<std::setw(5)<<"hunger"; //hunger
        std::cout<<"|"<<std::setw(20)<<"additional"<<"|\n"; //additional
        printSep();
        std::cout<<std::setfill(' ');
        for (const auto &item: *this->getStorage()){
            std::cout<<*item;
        }
        printSep();
    }

    std::string name() override {
        return "animal";
    }

    void create() override {
        std::cout<<"select type:\n";
        for (const auto &item: *BaseAnimalFactory::getMap()){
            std::cout<<"\t"<<item.first<<"\n";
        }
        std::cout<<"type >";
        std::string type;
        std::cin>>type;
        this->add(BaseAnimalFactory::createInstance(type));
    }

    void remove() override {
        this->getStorage()->erase(this->getStorage()->begin()+selectId());
    }
    Animal* popAnimal(const std::string& name)override{
        Animal* pResult = nullptr;
        auto& storage = *getStorage();
        auto it = std::find_if(storage.begin(), storage.end(), [&name](const Animal* pAnimal) {return pAnimal->getname() == name;});
        if (it != storage.end()){
            pResult = *it;
            storage.erase(it);
        }
        return pResult;
    }
};

Init(AnimalsController)

#endif //ASTENENKO_ANIMALSCONTROLLER_H
