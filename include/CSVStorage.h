#ifndef CSVSTORAGE_H
#define CSVSTORAGE_H

#include "Storage.h"
#include <string>

class CSVStorage: public Storage{
private:
    std::string booksFile;
    std::string usersFile;
public:
    CSVStorage(
        const std::string& booksFile,
        const std::string& usersFile
    );

    void saveBooks(const std::vector<Book>& books) override;
    std::vector<Book> loadBooks() override;

    void saveUsers(const std::vector<User>& users) override;
    std::vector<User> loadUsers() override;
};

#endif