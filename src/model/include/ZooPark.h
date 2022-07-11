

#ifndef ASTENENKO_ZOOPARK_H
#define ASTENENKO_ZOOPARK_H


#include <string>
#include "../animal/Animal.h"

class ZooPark {
public:
    friend std::ostream& operator<<(std::ostream& os, const ZooPark& dt);

    ZooPark(std::string name) : name(std::move(name)) {}

    const std::string& getName() const {
        return name;
    }
    void addAnimal(Animal* pAnimal){
        animals.push_back(pAnimal);
    }

    void moveAnimal(Animal* pAnimal){
        animals.push_back(pAnimal);
    }
    Animal* popAnimal(const std::string& name){
        Animal* pResult = nullptr;
        auto& storage = animals;
        auto it = std::find_if(storage.begin(), storage.end(), [&name](const Animal* pAnimal) {return pAnimal->getname() == name;});
        if (it != storage.end()){
            pResult = *it;
            storage.erase(it);
        }
        return pResult;
    }

private:
    std::string name;
    std::vector<Animal*> animals;
};

std::ostream &operator<<(std::ostream &os, const ZooPark &dt) {
    os << "|" << std::setw(10) << dt.name;
    os << "|" << std::setw(10) << dt.animals.size();
    os << "|\n";
    return os;
}


#endif //ASTENENKO_ZOOPARK_H
