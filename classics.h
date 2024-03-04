#ifndef CLASSIC_H
#define CLASSIC_H

/**
 * Classics class, Classic is a Movie
 */
#include "movie.h"
#include <string>

class Classics : public Movie {

private:
  string majorActor;
  int releaseMonth;
  int releaseYear;

public:
  // Constructor for classics
  Classics(int stock, const string &director, const string &title,
           const string &majorActor, int releaseMonth, int releaseYear)
      : Movie('C', stock, director, title), majorActor(majorActor),
        releaseMonth(releaseMonth), releaseYear(releaseYear) {}

  // Displays classics object
  void display() const override;

  // getter for year
  static int getYear();

  // checks if  current object matches with given sorting attributes
  bool matches(const string &sortingAttributes) const;

  // Customize sorting key for Classics
  // Format: ReleaseYear_ReleaseMonth_MajorActor_Title
  string getSortingKey() const override;
};

/**
 * Creating ComedyFactory to make Comedy objects
 * ComedyFactory object will register itself later and get stored in Movie class
 */
class ClassicsFactory : public MovieFactory {
public:
  // Constructor for factory
  ClassicsFactory();
  // Makes movie object
  Movie *makeMovie(int stock, const string &director, const string &title,
                   string data) const override;
};

#endif