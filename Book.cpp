#include "Book.hpp"
#include <iostream>
#include "../zadatak1/MojVektor.hpp"

Book::Book(std::string title, std::string author, std::string publisher,
           int publicationyear, int numcopies)
    : Title_{title},
      Author_{author},
      Publisher_{publisher},
      PublicationYear_{publicationyear},
      numOfCopies_{numcopies} {}


