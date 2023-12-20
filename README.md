 A program for tracking borrowed books in a library using std::vector container.

The program has the following functionalities:

    New book entry - allows inputting data about a new book (title, author, publisher, year of publication, number of copies).

    Borrowing a book - allows borrowing a book to a user (inputting user data, the number of copies being borrowed).

    Returning a book - allows returning a borrowed book to the library (reduces the number of borrowed copies by the number of returned copies).

    Book search - allows searching for books by title, author, publisher, or year of publication. The program stores data about books and users in std::vector containers.
    Each book is represented by an object of the Book class, which has the following members:

    Title (string)

    Author (string)

    Publisher (string)

    Year of publication (int)

    Number of copies (int)
    Each user is represented by an object of the User class, which has the following members:

    First name (string)

    Last name (string)

    User ID (int)
    Methods are implemented for adding, borrowing, returning, and searching for books in the Library class. A user can borrow only one copy of a specific book. At any given time, a user can borrow only one copy of a particular book.
