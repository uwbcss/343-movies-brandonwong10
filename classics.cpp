#include "classics.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// register a concrete factory with a given name
ClassicsFactory::ClassicsFactory() { registerType('C', this); }

// Creates Classic movie Object
Movie *ClassicsFactory::makeMovie(int stock, const string &director,
                                  const string &title, string data) const {
  istringstream iss(data);
  vector<string> tokens;
  string token;
  while (iss >> token) {
    tokens.push_back(token);
  }
  string majorActor = tokens[0] + " " + tokens[1];
  int releaseMonth = stoi(tokens[2]);
  int releaseYear = stoi(tokens[3]);
  return new Classics(stock, director, title, majorActor, releaseMonth,
                      releaseYear);
}

// Displays classic movie
void Classics::display() const {
  cout << releaseYear << " " << releaseMonth << ", " << majorActor << ", "
       << director << ", " << title << " (" << stock << ") "
       << "- " << type << endl;
}

// Customize sorting key for Classics
// Format: ReleaseYear_ReleaseMonth_MajorActor_Title
string Classics::getSortingKey() const {
  return to_string(releaseYear) + "_" + std::to_string(releaseMonth) + "_" +
         majorActor + "_" + title;
}

// Getter for year
int Classics::getYear() { return 0; }

// checks if  current object matches with given sorting attributes
bool Classics::matches(const string &sortingAttributes) const {
  string inputReleaseDate;
  string inputMajorActorFirstName;
  string inputMajorActorLastName;
  int inputReleaseMonth;
  int inputReleaseYear;
  istringstream iss(sortingAttributes);
  if (!(iss >> inputReleaseMonth >> inputReleaseYear >>
        inputMajorActorFirstName >> inputMajorActorLastName)) {
    return false;
  }
  string inputMajorActor =
      inputMajorActorFirstName + " " + inputMajorActorLastName;
  return (inputReleaseMonth == releaseMonth &&
          inputReleaseYear == releaseYear && inputMajorActor == majorActor);
}

// creating the object registers the type at run time
ClassicsFactory anonymousClassicsFactory;