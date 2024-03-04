#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie;

class MovieFactory {
public:
  // Makes movie object
  virtual Movie *makeMovie(int stock, const string &director,
                           const string &title, string data) const = 0;

  // find the corresponding Movie factory and get factory to create the object
  static Movie *create(const char &type, int stock, const string &director,
                       const string &title, const string &data);

protected:
  // register a concrete factory with a given name
  static void registerType(const char &type, MovieFactory *factory);

private:
  // Getter for map
  static map<char, MovieFactory *> &getMap();
};

/**
 * The abstract class at the top of the hierarchy
 * All Pets are derived from this class
 * Stores pet factories and creates Pet objects through static functions
 **/
class Movie {
protected:
  char type;
  int stock;
  string director;
  string title;
  string data;

public:
  // Constructor
  Movie(const char &type, int stock, const string &director,
        const string &title);

  // Destructor
  virtual ~Movie() {}

  // Getter for type
  char getType() const;

  // Getter for stock
  int getStock() const;

  // Getter for director
  string getDirector() const;

  // Getter for title
  string getTitle() const;

  // Getter for data
  string getData() const;

  // Decreases stock by one
  void decreaseStock();

  // Increase stock by one
  void increaseStock();

  // Gets the sorting key
  virtual string getSortingKey() const = 0;

  // Method to check if the movie matches the given sorting attributes
  virtual bool matches(const string &sortingAttributes) const = 0;

  // different Movies will display different properties, all subclasses must
  // implement say
  virtual void display() const = 0;
};

#endif // MOVIE_H