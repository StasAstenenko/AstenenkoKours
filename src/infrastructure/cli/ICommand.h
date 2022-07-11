

#ifndef ASTENENKO_ICOMMAND_H
#define ASTENENKO_ICOMMAND_H


#include <string>
#include <vector>
#include "../AppContext.h"

class ICommand {
public:
    virtual void handle(AppContext* context, std::vector<std::string> args) = 0;
    virtual std::string getName() = 0;
    virtual std::string getAliases(){return "";};
};


#endif //ASTENENKO_ICOMMAND_H
