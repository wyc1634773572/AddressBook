#include "../include/menu.h"

Cmenu::Cmenu(){
    status = nullptr;
    book = nullptr;
}

Cmenu::~Cmenu(){
    //delete book;     //double free!
}

void Cmenu::init(shared_ptr<CaddressBook> bk){
    book = bk;
}

void Cmenu::run(){
    char input[1];
    while (true)
    {
        cout << "=========================" << endl;
        cout << "1.显示所有联系人" << endl;
        cout << "2.查找联系人" << endl;
        cout << "3.新增联系人" << endl;
        cout << "4.删除联系人" << endl;
        cout << "0.退出" << endl;
        cout << "=========================" << endl;
        cin >> input;
        if(input[0] == '0'){
            break;
        }else if(input[0] == '1'){
            book->showall();
        }else if(input[0] == '2'){
            cout << "请输入要查找的联系人" << endl;
            char buf[30];
            cin >> buf;
            auto person = book->findPerson(buf);
            book->show(person);
        }else if(input[0] == '3'){
            auto p = make_shared<Personinfo>();
            char buf[64];
            cout << "请输入用户姓名" << endl;
            cin >> buf;
            strcpy(p->name, buf);

            cout << "请输入用户年龄" << endl;
            cin >> buf;
            p->age = atoi(buf);

            cout << "请输入用户性别" << endl;
            cin >> buf;
            if(atoi(buf) == 0) p->sex = GENDER::MALE;
            else if (atoi(buf) == 1) p->sex = GENDER::FEMALE;
            else p->sex = GENDER::OTHER;

            cout << "请输入用户地址" << endl;
            cin >> buf;
            strcpy(p->address, buf);

            cout << "请输入用户电话" << endl;
            cin >> buf;
            strcpy(p->phonenumber, buf);
            book->addPerson(p);     //没有释放p，内存泄漏
        }else if(input[0] == '4'){
            cout << "输入要删除的联系人名字" << endl;
            char buf[30];
            cin >> buf;
            book->delPerson(buf);
        }
        cout << "按回车键返回主菜单" << endl;
        cin.ignore();
        cin.get();
    }
}