#include "HashTable.h"
#include <iostream>
#include <list>
using namespace std;

// Retrieves index of movie
int HashTable::getHash(Movie *movie) const {
  return static_cast<int>(movie->getType()) % totalElements;
}

// Constructor for hashtable
HashTable::HashTable() { table = new list<Movie *>[totalElements]; }

// Destructor for hashTable
HashTable::~HashTable() {
  // Iterate over each slot in the table
  for (int i = 0; i < totalElements; ++i) {
    // Check if the linked list exists at this slot
    if (!table[i].empty()) {
      // Iterate over the linked list and delete all movies in it
      for (auto it = table[i].begin(); it != table[i].end(); ++it) {
        delete *it;
      }
    }
  }
  delete[] table;
}

// Insert data in the hash table:
void HashTable::insertElement(Movie *movie) {
  int index = getHash(movie);
  table[index].push_back(movie);
  table[index].sort([](Movie *a, Movie *b) {
    return a->getSortingKey() < b->getSortingKey();
  });
}

// Find a movie in the hash table:
Movie *HashTable::findMovie(char movieType, string sortingAttrib) {
  int index = static_cast<int>(movieType) % totalElements;
  for (Movie *m : table[index]) {
    if (m->matches(sortingAttrib)) {
      return m;
    }
  }
  return nullptr;
}

// Remove data from the hash table:
void HashTable::removeElement(Movie *movie) {
  int x = getHash(movie);
  list<Movie *>::iterator i;
  for (i = table[x].begin(); i != table[x].end(); i++) {
    if (*i == movie) {
      break;
    }
  }
  if (i != table[x].end()) {
    table[x].erase(i);
  }
}

// Siimulates borrow action
void HashTable::borrowMovie(Movie *movie) {
  for (int i = 0; i < totalElements; ++i) {
    for (Movie *m : table[i]) {
      if (movie->getType() == m->getType() &&
          movie->getSortingKey() == m->getSortingKey()) {
        m->decreaseStock();
        return;
      }
    }
  }
  cout << "Could not borrow: Movie not found in the inventory!" << endl;
}

// Simulates return action
void HashTable::returnMovie(Movie *movie) {
  for (int i = 0; i < totalElements; ++i) {
    for (Movie *m : table[i]) {
      if (movie->getType() == m->getType() &&
          movie->getSortingKey() == m->getSortingKey()) {
        m->increaseStock();
        return;
      }
    }
  }
  cout << "Could not return: Movie not found in the inventory!" << endl;
}

// Print all elements in the hash table:
void HashTable::printAll() {
  for (int i = 0; i < totalElements; ++i) {
    if (!table[i].empty()) {
      cout << "Bucket " << i << ": " << endl;
      for (Movie *movie : table[i]) {
        // Print details of each movie
        movie->display();
        cout << endl;
      }
      cout << endl;
    }
  }
}

// Prints entire inventory
void HashTable::printInventory() {
  for (int i = totalElements - 1; i >= 0; --i) {
    if (!table[i].empty()) {
      for (Movie *movie : table[i]) {
        movie->display();
        cout << endl;
      }
      cout << endl;
    }
  }
}
