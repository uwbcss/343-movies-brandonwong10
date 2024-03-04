#ifndef BORROW_H
#define BORROW_H

/**
 * Borrow class, Borrow is a Command
 */

#include "command.h"
#include <string>

class Command;

class Borrow : public Command {
protected:
  int customerID;
  const char &mediaType;
  const char &movieType;
  string data;

public:
  // Constructor For Borrow
  Borrow(int customerID, const char &mediaType, const char &movieType,
         string data)
      : Command('B'), customerID(customerID), mediaType(mediaType),
        movieType(movieType), data(data) {}

  // Executes the borrow
  void execute(Store &store) override;

  // Displays Data
  void display() const override;
};

/**
 * Creating BorrowFactory to make Borrow objects
 * ComedyFactory object will register itself later and get stored in Movie class
 */
class BorrowFactory : public CommandFactory {
public:
  // Constructor For Borrow Factory
  BorrowFactory();
  // Uses factory to make object
  Command *makeCommand(int customerID, const char &mediaType,
                       const char &movieType, string data) const override;
};

#endif