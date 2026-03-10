#include "Book.h"
#include <stdexcept>

Book::Book(): year(0), available(true){}
Book::Book(
    const std::string& title,
    const std::string& author,
    const std::string& isbn,
    int year
): title(title),
    author(author),
    isbn(isbn),
    year(year),
    available(true)
{
    validate(title, author, isbn, year);
}

//getters
const std::string& Book::getTitle() const{
    return title;
}

const std::string& Book::getAuthor() const{
    return author;
}

const std::string& Book::getIsbn() const {
    return isbn;
}

int Book::getYear() const {
    return year;
}

bool Book::isAvailable() const {
    return available;
}

//setters
void Book::setTitle(const std::string& title){
    if(title.empty()){
        throw std::runtime_error("Title cannot be empty");
    }
    this->title = title;
}

void Book::setAuthor(const std::string& author){
    if(author.empty()){
        throw std::runtime_error("Author cannot be empty");
    }
    this->author = author;
}

void Book::setYear(int year){
    if(year <= 0){
        throw std::runtime_error("Invalid year");
    }
    this->year = year;
}

//Load control
void Book::markAsBorrowed(){
    if(!isAvailable()){
        throw std::runtime_error("Book is already borrowed");
    }
    available = false;
}

void Book::markAsReturned(){
    available = true;
}

void Book::validate(
    const std::string& title,
    const std::string& author,
    const std::string& isbn,
    int year
){
    if(title.empty()){
        throw std::runtime_error("Title cannot be empty");
    }
    if(author.empty()){
        throw std::runtime_error("Author cannot be empty");
    }
    if(isbn.empty()){
        throw std::runtime_error("ISBN cannot be empty");
    }
    if(year < 0){
        throw std::runtime_error("Invalid year");
    }
}