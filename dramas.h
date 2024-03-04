#ifndef DRAMA_H
#define DRAMA_H

/**
 * Dramas class, Drama is a Movie
 */

#include "movie.h"
#include <string>

class Drama : public Movie {

private:
  int year;

public:
  // Constructor for Drama
  Drama(int stock, const string &director, const string &title, int year)
      : Movie('D', stock, director, title), year(year) {}

  // Displays drama properties
  void display() const override;

  // Customize sorting key for Drama
  // Format: Director_Title
  string getSortingKey() const override;

  // Checks if current object matches with sorting attributes
  bool matches(const string &sortingAttributes) const override;
};

/**
 * Creating DramaFactory to make Drama objects
 * DramaFactory object will register itself later and get stored in Movie class
 */
class DramaFactory : public MovieFactory {
public:
  // Constructor for drama factory
  DramaFactory();
  // Makes drama object
  Movie *makeMovie(int stock, const string &director, const string &title,
                   string data) const override;
};

#endif