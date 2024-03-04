#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
#include <string>

class Command;

// Inventory class, derived from Command
class Inventory : public Command {
protected:
  int customerID;
  const char &mediaType;
  const char &movieType;
  string data;

public:
  // Constructor
  Inventory(int customerID, const char &mediaType, const char &movieType,
            string data)
      : Command('I'), customerID(customerID), mediaType(mediaType),
        movieType(movieType), data(data) {}

  // Method to execute the Inventory command
  void execute(Store &store) override;

  // Method to display information about an Inventory command
  void display() const override;
};

// InventoryFactory class, derived from CommandFactory
class InventoryFactory : public CommandFactory {
public:
  // Constructor
  InventoryFactory();

  // Method to create a new Inventory command
  Command *makeCommand(int customerID, const char &mediaType,
                       const char &movieType, string data) const override;
};

#endif
