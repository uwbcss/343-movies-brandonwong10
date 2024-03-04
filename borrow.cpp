#include "borrow.h"
#include "movie.h"
#include "store.h"
#include <iostream>

using namespace std;

// register a concrete factory with a given name
BorrowFactory::BorrowFactory() { registerType('B', this); }

// Creates Burrow Object
Command *BorrowFactory::makeCommand(int customerID, const char &mediaType,
                                    const char &movieType, string data) const {
  return new Borrow(customerID, mediaType, movieType, data);
}

// Executes borrow movie action
void Borrow::execute(Store &store) {
  if (!store.customerExists(customerID)) {
    std::cout << "Error: Customer with ID " << customerID << " not found."
              << std::endl;
    return;
  }
  Customer *customer = store.getCustomer()[customerID];
  // Check if the movie exists
  Movie *movie = store.getMovies().findMovie(movieType, data);
  if (movie == nullptr) {
    std::cout << "Error: Movie not found with type: " << movieType
              << " and Data: " << data << endl;
    return;
  }
  if (movie->getStock() <= 0) {
    cout << customer->firstNameGetter() << " " << customer->lastNameGetter()
         << "could NOT borrow " << movie->getTitle() << ", out of stock."
         << endl;
    return;
  }
  store.borrowMovie(customerID, movie, this);
}

// Displays data
void Borrow::display() const { cout << data << endl; }

// creating the object registers the type at run time
BorrowFactory anonymousBorrowFactory;