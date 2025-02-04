#include <gtest/gtest.h>
#include <memory>
#include "addressbook.h"
#include "menu.h"

class CTestAddress : public testing::Test{
public:
    CaddressBook bk;
    shared_ptr<Personinfo> p;

    void SetUp() override{
        p = make_shared<Personinfo>();
    }
    
    void TearDown() override{
    }
};

TEST_F(CTestAddress, showall){
    EXPECT_EQ(bk.showall(), true);
}

TEST_F(CTestAddress, show){
    EXPECT_EQ(bk.show(*p), true);
}

TEST_F(CTestAddress, findperson){
    bk.addPerson(p);
    const char* pc = nullptr;
    EXPECT_EQ(bk.findPerson(pc), false);
    EXPECT_EQ(bk.findPerson("wyc"), false);
    EXPECT_EQ(bk.findPerson("佚名"), true);
}

TEST_F(CTestAddress, addPerson){
    EXPECT_EQ(bk.addPerson(p), true);
    p.reset();
    EXPECT_EQ(bk.addPerson(p), false);
}

TEST_F(CTestAddress, delPerson){
    const char* p = nullptr;
    EXPECT_EQ(bk.delPerson("wone"), true);
    EXPECT_EQ(bk.delPerson(""), true);
    EXPECT_EQ(bk.delPerson(p), false);
}