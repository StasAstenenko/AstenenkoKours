

#ifndef ASTENENKO_ANIMAL_H
#define ASTENENKO_ANIMAL_H


#include <string>
#include <map>
#include "../Food.h"

//template<typename T>
//struct AnimalFactory;


class Animal {
public:
    Animal(std::string kind,std::string name ,int age, int weight, uint8_t hungerP)
            : kind(std::move(kind)),name(std::move(name)), age(age), weight(weight), hunger_p(hungerP) {}

    const std::string &getKind() const {
        return kind;
    }
    const std::string &getname() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getWeight() const {
        return weight;
    }

    uint8_t getHungerP() const {
        return hunger_p;
    }

    virtual bool feed(Food& food){
        return true;
    }
    friend std::ostream& operator<<(std::ostream& os, const Animal& dt);
    virtual std::string info() const{
        return "";
    }

private:
    std::string kind;
    std::string name;
    int age;
    int weight;
    uint8_t hunger_p;
    //static AnimalFactory<Animal> reg;
};

std::ostream &operator<<(std::ostream &os, const Animal &dt) {
    os << "|" << std::setw(5) << dt.kind;
    os << "|" << std::setw(5) << dt.name;
    os << "|" << std::setw(5) << dt.age;
    os << "|" << std::setw(5) << dt.weight;
    os << "|" << std::setw(5) << std::to_string((int)dt.hunger_p)+"%";
    os << "|" << std::setw(20) << dt.info();
    os << "|\n";
    return os;
}


class BaseAnimalFactory {
public:
    typedef std::map<std::string, Animal*(*)()> map_type;

    static Animal * createInstance(std::string const& s) {
        auto it = getMap()->find(s);
        if(it == getMap()->end())
            return nullptr;
        return it->second();
    }

public:
    static map_type * getMap() {
        // never delete'ed. (exist until program termination)
        // because we can't guarantee correct destruction order
        if(!map) { map = new map_type; }
        return map;
    }

private:
    inline static map_type * map = new map_type;
};

/*template<typename T> Animal * createT() { return new T("", 1, 1, 1); }

template<typename T>
struct AnimalFactory : BaseAnimalFactory{
    explicit AnimalFactory(std::string const& s) {
        getMap()->insert(std::make_pair(s, &createT<T>));
        //(*getMap())[s] = &AnimalFactory::create;
    }
private:
    static Animal* create(){
        std::string kind;
        int age;
        int weight;
        uint8_t hunger_p;

        std::cout<<"kind >";
        std::cin>>kind;

        std::cout<<"age (full years) >";
        std::cin>>age;

        std::cout<<"weight >";
        std::cin>>weight;

        do {
            std::cout << "hunger percentage(0-100) >";
            std::cin >> hunger_p;
        } while (hunger_p>100);
        return new Animal(kind, age, weight, hunger_p);
    }
};


AnimalFactory<Animal> Animal::reg("animal");*/

#include "Beast.h"
#include "Bird.h"
#include "Snake.h"

#endif //ASTENENKO_ANIMAL_H
