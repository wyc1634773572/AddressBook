#include "addressbook.h"
using namespace std;

class Cstatus{
public:
    virtual void show() = 0;
};

class Cmenu{
public:
    Cmenu();

    ~Cmenu();

    //初始化
    void init(CaddressBook* );
    //运行
    void run();
    //切换状态
    void setstatus();
private:
    //状态
    Cstatus* status;
    //通讯录
    CaddressBook* book;
};
