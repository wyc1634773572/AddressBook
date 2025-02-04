#ifndef _ADDRESSBOOK_H_
#define _ADDRESSBOOK_H_
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <memory>
#include "debug.h"
using namespace std;

enum GENDER{
    MALE,
    FEMALE,
    OTHER
};

struct Personinfo
{
    char name[32];
    char address[32];
    char phonenumber[32];
    GENDER sex;
    int age;
    shared_ptr<Personinfo> next;

    //默认初始化
    Personinfo():name("佚名"),address("无"),phonenumber("无"),sex(GENDER::OTHER),age(0),next(nullptr){}
    Personinfo(const Personinfo &other){
        cout << "拷贝构造" << endl;
    }
    ~Personinfo(){}
};


class CaddressBook{
public:
    CaddressBook();

    ~CaddressBook();

    bool showall();

    bool show(const Personinfo& p);

    bool addPerson(shared_ptr<Personinfo> p);

    bool delPerson(const char * name);

    bool findPerson(const char * name);

    bool updatePerson(shared_ptr<Personinfo> p, Personinfo p2);

private:
    shared_ptr<Personinfo> _head;
    shared_ptr<Personinfo> _tail;
};
#endif