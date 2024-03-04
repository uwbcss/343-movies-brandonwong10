#ifndef COMEDY_H
#define COMEDY_H

/**
 * Comedy class, Comedy is a Movie
 */

#include "movie.h"
#include <string>

class Comedy : public Movie {
private:
  int year;

public:
  // Constructor for comedy object
  Comedy(int stock, const string &director, const string &title, int year)
      : Movie('F', stock, director, title), year(year) {}

  // Displays comedy object
  void display() const override;

  // Customize sorting key for Comedy
  // Format: Title_Year
  string getSortingKey() const override;

  bool matches(const string &sortingAttributes) const override;
};

/**
 * Creating ComedyFactory to make Comedy objects
 * ComedyFactory object will register itself later and get stored in Movie class
 */
class ComedyFactory : public MovieFactory {
public:
  // Default Constructor for comedy factory
  ComedyFactory();
  // Makes comedy object
  Movie *makeMovie(int stock, const string &director, const string &title,
                   string data) const override;
};

#endif