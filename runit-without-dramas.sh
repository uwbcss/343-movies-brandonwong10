#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling without Dramas.cpp"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp store_test.cpp borrow.cpp classics.cpp comedy.cpp customer.cpp return.cpp Hashtable.cpp history.cpp inventory.cpp movie.cpp store.cpp command.cpp
./a.out
