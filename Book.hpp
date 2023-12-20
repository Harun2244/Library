#pragma once
#include <iostream>
#include "../zadatak1/MojVektor.hpp"

class Book {
  public:

    Book() = default;
Book(std::string, std::string, std::string, int, int);

 const std::string& getTitle  () const {
return Title_;
}

const int& getNum () const{
return numOfCopies_;
}

int& getNum (){
return numOfCopies_;
}

const std::string getAuthor () const{
return Author_;
}

const std::string getPublisher() const{
return Publisher_;
}

int getPublicationoYear() {
return PublicationYear_;
}



  private:
    std::string Title_;
    std::string Author_;
    std::string Publisher_;
    int PublicationYear_;
    int numOfCopies_;
};
