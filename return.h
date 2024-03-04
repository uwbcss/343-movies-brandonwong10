#ifndef RETURN_H
#define RETURN_H

/**
 * Return class, Return is a Command
 */

#include "command.h"
#include <string>

class Command;

class Return : public Command {
protected:
  int customerID;
  const char &mediaType;
  const char &movieType;
  string data;

public:
  // Constructor for the Return command.
  Return(int customerID, const char &mediaType, const char &movieType,
         string data)
      : Command('R'), customerID(customerID), mediaType(mediaType),
        movieType(movieType), data(data) {}

  // Executes the Return command.
  void execute(Store &store) override;

  // Displays the data associated with the Return command.
  void display() const override;
};

/**
 * Creating BorrowFactory to make Borrow objects
 * ComedyFactory object will register itself later and get stored in Movie class
 */
class ReturnFactory : public CommandFactory {
public:
  // Constructor for ReturnFactory. Registers the 'R' type with the factory.
  ReturnFactory();

  // Creates a new Return command object.
  Command *makeCommand(int customerID, const char &mediaType,
                       const char &movieType, string data) const override;
};

#endif