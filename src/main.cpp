#include <iostream>

#include "Library.h"
#include "LoanManager.h"
#include "CSVStorage.h"
#include "Book.h"
#include "User.h"


int main(){

    try{

        // storage
        CSVStorage storage("../data/books.csv", "../data/users.csv");

        // library
        Library library(storage);

        // load previous data
        library.load();

        // create books
        Book cleanCode("Clean Code", "Robert Martin", "124", 2008);
        Book pragmatic("The Pragmatic Programmer", "Andrew Hunt", "456", 1999);

        // create users
        User alice(1, "Alice", "alice@email.com");
        User bob(2, "Bob", "bob@email.com");

        // register data
        library.addBook(cleanCode);
        library.addBook(pragmatic);

        library.addUser(alice);
        library.addUser(bob);

        // loan manager
        LoanManager loanManager(library);

        std::cout << "Borrowing book 124...\n";
        loanManager.borrowBook(1, "124");

        std::cout << "Returning book 124...\n";
        loanManager.returnBook("124");

        // save data
        library.save();

        std::cout << "System executed successfully\n";
    }
    catch(const std::exception& e){

        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}