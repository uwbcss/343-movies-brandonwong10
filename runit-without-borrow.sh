#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling without Borrow.cpp"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp store_test.cpp return.cpp classics.cpp comedy.cpp customer.cpp dramas.cpp Hashtable.cpp history.cpp inventory.cpp movie.cpp store.cpp command.cpp
./a.out
