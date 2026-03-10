# Library Management System (C++)

A modular C++ library management system built to demonstrate modern C++ design and architecture.

## Features

- Book registration
- User registration
- Book borrowing and returning
- File persistence (CSV / JSON)
- Search by title and author
- Exception handling with `std::runtime_error`

## Technologies

- C++17
- STL (vector, map)
- CMake
- Object-Oriented Design
- RAII

## Architecture

Main classes:

- `Book`
- `User`
- `Library`
- `LoanManager`

The project follows good practices such as:

- separation of header and implementation
- SOLID principles
- exception-safe code

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Status

Work in progress