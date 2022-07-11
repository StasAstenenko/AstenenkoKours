

#ifndef ASTENENKO_BIRD_H
#define ASTENENKO_BIRD_H


#include <iostream>
#include "Animal.h"

struct BirdRegister;

class Bird : public Animal{
public:
    Bird(const std::string &kind,std::string &name, int age, int weight, uint8_t hungerP, bool predator, int wingLength)
    : Animal(kind, name, age, weight, hungerP), predator(predator), wingLength(wingLength) {}

    std::string info() const override {
        return "predator: "+ std::to_string(this->predator) + ", wind length: " + std::to_string(this->wingLength);
    }

private:
    bool predator;
    int wingLength;
    static BirdRegister reg;
};



struct BirdRegister : BaseAnimalFactory {
private:
    static Animal* create(){
        std::string kind;
        std::string name;
        int age;
        int weight;
        int hunger_p;
        int wingLength;
        bool predator;

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

        std::cout<<"wing length >";
        std::cin>>wingLength;

        std::cout<<"predator >";
        std::cin>>predator;

        return new Bird(kind,name , age, weight, hunger_p, predator, wingLength);
    }
public:
    explicit BirdRegister(std::string const& s) {
        (*getMap())[s] = &BirdRegister::create;
    }
};

BirdRegister Bird::reg("bird");

#endif //ASTENENKO_BIRD_H
