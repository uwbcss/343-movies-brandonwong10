#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Store;

class Command;

class CommandFactory {
public:
  // Makes Command objects
  virtual Command *makeCommand(int customerID, const char &mediaType,
                               const char &movieType, string data) const = 0;

  // find the corresponding Command factory and get factory to create the object
  static Command *create(const char &type, int customerID,
                         const char &mediaType, const char &movieType,
                         const string &data);

protected:
  // register a concrete factory with a given name
  static void registerType(const char &type, CommandFactory *factory);

private:
  // Getter for map
  static map<char, CommandFactory *> &getMap();
};

/**
 * The abstract class at the top of the hierarchy
 * All Commands are derived from this class
 * Stores command factories and creates Command objects through static functions
 **/
class Command {
protected:
  char type;

public:
  // Constructor
  explicit Command(const char &type);

  // Destructor
  virtual ~Command() {}

  // Getter for type
  char typeGetter() const;

  // different Commands will display different properties, all subclasses must
  // implement display
  virtual void display() const = 0;

  // Executes action
  virtual void execute(Store &store) = 0;
};

#endif