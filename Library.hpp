#pragma once
#include <iostream>
#include "Book.hpp"
#include "User.hpp"
#include "../zadatak1/MojVektor.hpp"


class Library {
  public:

    void AddNewBook();
    void AddNewUser();
    void BorrowBook();
    void ReturnBook();
    void BookSearchByTitle ();
    void BookSearchByAuthor ();
    void BookSearchByPublisher ();
    void BookSearchByPublicatonYear ();



  MojVektor<Book> Books;
  MojVektor<User> Users;

};
