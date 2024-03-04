#include <map>
#include <string>
#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;

class Customer;

class Customer {
protected:
  int customerID;
  string firstName;
  string lastName;

public:
  // Constructor
  Customer(int customerID, string firstName, string lastName);

  // Destructor
  ~Customer() {}

  // Getter for customerID
  int customerIDGetter() const;

  // Getter for firstName
  string firstNameGetter() const;

  // Getter for lastName
  string lastNameGetter() const;
};

#endif