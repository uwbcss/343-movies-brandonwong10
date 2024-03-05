#include "command.h"
#include <iostream>

using namespace std;

/**
 * Storage place for the concrete Command factories
 * Having it available only through this function guarantees that
 * this static variable is initialized
 * when a concrete factory tires to register itself
 * @return map
 */
map<char, CommandFactory *> &CommandFactory::getMap() {
  static map<char, CommandFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void CommandFactory::registerType(const char &type, CommandFactory *factory) {
  getMap().emplace(type, factory);
}

// find the corresponding Command factory and get factory to create the object
Command *CommandFactory::create(const char &type, int customerID,
                                const char &mediaType, const char &movieType,
                                const string &data) {
  if (getMap().count(type) == 0) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->makeCommand(customerID, mediaType, movieType, data);
}

// Constructor
Command::Command(const char &type) : type(type) {}

// Getter for type
char Command::typeGetter() const { return type; }