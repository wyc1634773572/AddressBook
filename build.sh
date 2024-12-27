#!/bin/bash

g++ -fno-elide-constructors -g run.cpp src/addressbook.cpp src/menu.cpp -I include/ -o main