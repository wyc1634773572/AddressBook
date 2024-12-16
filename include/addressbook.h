#include <iostream>
#include "debug.h"
using namespace std;

enum GENDER{
    MALE,
    FEMALE,
    OTHER
};

struct Personinfo
{
    const char* name;
    const char* address;
    const char* phonenumber;
    GENDER sex;
    int age;
    Personinfo* next;

    //默认初始化
    Personinfo(const char* n = "佚名"):name(n),address("无"),phonenumber("无"),sex(GENDER::OTHER),age(0),next(nullptr){}
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

    void findPerson(const char * name);

    void updatePerson(Personinfo p);

private:
    Personinfo* _head;
    Personinfo* _tail;
};