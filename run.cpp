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
    book.addPerson(p);
    book.show();
    book.delPerson("tyl");
    book.show();
    return 0;
}