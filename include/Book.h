#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
private:
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    bool available;

public:
    Book();
    Book(
        const std::string& title,
        const std::string& author,
        const std::string& isbn,
        int year
    );

    //getters
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    const std::string& getIsbn() const;
    int getYear() const;
    bool isAvailable() const;

    //setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setYear(int year);

    //loan control
    void markAsBorrowed();
    void markAsReturned();

    //book validation 
    static void validate(
        const std::string& title,
        const std::string& author,
        const std::string& isbn,
        int year
    );   

};

#endif