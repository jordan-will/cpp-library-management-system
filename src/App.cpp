#include "User.h"
#include "Book.h"
#include "App.h"

#include <iostream>
#include <limits>

App::App(Library& library): library(library), running(true){}

void App::run(){
    while(running){
        showMenu();
        int option;

        if(!(std::cin >> option)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << "Invalid input. Please, enter a valid options.";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        handleOption(option);
    }//end while
}

void App::showMenu(){
    std::cout << "\n ===== Libray Management System =====\n";
    std::cout << "Select an options: \n";
    std::cout << "1. Register User\n";
    std::cout << "2. List Users\n";
    std::cout << "3. Register Book\n";
    std::cout << "4. List Books\n";
    std::cout << "0. Exit\n";
}

void App::handleOption(int option){
    switch (option)
    {
    case 1:
        createUser();
        break;
    case 2:
        listUser();
        break;
    case 3:
        createBook();
        break;
    case 4:
        listBooks();
        break;
    case 0:
        running = false;
        break;
    default:
        std::cout << "Invalid options\n";
        break;
    }
}

void App::createUser(){
    std::string name;
    std::string email;

    std::cout << "Enter a user name: ";
    std::getline(std::cin, name);

    std::cout << "Enter user email: ";
    std::getline(std::cin, email);

    const int userId = library.generateUserId(); 
    

    User newUser(userId, name, email);

    library.addUser(newUser);

    std::cout << "User registered successfully\n";
}

void App::listUser(){
    const auto& users = library.getAllUsers();

    if(users.empty()){
        std::cout << "No users registered.\n";
        return;
    }

    std::cout << "\n--- Users --- \n";

    for(const auto& [id, user]: users){
        std::cout << "ID: " << user.getId()
                  << " | Name: " << user.getName()
                  << " | Email: " << user.getEmail()
                  << "\n";  
    }
}

void App::createBook(){
    
    std::string title;
    std::string author;
    std::string isbn;
    int year;

    std::cout << "Enter book title: ";
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);

    std::cout << "Enter publication year";
    std::cin >> year;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max());

    Book newBook(title, author, isbn, year);

    library.addBook(newBook);

    std::cout << "Book registered successfully.\n";
}

void App::listBooks(){
    const auto& books = library.getAllBooks();

    if(books.empty()){
        std::cout << "No books registered.\n";
        return;
    }

    std::cout << "\n--- Books ---\n";

    for(const auto& [isbn, book] : books){
        std::cout << "Title: " << book.getTitle()
                  << " | Author: " << book.getAuthor()
                  << " | ISBN: "  << book.getIsbn()
                  << " | Available: " << (book.isAvailable() ? "Yes" : "No")
                  << "\n";
    }
}