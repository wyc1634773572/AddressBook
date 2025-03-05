#include "addressbook.h"
#include <cstring>

CaddressBook::CaddressBook(){
    _head = make_shared<Personinfo>();
    _tail = _head;
    LOG_INFO("CaddressBook constructed!");
}

CaddressBook::~CaddressBook(){
    LOG_INFO("CaddressBook deleted!");
}

bool CaddressBook::showall(){
    if(nullptr == _head)
        return false;
    auto cur = _head->next;
    while (cur != nullptr)
    {
        show(*cur);
        cur = cur->next;
    }
    return true;
}

bool CaddressBook::show(const Personinfo& p){
    cout << "----------------------------------" << endl;
    cout << "|姓名：" << p.name << endl;
    string SEX;
    switch (p.sex)
    {
    case GENDER::FEMALE:
        SEX = "女";
        break;
    case GENDER::MALE:
        SEX = "男";
        break;
    default:
        SEX = "LGBT+";
        break;
    }
    cout << "|性别：" << SEX << endl;
    cout << "|地址：" << p.address << endl;
    cout << "|年龄：" << p.age << endl;
    cout << "|电话号码：" << p.phonenumber << endl;
    cout << "----------------------------------" << endl;
    return true;
}

bool CaddressBook::addPerson(const shared_ptr<Personinfo>& p){
    if(nullptr == p || nullptr == _tail) 
        return false;
    _tail->next = p;
    _tail = _tail->next;
    return true;
}

bool CaddressBook::delPerson(const char * name){
    if(nullptr == _head || nullptr == name){
        return false;
    }
    shared_ptr<Personinfo> cur = _head;
    while (cur->next != nullptr)
    {
        if(strcmp(cur->next->name, name) == 0){
            if(cur->next == _tail){
                _tail = cur;
            }
            cur->next.reset(cur->next->next.get());
            break;
        }
        cur = cur->next;
    }
    return true;
}

bool CaddressBook::findPerson(const char * name){
    if(nullptr == _head || nullptr == name){
       return false; 
    }
    shared_ptr<Personinfo> cur = _head;
    while (1)
    {
        if(strcmp(cur->name, name) == 0) break;
        cur = cur->next;
        if(cur == nullptr) return false;
    }
    show(*cur);
    return true;
}

bool CaddressBook::updatePerson(shared_ptr<Personinfo> p, Personinfo p2){
    strcpy(p->name, p2.name);
    strcpy(p->address, p2.address);
    p->age = p2.age;
    strcpy(p->phonenumber, p2.phonenumber);
    p->sex = p2.sex;
    return true;
}