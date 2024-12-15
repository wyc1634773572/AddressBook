#include "../include/addressbook.h"

CaddressBook::CaddressBook(){
    _head = new Personinfo();
    _tail = _head;
    LOG_INFO("CaddressBook constructed!");
}

CaddressBook::~CaddressBook(){
    delete _head;
    LOG_INFO("CaddressBook deleted!");
}

void CaddressBook::show(){
    Personinfo* cur = _head->next;
    while (cur != nullptr)
    {
        cout << cur->name << endl;
        cout << cur->address << endl;
        cout << cur->age << endl;
        cout << cur->phonenumber << endl;
        cout << cur->sex << endl;
        cur = cur->next;
    }
    
}

//传入值和传入指针有什么不同？
void CaddressBook::addPerson(Personinfo *p){
    _tail->next = p;
    _tail = _tail->next;
}

void CaddressBook::delPerson(const char * name){
    Personinfo* cur = _head;
    while (cur->next != nullptr)
    {
        if(cur->next->name == name){
            delete cur->next;
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }
}