#include <iostream>
#include <memory>
#include "include/addressbook.h"
#include "include/menu.h"
using namespace std;

int main(){
    shared_ptr<CaddressBook> book = make_shared<CaddressBook>();
    Cmenu menu;
    menu.init(book);
    menu.run();
    return 0;
}