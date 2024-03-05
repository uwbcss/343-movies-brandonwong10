#include "inventory.h"
#include "movie.h"
#include "store.h"
#include <iostream>

using namespace std;

// Constructor to register type 'I' with InventoryFactory
InventoryFactory::InventoryFactory() { registerType('I', this); }

// Method to create a new Inventory command
Command *InventoryFactory::makeCommand(int customerID, const char &mediaType,
                                       const char &movieType,
                                       string data) const {
  return new Inventory(customerID, mediaType, movieType, data);
}

// Method to execute the Inventory command
void Inventory::execute(Store &store) {
  store.getMovies().printInventory();
  delete this;
}

// Method to display information about an Inventory command
void Inventory::display() const { cout << "Type: " << type << endl; }

// Creating the object registers the type at runtime
InventoryFactory anonymousInventoryFactory;
