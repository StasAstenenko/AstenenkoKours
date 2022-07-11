

#ifndef ASTENENKO_ABSTRACTSTORAGECONTROLLER_H
#define ASTENENKO_ABSTRACTSTORAGECONTROLLER_H

#include <vector>
#include <iostream>
#include "IController.h"

template<typename DeriveType, typename Object>
class AbstractStorageController: public IController<DeriveType>{
private:
    std::vector<Object*> *storage;
public:

    AbstractStorageController(){
        this->storage = new std::vector<Object*>();
    }

    Object* get(int id){
        return storage->at(id);
    }

    void add(Object* o){
        storage->push_back(o);
    }

    Object* select(){
        return storage->at(selectId());
    }

    int selectId(){
        int id;
        std::cout<<"id >";
        std::cin>>id;
        return id;
    }

    std::vector<Object *> *getStorage() const {
        return storage;
    }
};


#endif //ASTENENKO_ABSTRACTSTORAGECONTROLLER_H
