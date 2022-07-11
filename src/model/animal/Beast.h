

#ifndef ASTENENKO_BEAST_H
#define ASTENENKO_BEAST_H


#include <iostream>
#include "Animal.h"

struct BeastRegister;

class Beast : public Animal{
public:
    Beast(const std::string &kind,std::string &name, int age, int weight, uint8_t hungerP, int lactationPeriod) :
    Animal(kind, name, age, weight, hungerP), lactationPeriod(lactationPeriod) {}

    bool feed(Food& food) override {

        bool isLactation = (this->lactationPeriod/12) < this->getAge();
        bool isMilk = food.getFoodType() == FoodType::MILK;

        return (!isLactation || isMilk) && Animal::feed(food);
    }

    std::string info() const override;

private:
    int lactationPeriod;
    static BeastRegister reg;
};


struct BeastRegister : BaseAnimalFactory {
private:
    static Animal* create(){
        std::string kind;
        std::string name;
        int age;
        int weight;
        int hunger_p;
        int lactationPeriod;

        std::cout<<"kind >";
        std::cin>>kind;

        std::cout<<"name >";
        std::cin>>name;

        std::cout<<"age (full years) >";
        std::cin>>age;

        std::cout<<"weight >";
        std::cin>>weight;

        do {
            std::cout << "hunger percentage(0-100) >";
            std::cin >> hunger_p;
        } while (hunger_p>100);

        std::cout<<"lactation period (month) >";
        std::cin>>lactationPeriod;

        return new Beast(kind, name, age, weight, hunger_p, lactationPeriod);
    }
public:
    explicit BeastRegister(std::string const& s) {
        (*getMap())[s] = &BeastRegister::create;
    }
};

BeastRegister Beast::reg("beast");

std::string Beast::info() const {
    return "lactation period: " + std::to_string(this->lactationPeriod);
}

#endif //ASTENENKO_BEAST_H
