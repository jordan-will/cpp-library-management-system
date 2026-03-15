#ifndef APP_H
#define APP_H

#include "Library.h"
class App{
public:
    App(Library& library);
    void run();
private:
    Library& library;
    bool running;

    void showMenu();
    void handleOption(int option);

    void createUser();
    void listUser();

    void createBook();
    void listBooks();
};

#endif