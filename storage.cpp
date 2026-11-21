#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "library.h"
using namespace std;

void Library::saveData(){
    ofstream file("library_data.txt");
    file<<currentDay<<endl;

    file<<books.size()<<endl;
    for(int i=0;i<books.size();i++){
        file<<books[i].code<<"|"
            <<books[i].title<<"|"
            <<books[i].totalCopies<<"|"
            <<books[i].availableCopies
            <<endl;
    }

    file<<members.size()<<endl;
    for(int i=0;i<members.size();i++){
        file<<members[i].memberCode<<"|"
            <<members[i].memberName
            <<endl;
    }

    file<<borrows.size()<<endl;
    for(int i=0;i<borrows.size();i++){
        file<<borrows[i].bookCode<<"|"
            <<borrows[i].memberCode<<"|"
            <<borrows[i].dayTaken<<"|"
            <<borrows[i].dayReturn
            <<endl;
    }

    file.close();
    cout<<"Data saved\n";
}

void Library::loadData(){
    ifstream file("library_data.txt");
    if(!file){
        return;
    }

    books.clear();
    members.clear();
    borrows.clear();

    string line;
    int n;

    getline(file,line);
    currentDay = atoi(line.c_str());

    getline(file,line);
    n = atoi(line.c_str());
    for(int i=0;i<n;i++){
        getline(file,line);
        stringstream ss(line);
        string total,avail;
        Book b;
        getline(ss,b.code,'|');
        getline(ss,b.title,'|');
        getline(ss,total,'|');
        getline(ss,avail,'|');
        b.totalCopies = atoi(total.c_str());
        b.availableCopies = atoi(avail.c_str());
        books.push_back(b);
    }

    getline(file,line);
    n = atoi(line.c_str());
    for(int i=0;i<n;i++){
        getline(file,line);
        stringstream ss(line);
        Member m;
        getline(ss,m.memberCode,'|');
        getline(ss,m.memberName,'|');
        members.push_back(m);
    }

    getline(file,line);
    n = atoi(line.c_str());
    for(int i=0;i<n;i++){
        getline(file,line);
        stringstream ss(line);
        string taken,ret;
        Borrow br;
        getline(ss,br.bookCode,'|');
        getline(ss,br.memberCode,'|');
        getline(ss,taken,'|');
        getline(ss,ret,'|');
        br.dayTaken = atoi(taken.c_str());
        br.dayReturn = atoi(ret.c_str());
        borrows.push_back(br);
    }

    file.close();
    cout<<"Data loaded\n";
}
