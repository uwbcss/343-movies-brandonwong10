# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: Yes

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0 after 5 long hours

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: Yes

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): Yes

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: 
File: Command.cpp Function: Command *CommandFactory::create(const char &type, int customerID,
                                const char &mediaType, const char &movieType,
                                const string &data)

invalid movie type: 
File: Movie.cpp Function: Movie *MovieFactory::create(const char &type, int stock, const string &director,
                            const string &title, const string &data)
File: borrow.cpp Function: void Borrow::execute(Store &store)
File: return.cpp Function: void Return::execute(Store &store)

invalid customer ID:
File: borrow.cpp Function: void Borrow::execute(Store &store)
File: return.cpp Function: void Return::execute(Store &store)
File: history.cpp Function: void History::execute(Store &store)
 
invalid movie:
File: borrow.cpp Function: void Borrow::execute(Store &store)
File: return.cpp Function: void Return::execute(Store &store)

factory classes:
All classes have their own factory, except for customer as their is only one customer class.

hashtable: The hastable is used for the movie class. It can add, remove, and located movies in o(1) time

container used for comedy movies:
File: HashTable.cpp Function: list<Movie *> *table;

function for sorting comedy movies:
File: hashtable.cpp Function: void HashTable::insertElement(Movie *movie); (Uses a sorting key system, each class has their own sorting key)

function where comedy movies are sorted: 
File: hashtable.cpp Function: void HashTable::insertElement(Movie *movie);

functions called when retrieving a comedy movie based on title and year:
File: HashTable.cpp Function: Movie *HashTable::findMovie(char movieType, string sortingAttrib), 

functions called for retrieving and printing customer history:
File: History.cpp Function: void History::execute(Store &store)

container used for customer history: TODO(student)
File: store.cpp Container: unordered_map<Customer *, vector<Command *>> transactions;

functions called when borrowing a movie:
File: borrow.cpp Function: void Borrow::execute(Store &store)
File: store.cpp Function: void Store::borrowMovie(int customerID, Movie *movie, Command *command)
File: HashTable.cpp Function: void borrowMovie(Movie *movie)

explain borrowing a movie that does not exist:
After the borrowMovie function searches the inventory for the movie that wants to be borrowed, if unsuccessful. It will return a statement that says movie cannot be found

explain borrowing a movie that has 0 stock:
After someone borrows a movie, the stock of that movie goes down. And everytime someone wants to borrow a movie, it goes through an if statement to make sure that specific movie is still in stock. If that movie is not in stock it will return movie out of stock.

explain returning a movie that customer has not checked out: In the return movie, the function looks through the customers transaction history to find a borrowed movie that matches with the movie that wants to be returned. Or else the customer is informed that the he/she has not borrowed the movie

any static_cast or dynamic_cast used:
Borrow *borrowCommand = dynamic_cast<Borrow *>(cmd);


## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? Yes




Q: Total points: 25