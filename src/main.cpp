#include <iostream>

#include "App.h"
#include "Library.h"
#include "CSVStorage.h"

int main() {
    try {

        CSVStorage storage("../data/books.csv", "../data/users.csv");

        Library library(storage);

        library.load();

        App app(library);
        app.run();

        library.save();

    } catch (const std::exception& e) {

        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}