cmake_minimum_required(VERSION 3.0)
project(Astenenko)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/model/include)

add_executable(Astenenko main.cpp
        src/model/animal/Animal.h
        src/model/Food.h
        src/model/include/ZooPark.h
        src/infrastructure/cli/CommandManager.h
        src/infrastructure/cli/ICommand.h
        src/infrastructure/controller/IController.h
        src/infrastructure/AppContext.h
        src/controller/AnimalsController.h
        src/infrastructure/cli/command/ExitCommand.h
        src/model/animal/Beast.h
        src/model/animal/Snake.h
        src/model/animal/Bird.h
        src/infrastructure/cli/command/PrintCommand.h
        src/infrastructure/cli/command/SubManagerCommand.h
        src/infrastructure/cli/command/CreateCommand.h
        src/infrastructure/cli/command/DeleteCommand.h
        src/commands/zoo/TestCommand.h
        src/infrastructure/controller/AbstractStorageController.h
        src/model/FoodType.h src/infrastructure/cli/command/ImportCommand.h src/infrastructure/cli/command/MoveCommand.h)
