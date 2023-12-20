#include "Library.hpp"

void Library::AddNewBook() {
  const std::string str(45, '-');
std::string title, author, publisher;
int pubyear, numofcopies;
std::cout << str << std::endl;
std::cout << "Title: ";
std::getline(std::cin >> std::ws, title);
std::cout<<"";
std::cout << "Author: "; 
std::getline(std::cin >> std::ws, author); 
std::cout << "";
std::cout << "Publisher: ";
std::getline(std::cin >> std::ws, publisher); 
std::cout << "";
std::cout << "Publication year: ";
std::cin >> pubyear;
std::cout << "Number of copies: ";
std::cin >> numofcopies;
  Book book(title, author, publisher, pubyear, numofcopies);
  Books.push_back(book);
  std::cout << "Book successfully added!" << std::endl;

}

void Library::AddNewUser() {
  std::string name, lname;
  int id;
  const std::string str(45, '-');
  std::cout << str << std::endl;
  std::cout << "Name: ";
  std::getline(std::cin >> std::ws, name);
  std::cout << "";
  std::cout << "Last name: ";
  std::getline(std::cin >> std::ws, lname);
  std::cout<<"";
  std::cout << "Id: ";
  std::cin >> id;
  MojVektor<User>::Iterator b = Users.begin();
  MojVektor<User>::Iterator e = Users.end();
while(b!=e){
if(b->getId() == id) {std::cout << "User with id {"<< id << "} already exists!" <<std::endl;
return;
}
++b;
}
  User user(name, lname, id);
  Users.push_back(user);
  std::cout << "User created successfully!" << std::endl;
}


void Library::BorrowBook(){
int id;
std::string title;
const std::string str(45, '-');
//U N O S
std::cout << "Id: ";
std::cin >> id;
std::cout << "Title: ";
std::getline(std::cin >> std::ws, title);


MojVektor<User>::Iterator itb = Users.begin();
MojVektor<User>::Iterator ite = Users.end();
//Da li postoji kornisnik
while(itb!=ite){
//Kornisk postoji  
if(itb->getId()==id){
MojVektor<Book>::Iterator iter1 = Books.begin();
MojVektor<Book>::Iterator iter2 = Books.end();
//Da li postoji knjiga s tim naslovom i da li ima dovoljan br. kopija
while(iter1!=iter2){
//Knjiga dostupna 
if(iter1->getTitle()==title && iter1->getNum() > 0){
MojVektor<Book>::Iterator it1 = (itb->lended).begin();
MojVektor<Book>::Iterator it2 = (itb->lended).end();
//IMa li kornisnik vec tu knjigu
 while(it1!=it2){
 if(it1->getTitle() == title && it1->getNum() >0){
   std::cout<<"You already have that book!";
   return;
 }
 ++it1; //sljedeca korisnikova knjiga
 }
(itb->lended).push_back(*iter1);
iter1->getNum()--;
it1->getNum() = it1->getNum() - it1->getNum() + 1;

std::cout << "Book successfully borrowed!" << std::endl;
return;
} //Kraj - Knjiga dostupna
++iter1; //slj. knjiga
}
std::cout << "Book not available!" << std::endl;
return;
}//Kraj - Korisnik postoji
++itb; //slj. kornisk
}
std::cout << "User does not exist!" << std::endl;
return;
}





void Library::ReturnBook(){
int id;
std::string title;
const std::string str(45, '-');
std::cout << str << std::endl;
std::cout << "Id:";
std::cin >> id;
std::cout << "Title: ";
std::getline(std::cin >> std::ws, title);


MojVektor<User>::Iterator itb = Users.begin();
MojVektor<User>::Iterator ite = Users.end();
while(itb!=ite){ //Da li postoji taj user

  if(itb->getId() == id){ //user postoji
  
MojVektor<Book>::Iterator ib = Books.begin();
MojVektor<Book>::Iterator ie = Books.end();

  while(ib!=ie){
  if(ib->getTitle() == title){//ako ta knjiga postoji u biblioteci
  
  MojVektor<Book>::Iterator i1 = (itb->lended).begin();
   MojVektor<Book>::Iterator i2 = (itb->lended).end();
while(i1!=i2){
  if(i1 ->getTitle() == title){

   while(i1 != i2){
   if(i1->getTitle() == title && i1->getNum() > 0){
   i1 -> getNum()--;
   ib -> getNum()++;
   std::cout << "Book successfully returned!" << std::endl;
   return;
   }

   else if(i1->getTitle()==title && i1->getNum() == 0){
   std::cout << "Book already returned!" << std::endl;
   return;
   }
   ++i1;
   }
  }
  ++i1;
}
std::cout << "Can not return a book you do not own!" << std::endl;
return;
  }

  ++ib;
  }
std::cout << "Book that you are trying to return is not in the database!" << std::endl;
return;
 }
++itb;
}
std::cout<<"User does not exist!"<<std::endl;
return;
}






