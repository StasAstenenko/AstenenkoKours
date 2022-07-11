

#ifndef ASTENENKO_ZOOPARKCONTROLLER_H
#define ASTENENKO_ZOOPARKCONTROLLER_H


#include <vector>
#include <iostream>
#include <iomanip>
#include "ZooPark.h"
#include "../infrastructure/controller/AbstractStorageController.h"

class ZooParkController : public AbstractStorageController<ZooParkController, ZooPark>{
private:
    static inline void printSep(){
        std::cout<<"+"<<std::setw(2)<<std::setfill('-')<<"";
        std::cout<<"+"<<std::setw(10)<<"";
        std::cout<<"+"<<std::setw(10)<<""<<"+\n";
    }
public:
    ZooParkController() = default;

    void print() override {

        printSep();
        std::cout<<std::setfill(' ')<<std::left;
        std::cout <<"|"<<std::setw(2)<<"id";
        std::cout <<"|"<<std::setw(10)<<"name";
        std::cout <<"|"<<std::setw(10)<<"animals";
        std::cout <<"|\n";
        printSep();
        std::cout<<std::setfill(' ')<<std::left;
        for (int i = 0; i < this->getStorage()->size(); ++i) {
            std::cout << "|" << std::setw(2)<<i;
            std::cout << *this->getStorage()->at(i);
        }
        printSep();

    }

    std::string name() override {
        return "zoo";
    }

    void create() override {
        std::string name;

        std::cout << "name >";
        std::cin>>name;
        ZooPark* zoo = new ZooPark(name);
        this->add(zoo);
    }

    void remove() override {
        this->getStorage()->erase(this->getStorage()->begin()+selectId());
    }

    void addAnimal(Animal* pAnimal) {
        auto it = (this->getStorage()->begin()+selectId());
        (*it)->addAnimal(pAnimal);
    }

    void moveAnimal(const std::string& zooFrom, const std::string& zooTo, const std::string& animalName) {
        auto& storage = *getStorage();
        auto foundZooFrom = std::find_if(storage.begin(), storage.end(), [&zooFrom]( ZooPark* pZooPark) {return pZooPark->getName() == zooFrom;});
        if(foundZooFrom != storage.end()){
            auto foundZooTo = std::find_if(storage.begin(), storage.end(), [&zooTo]( ZooPark* pZooPark) {return pZooPark->getName() == zooTo;});
            if(foundZooTo != storage.end()){
                auto* pAnimal = (*foundZooFrom)->popAnimal(animalName);
                if (pAnimal != nullptr){
                    (*foundZooTo)->addAnimal(pAnimal);
                } else{
                    std::cout<<"Animal with name \""<<animalName<<"\" not found";
                }
            }
            else
            {
                std::cout<<"ZooPark with name \""<<zooTo<<"\" not found";
            }
        }
        else
        {
            std::cout<<"ZooPark with name \""<<zooFrom<<"\" not found";
        }

    }
};

Init(ZooParkController)

#endif //ASTENENKO_ZOOPARKCONTROLLER_H
