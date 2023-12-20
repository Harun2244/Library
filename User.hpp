#pragma once
#include "Book.hpp"
#include <iostream>
#include "../zadatak1/MojVektor.hpp"

class User{
  public:

User () = default; 
User(std::string, std::string, int);

const int& getId () const {
return id_;
}

MojVektor<Book> lended;


  private:
    std::string Name_;
    std::string LastName_;
    int id_;


};
