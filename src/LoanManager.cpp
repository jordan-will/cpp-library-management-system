#include "LoanManager.h"
#include "Library.h"

#include <stdexcept>

LoanManager::LoanManager(Library& library): library(library){}

void LoanManager::borrowBook(int userId, const std::string& isbn){
    
    if(!library.hasUser(userId)){
        throw std::runtime_error("User not found");
    }
    if(!library.hasBook(isbn)){
        throw std::runtime_error("Book not found");
    }

    Book& book = library.getBook(isbn);

    if(!book.isAvailable()){
        throw std::runtime_error("Book already borrow");
    }

    book.markAsBorrowed();
}

void LoanManager::returnBook(const std::string& isbn){
    
    if(!library.hasBook(isbn)){
        throw std::runtime_error("Book not found");
    }

    Book& book = library.getBook(isbn);

    if(book.isAvailable()){
        throw std::runtime_error("Book is not borrowed");
    }

    book.markAsReturned();
}