#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>
#include <string>

#include "Book.h"
#include "User.h"

class Library{
private:
    std::unordered_map<std::string, Book> books;
    std::unordered_map<int, User> users;
public:
    //book operations
    void addBook(const Book& book);
    Book& getBook(const std::string& isbn);//uma função por referencia?
    bool hasBook(const std::string& isbn) const;

    //user operatin
    void addUser(const User& user);
    User& getUser(int id);
    bool hasUser(int id) const;
};

#endif