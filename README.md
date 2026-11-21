# Library Management System 📚

A simple and efficient **Library Management System** developed in **C++**. This project demonstrates basic concepts of Object-Oriented Programming (OOP) and file handling/data management.

## 🚀 Features
* **Manage Books and Members:** Add books and members, borrow and return books.
* **Late Books:** Borrowed books are due after 14 days, and the late report lists the ones past due.
* **Clean Code:** Structured with modular files (`.h` and `.cpp`).

## 🛠️ Tech Stack
* **Language:** C++
* **Environment:** Compatible with any C++ compiler (GCC, Clang, MSVC).

## 📂 Project Structure
* `main.cpp`: The entry point of the application.
* `library.h`: the `Library` class (private books, members and borrows) and the data structs.
* `library.cpp`: add book/member, borrow, return, next day.
* `reports.cpp`: late books report (`Library::lateBooks`).
* `storage.cpp`: saving and loading books, members and borrows (`Library::saveData` / `Library::loadData`).

## 📊 Modules Added
* **Reporting System:** Generates clear summaries of the library's current state.
* **Data Storage:** Books, members and borrows are saved to `library_data.txt` and loaded again when the program starts.

Team:
Amira
Afnan
