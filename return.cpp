#include "return.h"
#include "movie.h"
#include "store.h"
#include <iostream>

using namespace std;

// Constructor for ReturnFactory. Registers the 'R' type with the factory.
ReturnFactory::ReturnFactory() { registerType('R', this); }

// Creates a new Return command object.
Command *ReturnFactory::makeCommand(int customerID, const char &mediaType,
                                    const char &movieType, string data) const {
  return new Return(customerID, mediaType, movieType, data);
}

// Executes the Return command.
void Return::execute(Store &store) {
  if (!store.customerExists(customerID)) {
    std::cout << "Error: Customer with ID " << customerID << " not found."
              << endl;
    return;
  }
  Movie *movie = store.getMovies().findMovie(movieType, data);
  if (movie == nullptr) {
    std::cout << "Error: Movie not found with type: " << movieType
              << " and Data: " << data << std::endl;
    return;
  }
  if (movie->getStock() <= 0) {
    cout << "Error: Movie " << movie->getTitle() << " is out of stock."
         << std::endl;
    return;
  }
  store.returnMovie(customerID, movie, this);
}

// Displays the data associated with the Return command.
void Return::display() const { cout << data << endl; }

// Creating the object registers the type at run time.
ReturnFactory anonymousReturnFactory;
