#include <gtest/gtest.h>
#include <memory>
#include "addressbook.h"
#include "menu.h"

TEST(InterfaceTest, Cmenu_init1){
    Cmenu mu;
    shared_ptr<CaddressBook> bk = make_shared<CaddressBook>();
    EXPECT_EQ(mu.init(bk), RTINFO::RTSUCCESS);
}

TEST(InterfaceTest, Cmenu_init2){
    Cmenu mu;
    shared_ptr<CaddressBook> bk = make_shared<CaddressBook>();
    bk.reset();
    EXPECT_EQ(mu.init(bk), RTINFO::NULLPOINT_ERROR);
}
