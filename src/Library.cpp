#include "Library.h"
#include <stdexcept>

void Library::addBook(const Book& book){
    std::string isbn = book.getIsbn();
    
    if(books.find(isbn) != books.end()){
        throw std::runtime_error("Book already exists");
    }
    //books[isbn] = book;
    books.emplace(book.getIsbn(), book);
}

Book& Library::getBook(const std::string& isbn){
    auto it = books.find(isbn);
    
    if(it == books.end()){
        throw std::runtime_error("Book not folunt");
    }
    return it->second;
}

bool Library::hasBook(const std::string& isbn) const {
    return books.find(isbn) != books.end();
}

void Library::addUser(const User& user){
    int id = user.getId();
    if(users.find(id) != users.end()){
        throw std::runtime_error("User already exists");
    }
    //users[id] = user;
    users.emplace(user.getId(), user);
}

User&Library::getUser(int id){
    auto it = users.find(id);
    if(it == users.end()){
        throw std::runtime_error("User not found");
    }

    return it->second;
}

bool Library::hasUser(int id) const{
    return users.find(id) != users.end();
}