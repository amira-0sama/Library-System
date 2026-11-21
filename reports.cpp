#include <iostream>
#include "library.h"
using namespace std;

void Library::lateBooks(){
    for(int i=0;i<borrows.size();i++){
        if(currentDay > borrows[i].dayReturn){
            cout<<"Late book: "
                <<borrows[i].bookCode
                <<endl;
        }
    }
}
