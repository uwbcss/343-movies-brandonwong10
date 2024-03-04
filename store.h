#include "HashTable.h"
#include "command.h"
#include "customer.h"
#include <string>
#include <unordered_map>
#ifndef STORE_H
#define STORE_H

using namespace std;

class Store {
protected:
  HashTable movies;
  unordered_map<int, Customer *> customers;
  unordered_map<Customer *, vector<Command *>> transactions;

public:
  // Constructor for the Store class.
  Store();

  // Destructor for the Store class.
  ~Store();

  // Prints the contents of the internal map.
  void printMap();

  // Reads movie data from a file and populates the store's inventory.
  void readMoviesFromFile(string moviesFile);

  // Reads customer data from a file and populates the store's customer
  // database.
  void readCustomersFromFile(string customersFile);

  // Reads command data from a file and executes the commands.
  void readCommandsFromFile(string commandsFile);

  // Checks if a customer exists in the store's database.
  bool customerExists(int customerId);

  // Handles the borrowing of a movie by a customer.
  void borrowMovie(int customerID, Movie *movie, Command *command);

  // Handles the return of a movie by a customer.
  void returnMovie(int customerID, Movie *movie, Command *command);

  // Returns a reference to the store's movie inventory.
  HashTable &getMovies();

  // Returns a copy of the store's customer database.
  unordered_map<int, Customer *> getCustomer();

  // Returns a copy of the store's transaction history.
  unordered_map<Customer *, vector<Command *>> getTransactions();
};

#endif