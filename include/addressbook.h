#ifndef _ADDRESSBOOK_H_
#define _ADDRESSBOOK_H_
#include <iostream>
#include <unistd.h>
#include <cstring>
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
    Personinfo* next;

    //默认初始化
    Personinfo():name("佚名"),address("无"),phonenumber("无"),sex(GENDER::OTHER),age(0),next(nullptr){}
    Personinfo(const Personinfo &other){
        cout << "拷贝构造" << endl;
    }
};


class CaddressBook{
public:
    CaddressBook();

    ~CaddressBook();

    void showall();

    void show(Personinfo *p);

    void addPerson(Personinfo *p);

    void delPerson(const char * name);

    Personinfo* findPerson(const char * name);

    void updatePerson(Personinfo *p, Personinfo p2);

private:
    Personinfo* _head;
    Personinfo* _tail;
};
#endif