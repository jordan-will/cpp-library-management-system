#include "CSVStorage.h"
#include "Book.h"
#include "User.h"
#include "StringUtils.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

CSVStorage::CSVStorage(
    const std::string& booksFile,
    const std::string& usersFile
): booksFile(booksFile), usersFile(usersFile){}

void CSVStorage::saveBooks(const std::vector<Book>& books){
    std::ofstream file(booksFile);
    if(!file){
        throw std::runtime_error("Cannot open books file");
    }

    for(const auto& book: books){
        file << book.getTitle() << ","
        << book.getAuthor() << ","
        << book.getIsbn() << ","
        << book.getYear() << ","
        << book.isAvailable() 
        << "\n"; 
    }
}

std::vector<Book> CSVStorage::loadBooks(){

    std::vector<Book> books;

    std::ifstream file(booksFile);

    if(!file){
        throw std::runtime_error("Cannot open books file");
    }

    std::string line;

    while(std::getline(file, line)){

        if(line.empty()) {
            continue;
        }

        std::stringstream ss(line);

        std::string title;
        std::string author;
        std::string isbn;
        std::string yearStr;
        std::string availableStr;

        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, isbn, ',');
        std::getline(ss, yearStr, ',');
        std::getline(ss, availableStr);

        utils::trim(yearStr);
        utils::trim(availableStr);

        if(yearStr.empty() || availableStr.empty()){
            continue;
        }

        if(yearStr.empty() || availableStr.empty()){
            continue;
        }

        int year = std::stoi(yearStr);
        bool available = std::stoi(availableStr);

        Book book(title, author, isbn, year);

        if(!available){
            book.markAsBorrowed();
        }

        books.push_back(book);
    }

    return books;
}

void CSVStorage::saveUsers(const std::vector<User>& users){

    std::ofstream file(usersFile);

    if(!file){
        throw std::runtime_error("Cannot open users file");
    }

    for(const auto& user : users){

        file << user.getId() << ","
             << user.getName() << ","
             << user.getEmail()
             << "\n";
    }
}

std::vector<User> CSVStorage::loadUsers(){

    std::vector<User> users;

    std::ifstream file(usersFile);

    if(!file){
        throw std::runtime_error("Cannot open users file");
    }

    std::string line;

    while(std::getline(file, line)){

        if(line.empty()) {
            continue;
        }

        std::stringstream ss(line);

        std::string idStr;
        std::string name;
        std::string email;

        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, email);

        int id = std::stoi(idStr);

        users.emplace_back(id, name, email);
    }

    return users;
}