#include "history.h"
#include "movie.h"
#include "store.h"
#include <iostream>

using namespace std;

// Constructor to register type 'H' with HistoryFactory
HistoryFactory::HistoryFactory() { registerType('H', this); }

// Method to create a new History command
Command *HistoryFactory::makeCommand(int customerID, const char &mediaType,
                                     const char &movieType, string data) const {
  return new History(customerID, mediaType, movieType, data);
}

// Method to execute the History command
void History::execute(Store &store) {
  if (store.getCustomer().count(customerID) == 0) {
    cout << "Customer " << customerID << " does not exist" << endl;
    delete this;
    return;
  }
  Customer *customer = store.getCustomer()[customerID];
  cout << "History for " << customerID << " " << customer->firstNameGetter()
       << " " << customer->lastNameGetter() << endl;
  if (store.getTransactions().count(customer) == 0) {
    cout << "No history for " << customer->firstNameGetter() << " "
         << customer->lastNameGetter() << endl;
    delete this;
    return;
  }
  vector<Command *> transactions = store.getTransactions()[customer];
  for (Command *transaction : transactions) {
    cout << transaction->typeGetter() << " ";
    transaction->display();
  }
  delete this;
}

// Method to display information about a History command
void History::display() const {
  cout << "Type: " << type << endl;
  cout << "Customer ID: " << customerID << endl;
  cout << "Media Type: " << mediaType << endl;
  cout << "Movie Type: " << movieType << endl;
  cout << "Title: " << data << endl;
}

// Creating the object registers the type at runtime
HistoryFactory anonymousHistoryFactory;
