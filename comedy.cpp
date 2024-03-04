#include "comedy.h"
#include <iostream>
#include <sstream>

using namespace std;

// register a concrete factory with a given name
ComedyFactory::ComedyFactory() { registerType('F', this); }

// Makes comedy object
Movie *ComedyFactory::makeMovie(int stock, const string &director,
                                const string &title, string data) const {
  int year = stoi(data);
  return new Comedy(stock, director, title, year);
}

// Displays comedy object
void Comedy::display() const {
  cout << title << ", " << year << ", " << director << " (" << stock << ") "
       << "- " << type << endl;
}

// Customize sorting key for Comedy
// Format: Title_Year
string Comedy::getSortingKey() const {
  return getTitle() + "_" + std::to_string(year);
}

// checks if current object matches with given sorting attributes
bool Comedy::matches(const string &sortingAttributes) const {
  string inputTitle;
  int inputYear;
  istringstream iss(sortingAttributes);
  if (!getline(iss, inputTitle, ',')) {
    cout << inputTitle << endl;
    return false;
  }
  if (!(iss >> inputYear)) {
    return false;
  }
  if (inputTitle != getTitle()) {
    return false;
  }
  return inputYear == year;
}

// creating the object registers the type at run time
ComedyFactory anonymousComedyFactory;