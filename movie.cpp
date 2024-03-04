#include "movie.h"
#include <iostream>

using namespace std;

/**
 * Storage place for the concrete pet factories
 * Having it available only through this function guarantees that
 * this static variable is initialized
 * when a concrete factory tires to register itself
 * @return map
 */
map<char, MovieFactory *> &MovieFactory::getMap() {
  static map<char, MovieFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void MovieFactory::registerType(const char &type, MovieFactory *factory) {
  getMap().emplace(type, factory);
}

// find the corresponding Movie factory and get factory to create the object
Movie *MovieFactory::create(const char &type, int stock, const string &director,
                            const string &title, const string &data) {
  if (getMap().count(type) == 0) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->makeMovie(stock, director, title, data);
}

// Constructor
Movie::Movie(const char &type, int stock, const string &director,
             const string &title)
    : type(type), stock(stock), director(director), title(title) {}

void Movie::decreaseStock() {
  if (stock > 0) {
    --stock;
  }
}

void Movie::increaseStock() {
  if (stock > 0) {
    ++stock;
  }
}

// Getter for type
char Movie::getType() const { return type; }

// Getter for stock
int Movie::getStock() const { return stock; }

// Getter for director
string Movie::getDirector() const { return director; }

// Getter for title
string Movie::getTitle() const { return title; }

// Getter for data
string Movie::getData() const { return data; }
