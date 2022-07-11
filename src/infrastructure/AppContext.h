

#ifndef ASTENENKO_APPCONTEXT_H
#define ASTENENKO_APPCONTEXT_H

#include "../controller/ZooParkController.h"
#include "../controller/AnimalsController.h"

class AppContext {
public:
    AppContext() = default;

    template<typename T>
    T get(){
        return TypeBase::get<T>();
    }

    bool isRunning() const {
        return this->work;
    }
    void run(){
        this->work = true;
    }

    void stop(){
        this->work = false;
    }

private:
    bool work = true;
};


#endif //ASTENENKO_APPCONTEXT_H
