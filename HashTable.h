#include "movie.h"
#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
  list<Movie *> *table;
  int totalElements = 75;

  // Getter for index
  int getHash(Movie *movie) const;

public:
  // Default Constructor
  HashTable();

  // Destructor
  ~HashTable();

  // Insert data in the hash table:
  void insertElement(Movie *movie);

  // Remove data from the hash table:
  void removeElement(Movie *movie);

  // Simulates borrowing movie
  void borrowMovie(Movie *movie);

  // Simulates returning movie
  void returnMovie(Movie *movie);

  // Located movie object
  Movie *findMovie(char movieType, string sortingAttrib);

  // Prints hastable for map
  void printAll();

  // Prints entire inventory
  void printInventory();
};