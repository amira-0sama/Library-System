#include <iostream>
#include "library.h"
using namespace std;

int main(){

    Library lib;
    lib.loadData();
    int op;

    do{

        cout<<"\nLibrary Menu\n";

        cout<<"1 Add Book\n";
        cout<<"2 Add Member\n";
        cout<<"3 Borrow Book\n";
        cout<<"4 Return Book\n";
        cout<<"5 Late Books\n";
        cout<<"6 Next Day\n";
        cout<<"7 Save Data\n";
        cout<<"0 Exit\n";

        cin>>op;

        if(op==1) lib.addBook();
        else if(op==2) lib.addMember();
        else if(op==3) lib.borrowBook();
        else if(op==4) lib.giveBackBook();
        else if(op==5) lib.lateBooks();
        else if(op==6) lib.nextDay();
        else if(op==7) lib.saveData();

    }while(op!=0);

}
