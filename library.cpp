#include <iostream>
#include "library.h"
using namespace std;

Library::Library(){
    currentDay = 0;
}

void Library::addBook(){
    Book b;
    cout<<"Book code: ";
    cin>>b.code;
    cout<<"Book title: ";
    cin.ignore();
    getline(cin,b.title);
    cout<<"Copies: ";
    cin>>b.totalCopies;
    b.availableCopies = b.totalCopies;
    books.push_back(b);
    cout<<"Book added\n";
}

void Library::addMember(){
    Member m;
    cout<<"Member code: ";
    cin>>m.memberCode;
    cout<<"Member name: ";
    cin.ignore();
    getline(cin,m.memberName);
    members.push_back(m);
    cout<<"Member added\n";
}

Book* Library::searchBook(const string &code){
    for(int i=0;i<books.size();i++){
        if(books[i].code==code)
            return &books[i];
    }
    return NULL;
}

Member* Library::searchMember(const string &code){
    for(int i=0;i<members.size();i++){
        if(members[i].memberCode==code)
            return &members[i];
    }
    return NULL;
}

void Library::borrowBook(){
    string bCode,mCode;
    cout<<"Book code: ";
    cin>>bCode;
    cout<<"Member code: ";
    cin>>mCode;

    Book* b = searchBook(bCode);
    if(b==NULL){
        cout<<"Book not found\n";
        return;
    }
    if(searchMember(mCode)==NULL){
        cout<<"Member not found\n";
        return;
    }
    if(b->availableCopies==0){
        cout<<"No copies available\n";
        return;
    }

    Borrow br;
    br.bookCode = bCode;
    br.memberCode = mCode;
    br.dayTaken = currentDay;
    br.dayReturn = currentDay + 14;
    borrows.push_back(br);
    b->availableCopies--;
    cout<<"Book borrowed\n";
}

void Library::giveBackBook(){
    string bCode,mCode;
    cout<<"Book code: ";
    cin>>bCode;
    cout<<"Member code: ";
    cin>>mCode;

    for(int i=0;i<borrows.size();i++){
        if(borrows[i].bookCode==bCode &&
           borrows[i].memberCode==mCode){
            Book* b = searchBook(bCode);
            if(b!=NULL)
                b->availableCopies++;
            borrows.erase(borrows.begin()+i);
            cout<<"Book returned\n";
            return;
        }
    }
    cout<<"Borrow not found\n";
}

void Library::nextDay(){
    currentDay++;
}
