#include <iostream>
#include <memory>
#include "include/addressbook.h"
#include "include/menu.h"
using namespace std;

int main(){
    CaddressBook book;
    Personinfo* p = new Personinfo();
    strcpy(p->name, "tyl");
    strcpy(p->address, "sanqiang.st, 41");
    p->age = 26; 
    strcpy(p->phonenumber, "1111111111");
    p->sex = GENDER::FEMALE;

    Personinfo* p2 = new Personinfo();
    strcpy(p2->name, "wyc");
    strcpy(p2->address, "sanqiang.st, 41");
    p2->age = 26;
    strcpy(p2->phonenumber, "2222222222"); 
    p->sex = GENDER::MALE;
    book.addPerson(p);
    book.addPerson(p2);
    
    Cmenu menu;
    menu.init(&book);
    menu.run();
    return 0;
}