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
    if (p == nullptr){
        cout << "查无此人"<<endl;
    }else{
        cout << "----------------------------------" << endl;
        cout << "|姓名：" << p->name << endl;
        cout << "|性别：" << p->sex << endl;
        cout << "|地址：" << p->address << endl;
        cout << "|年龄：" << p->age << endl;
        cout << "|电话号码：" << p->phonenumber << endl;
        cout << "----------------------------------" << endl;
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
        if(strcmp(cur->next->name, name) == 0){
            delete cur->next;
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }
}

Personinfo* CaddressBook::findPerson(const char * name){
    Personinfo* cur = _head;
    while (cur != nullptr)
    {
        if(strcmp(cur->name, name) == 0) break;
        cur = cur->next;
    }
    return cur;
}

void CaddressBook::updatePerson(Personinfo *p, Personinfo p2){
    strcpy(p->name, p2.name);
    strcpy(p->address, p2.address);
    p->age = p2.age;
    strcpy(p->phonenumber, p2.phonenumber);
    p->sex = p2.sex;
}