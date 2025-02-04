#!/bin/bash

## g++ -fno-elide-constructors -g run.cpp src/addressbook.cpp src/menu.cpp -I include/ -o main

cmake -S . -B build/
cmake --build build/