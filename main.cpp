#include "Library.hpp"
#include "Book.hpp"
#include "User.hpp"


void frontscreen (){
  const std::string line (45 , '=');
  const std::string lline(45 , '-');
  std::cout << line << std::endl;
  std::cout<<""<<std::endl;
std::cout << "University of Tuzla" << std::endl;
std::cout << "Faculty of Electrical Engineering" << std::endl;
std::cout << "" << std::endl;
std::cout << "Library application" << std::endl;
std::cout << "Version April 2023." << std::endl;
std::cout <<""<< std::endl;
std::cout << line;
std::cout << "" << std::endl;
std::cout << lline <<std::endl;
std::cout << "List of commands: " <<std::endl;
std::cout << line << std::endl;
std::cout << "CreateUser" << std::endl;
std::cout << "BookAdd" << std::endl;
std::cout << "BookBorrow" << std::endl;
std::cout << "BookReturn" << std::endl;
std::cout << "BookSearchByTitle" << std::endl;
std::cout << "BookSearchByAuthor" << std::endl;
std::cout << "BookSearchByPublisher" << std::endl;
std::cout << "BookSearchByPublicationYear" << std::endl;
std::cout << "Help" << std::endl;
std::cout << "Exit" << std::endl;
std::cout << lline << std::endl;
}

std::string unos() {
const std::string tacke (45, '.');
std::cout << tacke << std::endl;
std::string unos;
std::cout << "Enter command: ";
std::cin>>unos;
return unos;
}


void fs (){
  
 Library lib;
   std::string uneseno;
  frontscreen();
while(1){
 uneseno = unos();
if(uneseno == "CreateUser"){lib.AddNewUser();}
else if(uneseno == "BookAdd"){lib.AddNewBook();}
else if(uneseno == "BookBorrow"){lib.BorrowBook();}
else if(uneseno == "BookReturn"){lib.ReturnBook();}
else if(uneseno == "BookSearchByTitle"){lib.BookSearchByTitle();}
else if(uneseno == "BookSearchByAuthor"){lib.BookSearchByAuthor();}
else if(uneseno == "BookSearchByPublisher"){lib.BookSearchByPublisher();}
else if (uneseno == "BookSearchByPublicationYear"){lib.BookSearchByPublicatonYear();}
else if(uneseno == "Help"){frontscreen();}
else if (uneseno == "Exit"){break;}
else {std::cout<<"Invalid command, please try again:"<<std::endl;}
}
}



int main(void)
{
fs();
  return 0;
}













