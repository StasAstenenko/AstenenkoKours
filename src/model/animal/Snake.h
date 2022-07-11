

#ifndef ASTENENKO_SNAKE_H
#define ASTENENKO_SNAKE_H


#include <iostream>
#include "Animal.h"

struct SnakeRegister;

class Snake : public Animal{
public:
    Snake(const std::string &kind, std::string &name, int age, int weight, uint8_t hungerP, int length, int color)
    : Animal(kind, name, age, weight, hungerP), length(length), color(color) {}

    std::string info() const override {
        return  "length: "+ std::to_string(this->length) + ", color: " + std::to_string(this->color);;
    }
private:
    int length;
    int color;
    static SnakeRegister reg;
};



struct SnakeRegister : BaseAnimalFactory {
private:
    static Animal* create(){
        std::string kind;
        std::string name;
        int age;
        int weight;
        int hunger_p;
        int length;
        int color;

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

        std::cout<<"length >";
        std::cin>>length;

        std::cout<<"color >";
        std::cin>>color;

        return new Snake(kind,name ,  age, weight, hunger_p, length, color);
    }
public:
    explicit SnakeRegister(std::string const& s) {
        (*getMap())[s] = &SnakeRegister::create;
    }
};

SnakeRegister Snake::reg("snake");

#endif //ASTENENKO_SNAKE_H
