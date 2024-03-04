#include "store.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// Constructor for the Store class.
Store::Store() {}

// Destructor for the Store class.
Store::~Store() {
  for (auto &pair : customers) {
    delete pair.second;
  }
  customers.clear();
  for (auto &pair : transactions) {
    for (auto *command : pair.second) {
      if (command == nullptr) {
        cout << "We got nullptr in command*\n";
      }
      cout << "Deleting: ";
      command->display();
      delete command;
    }
    pair.second.clear();
  }
  transactions.clear();
}

// Reads movie data from a file and populates the store's inventory.
void Store::readMoviesFromFile(string moviesFile) {
  ifstream fs(moviesFile);
  if (!fs.is_open()) {
    cerr << "Could not open file" << endl;
    return;
  }
  string str;
  while (getline(fs, str) && !str.empty()) {
    istringstream iss(str);
    char type;
    int stock;
    string director;
    string title;
    string data;
    string token;
    getline(iss, token, ',');
    type = token[0];
    getline(iss, token, ',');
    stock = stoi(token);
    getline(iss >> ws, director, ',');
    getline(iss >> ws, title, ',');
    getline(iss >> ws, data);
    Movie *movie = MovieFactory::create(type, stock, director, title, data);
    if (movie != nullptr) {
      movies.insertElement(movie);
    }
  }
}

// Reads customer data from a file and populates the store's customer
void Store::readCustomersFromFile(string customersFile) {
  ifstream file(customersFile);
  string line;
  int customerId;
  string firstName;
  string lastName;
  while (getline(file, line)) {
    istringstream iss(line);
    if (iss >> customerId >> firstName >> lastName) {
      Customer *newCustomer = new Customer(customerId, firstName, lastName);
      customers[customerId] = newCustomer;
    }
  }
}

// Reads command data from a file and executes the commands.
void Store::readCommandsFromFile(string commandsFile) {
  ifstream fs(commandsFile);
  if (!fs.is_open()) {
    cerr << "Could not open file" << endl;
    return;
  }
  string str;
  while (getline(fs, str) && !str.empty()) {
    istringstream iss(str);
    char type;
    int customerId = 0;
    char mediaType = '\0';
    char movieType = '\0';
    string data;
    if (!(iss >> type)) {
      cerr << "Invalid command: " << str << endl;
      continue;
    }
    if (type != 'I') {
      if (!(iss >> customerId)) {
        cerr << "Unknown command: " << str << endl;
        continue;
      }
    }
    if (type == 'B' || type == 'R') {
      if (!(iss >> mediaType >> movieType)) {
        cerr << "Missing media type or movie type in command: " << str << endl;
        continue;
      }
      if (mediaType != 'D') {
        cout << "Unknown mediaType " << mediaType << endl;
        continue;
      }
    }
    getline(iss >> ws, data);
    Command *command =
        CommandFactory::create(type, customerId, mediaType, movieType, data);
    if (command != nullptr) {
      command->execute(*this);
    }
  }
}

// Checks if a customer exists in the store's database.
bool Store::customerExists(int customerId) {
  return customers.count(customerId) != 0;
}

// Handles the borrowing of a movie by a customer.
void Store::borrowMovie(int customerID, Movie *movie, Command *command) {
  movies.borrowMovie(movie);
  transactions[customers[customerID]].push_back(command);
}

// Handles the return of a movie by a customer.
void Store::returnMovie(int customerID, Movie *movie, Command *command) {
  movies.returnMovie(movie);
  transactions[customers[customerID]].push_back(command);
}

// Returns a reference to the store's movie inventory.
HashTable &Store::getMovies() { return movies; }

// Returns a copy of the store's customer database.
unordered_map<int, Customer *> Store::getCustomer() { return customers; }

// Returns a copy of the store's transaction history.
unordered_map<Customer *, vector<Command *>> Store::getTransactions() {
  return transactions;
}
