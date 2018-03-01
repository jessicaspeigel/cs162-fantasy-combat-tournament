cmake_minimum_required(VERSION 3.9)
project(cs162_fantasy_combat_tournament)

set(CMAKE_CXX_STANDARD 11)

add_executable(cs162_fantasy_combat_tournament
        Barbarian.cpp
        Barbarian.hpp
        BlueMen.cpp
        BlueMen.hpp
        Character.cpp
        Character.hpp
        Die.cpp
        Die.hpp
        Game.cpp
        Game.hpp
        HarryPotter.cpp
        HarryPotter.hpp
        InputValidation.cpp
        InputValidation.hpp
        main.cpp
        Medusa.cpp
        Medusa.hpp
        Menu.cpp
        Menu.hpp
        Queue.cpp
        Queue.hpp
        Vampire.cpp
        Vampire.hpp QueueNode.cpp QueueNode.hpp)
