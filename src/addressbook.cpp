#include "../include/addressbook.h"
#include <cstring>

CaddressBook::CaddressBook(){
    _head = new Personinfo();
    _tail = _head;
    LOG_INFO("CaddressBook constructed!");
}

CaddressBook::~CaddressBook(){
    delete _head;
    LOG_INFO("CaddressBook deleted!");
}

void CaddressBook::showall(){
    Personinfo* cur = _head->next;
    while (cur != nullptr)
    {
        show(cur);
        cur = cur->next;
    }
}

void CaddressBook::show(Personinfo *p){
    cout << "姓名：" << p->name << endl;
    cout << "性别：" << p->sex << endl;
    cout << "地址：" << p->address << endl;
    cout << "年龄：" << p->age << endl;
    cout << "电话号码：" << p->phonenumber << endl;
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

void CaddressBook::findPerson(const char * name){
    Personinfo* cur = _head;
    while (cur != nullptr)
    {
        if(strcmp(cur->name, name) == 0) show(cur);
        cur = cur->next;
    }

}