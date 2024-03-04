#ifndef HISTORY_H
#define HISTORY_H

/**
 * History class, History is a Command
 */

#include "command.h"
#include <string>

class Command;

class History : public Command {
protected:
  int customerID;
  const char &mediaType;
  const char &movieType;
  string data;

public:
  // Constructor for histroy object
  History(int customerID, const char &mediaType, const char &movieType,
          string data)
      : Command('B'), customerID(customerID), mediaType(mediaType),
        movieType(movieType), data(data) {}

  // Prints customers transaction history
  void execute(Store &store) override;

  // Displays history data
  void display() const override;
};

/**
 * Creating BorrowFactory to make Borrow objects
 * ComedyFactory object will register itself later and get stored in Movie class
 */
class HistoryFactory : public CommandFactory {
public:
  // Constructor for history factory
  HistoryFactory();

  // Makes commands
  Command *makeCommand(int customerID, const char &mediaType,
                       const char &movieType, string data) const override;
};

#endif