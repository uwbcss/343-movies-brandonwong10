#include "dramas.h"
#include <iostream>
#include <sstream>

using namespace std;

DramaFactory::DramaFactory() { registerType('D', this); }

Movie *DramaFactory::makeMovie(int stock, const string &director,
                               const string &title, string data) const {
  int year = stoi(data);
  return new Drama(stock, director, title, year);
}
// Displays drama properties
void Drama::display() const {
  cout << director << ", " << title << ", " << year << " (" << stock << ") "
       << "- " << type << endl;
}

// Customize sorting key for Drama
// Format: Director_Title
string Drama::getSortingKey() const { return getDirector() + "_" + getTitle(); }

// Checks if current object matches with sorting attributes
bool Drama::matches(const string &sortingAttributes) const {
  string inputDirector;
  string inputTitle;
  istringstream iss(sortingAttributes);
  if (!getline(iss, inputDirector, ',')) {
    return false;
  }
  if (!getline(iss >> ws, inputTitle)) {
    return false;
  }
  if (inputDirector != getDirector()) {
    return false;
  }
  inputTitle.pop_back();
  return inputTitle == getTitle();
}

// creating the object registers the type at run time
DramaFactory anonymousDramaFactory;