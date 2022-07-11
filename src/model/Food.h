

#ifndef ASTENENKO_FOOD_H
#define ASTENENKO_FOOD_H


#include "FoodType.h"

class Food {
    int amount;
    FoodType foodType;
public:
    Food(int amount, FoodType type): amount(amount), foodType(type){}
    int getAmount() const{
        return amount;
    }

    void setAmount(int amount){
        this->amount = amount;
    }

    FoodType getFoodType() const {
        return foodType;
    }


};


#endif //ASTENENKO_FOOD_H
