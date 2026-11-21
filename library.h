#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>

struct Book{
    std::string code;
    std::string title;
    int totalCopies;
    int availableCopies;
};

struct Member{
    std::string memberCode;
    std::string memberName;
};

struct Borrow{
    std::string bookCode;
    std::string memberCode;
    int dayTaken;
    int dayReturn;
};

class Library{
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Borrow> borrows;
    int currentDay;

    Book* searchBook(const std::string &code);
    Member* searchMember(const std::string &code);

public:
    Library();

    void addBook();
    void addMember();
    void borrowBook();
    void giveBackBook();
    void nextDay();

    void lateBooks();

    void saveData();
    void loadData();
};

#endif
