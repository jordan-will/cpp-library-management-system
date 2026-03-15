# Library Management System (C++)

A modular command-line Library Management System written in modern C++.

The project demonstrates a layered architecture, object-oriented design, and persistent storage using CSV files.


# Features

### Book Management

* Register new books
* Store title, author, ISBN and publication year
* Track availability status
* List all registered books

### User Management

* Register new users
* Automatic incremental user ID generation
* Store name and email
* List registered users

### Persistence

* Persistent storage using **CSV files**
* Automatic loading of data on startup
* Manual save support
* Data serialization and deserialization

### Data Integrity

* Prevention of duplicate users
* Prevention of duplicate books (via ISBN)
* Consistent state validation
* Exception-based error handling

### Command-Line Interface

* Interactive menu system
* Clear separation between UI and business logic


# Technologies

* **C++17**
* **STL containers**

  * `std::vector`
  * `std::unordered_map`
* **File I/O**

  * `std::ifstream`
  * `std::ofstream`
* **Error Handling**

  * `std::runtime_error`
* **Build System**

  * CMake


# Software Architecture

The project follows a **modular architecture** separating domain logic, persistence, and application control.

## Core Domain

### `Book`

Represents a book in the library.

Attributes include:

* title
* author
* ISBN
* publication year
* availability status


### `User`

Represents a library user.

Attributes include:

* user ID
* name
* email


### `Library`

Central domain manager responsible for:

* storing books and users
* validating operations
* generating new user IDs
* coordinating persistence

Uses:

```
std::unordered_map<std::string, Book>
std::unordered_map<int, User>
```

for efficient lookups.


## Persistence Layer

### `Storage` (interface)

Abstract interface responsible for persistence operations.


### `CSVStorage`

Concrete implementation that saves and loads data from CSV files.

Responsibilities:

* serialize objects to file
* parse stored records
* reconstruct objects


## Application Layer

### `App`

Handles the **user interface and application flow**, including:

* menu interaction
* user input
* object creation
* invoking library operations


# Project Structure

```
src/
 ├── App.cpp
 ├── Book.cpp
 ├── CSVStorage.cpp
 ├── Library.cpp
 ├── User.cpp
 └── main.cpp

include/
 ├── App.h
 ├── Book.h
 ├── CSVStorage.h
 ├── Library.h
 ├── Storage.h
 └── User.h
```


# Build Instructions

The project uses **CMake**.

### Linux / macOS / Windows (with CMake)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run the program:

```bash
./library_app
```


# Example Workflow

Example interaction:

```
1 - Register User
2 - Register Book
3 - List Users
4 - List Books
0 - Exit
```

Example book entry:

```
Title: Clean Code
Author: Robert C. Martin
ISBN: 9780132350884
Year: 2008
```


# Design Goals

This project features the following architecture:

* Object-Oriented Design in C++
* Clean separation of responsibilities
* Persistent storage
* Exception-safe code
* CLI application architecture
* STL container usage
* Modular C++ project structure


# Future Improvements

Possible future extensions include:

* Book borrowing system
* Loan tracking
* Search functionality
* JSON storage support
* Unit testing
* Logging system


# Author

Jordan Willian
Contact: jordan.willian.mp@gmail.com
