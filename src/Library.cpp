#include "Library.h"
#include "Storage.h"

#include <stdexcept>
#include <vector>

Library::Library(Storage& storage): storage(storage), nextUserId(1){}

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

void Library::load(){
    auto loadedBooks = storage.loadBooks();
    auto loadedUsers = storage.loadUsers();
    nextUserId = loadedUsers.size() + 1;

    for(const auto& book : loadedBooks){
        books.emplace(book.getIsbn(), book);
    }

    for(const auto& user: loadedUsers){
        users.emplace(user.getId(), user);
    }
}

void Library::save(){
    std::vector<Book> bookList;
    std::vector<User> userList;

    for(const auto& pair : books){
        bookList.push_back(pair.second);
    }

    for(const auto& pair : users){
        userList.push_back(pair.second);
    }

    storage.saveBooks(bookList);
    storage.saveUsers(userList);
}

const std::unordered_map<std::string, Book>& Library::getAllBooks() const{
    return books;
}

const std::unordered_map<int, User>& Library::getAllUsers() const {
    return users;
}

int Library::generateUserId(){
    return nextUserId++;
}