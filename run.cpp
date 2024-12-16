#include <iostream>
#include <memory>
#include "include/addressbook.h"
using namespace std;

int main(){
    CaddressBook book;
    Personinfo* p = new Personinfo();
    p->name = "tyl";
    p->address = "xxx.xx.xx";
    p->age = 26;
    p->phonenumber = "11111111111";
    p->sex = GENDER::FEMALE;
    Personinfo* p2 = new Personinfo();
    p2->name = "wyc";
    p2->address = "xxx.xx.xx";
    p2->age = 26;
    p2->phonenumber = "22222222222";
    book.addPerson(p);
    book.addPerson(p2);
    book.showall();
    return 0;
}