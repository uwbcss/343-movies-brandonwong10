#include "customer.h"
#include <iostream>

using namespace std;

// Constructor
Customer::Customer(int customerID, string firstName, string lastName)
    : customerID(customerID), firstName(firstName), lastName(lastName) {}

// Getter for type
int Customer::customerIDGetter() const { return customerID; }

// Getter for firstName
string Customer::firstNameGetter() const { return firstName; }

// Getter for lastName
string Customer::lastNameGetter() const { return lastName; }
