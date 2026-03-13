#include <iostream>

#include "Library.h"
#include "LoanManager.h"
#include "Book.h"
#include "User.h"

#include <iostream>

#include "Library.h"
#include "LoanManager.h"
#include "Book.h"
#include "User.h"

int main(){
    try
    {
        Library library;

        Book cleanCode("Clean Code", "Robert Martin", "123", 2008);
        Book thePragmaticProgrammer
        (
            "The Pragmatic Programmer", "Andrew Hunt",
            "456", 19999
        );

        User alice(1, "Alice", "alice@email.com");
        User bob(2, "Bob", "bob@email.com");


        library.addBook(cleanCode);
        library.addBook(thePragmaticProgrammer);

        library.addUser(alice);
        library.addUser(bob);

        //Loan manager
        LoanManager loanManager(library);

        std::cout << "Borrowing book 123...\n";
        loanManager.borrowBook(1, "123");

        std::cout << "Returning book 123...\n";
        loanManager.returnBook("123");

        std::cout << "System excuted successsfully.\n";

    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: "<< e.what() << '\n';
    }
    
    return 0;
}