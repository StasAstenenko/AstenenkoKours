#include <iostream>
#include "src/infrastructure/AppContext.h"
#include "src/infrastructure/cli/CommandManager.h"
#include "src/infrastructure/cli/command/ExitCommand.h"
#include "src/infrastructure/cli/command/SubManagerCommand.h"

int main() {
    auto* context = new AppContext();
    CommandManager manager;

    manager.addCommand(new SubManagerCommand<ZooParkController>());
    manager.addCommand(new SubManagerCommand<AnimalsController>());
    manager.addCommand(new ExitCommand());

    std::string input;
    while (context->isRunning()){
        std::cout<<manager;
        std::cin>>input;
        try {
            manager.handle(context, input);
        }catch (std::runtime_error const& error){
            std::cout<<error.what()<<"\n";
        }
    }

    return 0;
}
