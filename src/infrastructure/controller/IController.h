

#ifndef ASTENENKO_ICONTROLLER_H
#define ASTENENKO_ICONTROLLER_H
#include <map>

#define Init(Typename) \
    template<> \
    Typename IController<Typename>::instance = Typename();

struct TypeBase{
    static std::map<std::string, void*> m_container;
    template<typename T>
    static T* get(){
        return (T*)m_container[typeid(T).name()];
    }
};

std::map<std::string, void*> TypeBase::m_container;


template<typename DeriveType>
class IController {

public:
    static inline DeriveType instance;
    constexpr IController(){
        TypeBase::m_container[typeid(DeriveType).name()] = &instance;
        //this->obj.print();
    }


    virtual void print() = 0;
    virtual std::string name() = 0;
    virtual void create() = 0;
    virtual void addAnimal(Animal* pAnimal){}
    virtual void moveAnimal(const std::string& zooFrom, const std::string& zooTo, const std::string& animalName){}
    virtual Animal* popAnimal(const std::string& name){}
    virtual void remove() = 0;

};

#endif //ASTENENKO_ICONTROLLER_H
