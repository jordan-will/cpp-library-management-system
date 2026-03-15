#ifndef STORAGE_H
#define STORAGE_H

#include <vector>

class Book;
class User;

class Storage{
public:
    virtual ~Storage();// = default;
    virtual void saveBooks(const std::vector<Book>& books) = 0;
    virtual std::vector<Book> loadBooks() = 0;

    virtual void saveUsers(const std::vector<User>& users) = 0;
    virtual std::vector<User> loadUsers() = 0;
};

#endif