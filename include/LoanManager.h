#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include <string>

class Library;

class LoanManager{
private: 
    Library& library;
public:
    LoanManager(Library& library);

    void borrowBook(int userId, const std::string& isbn);
    void returnBook(const std::string& isbn);
};
#endif