void Library::BookSearchByTitle() {
  std::string title;
  const std::string str(45, '-');
  std::cout << str << std::endl;
  std::cout << "Title: " << std::endl;
  std::getline(std::cin >> std::ws, title);
  

  MojVektor<Book>::Iterator itb = Books.begin();
  MojVektor<Book>::Iterator ite = Books.end();
 
  while (itb != ite) {
    if (itb->getTitle() == title) {
      std::cout << str << std::endl;
      std::cout << "Title: " << itb->getTitle() << std::endl;
      std::cout << "Author: " << itb->getAuthor() << std::endl;
      std::cout << "Publisher: " << itb->getPublisher() << std::endl;
      std::cout << "Publication Year: " << itb->getPublicationoYear() << std::endl;
      std::cout << "Number of copies: " << itb->getNum() << std::endl;
    }
    ++itb;
    return;
  }
  std::cout << "Book not found!" << std::endl;
  return;
}

void Library::BookSearchByAuthor() {
  MojVektor<Book> PronadjeneKnjige;
  std::string author;
   const std::string str(45, '-');
   std::cout << str << std::endl;
  std::cout << "Author: " << std::endl;
    std::getline(std::cin >>std::ws , author);
    
    
  MojVektor<Book>::Iterator itb = Books.begin();
  MojVektor<Book>::Iterator ite = Books.end();
  
  while (itb != ite) {
    if (itb->getAuthor() == author) {
      PronadjeneKnjige.push_back(*itb);
    }
    ++itb;
  }

  if (PronadjeneKnjige.size() > 0) {
    MojVektor<Book>::Iterator prb = PronadjeneKnjige.begin();
    MojVektor<Book>::Iterator pre = PronadjeneKnjige.end();
    while (prb != pre) {
      std::cout << str << std::endl;
      std::cout << "Title: " << prb->getTitle() << std::endl;
      std::cout << "Author: " << prb->getAuthor() << std::endl;
      std::cout << "Publisher: " << prb->getPublisher() << std::endl;
      std::cout << "Publication Year: " << prb->getPublicationoYear() << std::endl;
      std::cout << "Number of copies: " << prb->getNum() << std::endl;
      ++prb;
    }
    return;
  } else {
    std::cout << "No Books found!" << std::endl;
    return;
  }
}

void Library::BookSearchByPublisher() {
  MojVektor<Book> PronadjeneKnjige;
  std::string publisher;
 const std::string str(45, '-');
 std::cout << str << std::endl;
  std::cout << "Publisher: " << std::endl;
    std::getline(std::cin >> std::ws, publisher);
    
  MojVektor<Book>::Iterator itb = Books.begin();
  MojVektor<Book>::Iterator ite = Books.end();
 
  while (itb != ite) {
    if (itb->getPublisher() == publisher) {
      PronadjeneKnjige.push_back(*itb);
    }
    ++itb;
  }

  if (PronadjeneKnjige.size() > 0) {
    MojVektor<Book>::Iterator prb = PronadjeneKnjige.begin();
    MojVektor<Book>::Iterator pre = PronadjeneKnjige.end();
    while (prb != pre) {
      std::cout << str << std::endl;
      std::cout << "Title: " << prb->getTitle() << std::endl;
      std::cout << "Author: " << prb->getAuthor() << std::endl;
      std::cout << "Publisher: " << prb->getPublisher() << std::endl;
      std::cout << "Publication Year: " << prb->getPublicationoYear() << std::endl;
      std::cout << "Number of copies: " << prb->getNum() << std::endl;
      ++prb;
    }
    return;
  } else {
    std::cout << "No Books found!" << std::endl;
    return;
  }}

  void Library::BookSearchByPublicatonYear() {
    MojVektor<Book> PronadjeneKnjige;
    int publicationyear;
 const std::string str(45, '-');
 std::cout << str << std::endl;
    std::cout << "Publication year: " << std::endl;
    std::cin >> publicationyear;
    MojVektor<Book>::Iterator itb = Books.begin();
    MojVektor<Book>::Iterator ite = Books.end();
 
    while (itb != ite) {
      if (itb->getPublicationoYear() == publicationyear) {
        PronadjeneKnjige.push_back(*itb);
      }
      ++itb;
    }

    if (PronadjeneKnjige.size() > 0) {
      MojVektor<Book>::Iterator prb = PronadjeneKnjige.begin();
      MojVektor<Book>::Iterator pre = PronadjeneKnjige.end();
      while (prb != pre) {
        std::cout << str << std::endl;
        std::cout << "Title: " << prb->getTitle() << std::endl;
        std::cout << "Author: " << prb->getAuthor() << std::endl;
        std::cout << "Publisher: " << prb->getPublisher() << std::endl;
        std::cout << "Publication Year: " << prb->getPublicationoYear() << std::endl;
        std::cout << "Number of copies: " << prb->getNum() << std::endl;
        ++prb;
      }
      return;
    } else {
      std::cout << "No Books found!"
                << std::endl;
      return;
    }
  }


