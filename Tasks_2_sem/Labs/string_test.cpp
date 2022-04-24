#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "MyString.h"

TEST_CASE("String") 
{
    SECTION("1") {
        MyString exA("123");
        MyString copyA(exA); // copy-constructor
        REQUIRE(exA == copyA);
        MyString moveCopyA(std::move(copyA)); // move-constructor
        REQUIRE(exA == moveCopyA);
        REQUIRE(copyA == nullptr);

        MyString exOper = "abcdf";
        MyString ex("abcdf");
        REQUIRE(exOper == ex);
        MyString exOther("123f");
        exOper = "123f";
        REQUIRE(exOther == exOper);
    }

    SECTION("2") {
        MyString exB("abcdef");
        MyString addStr("123");
        exB.insert(3, addStr);
        MyString res("abc123def");
        REQUIRE(exB == res);
        exB.append(addStr);
        MyString ap("abc123def123");
        REQUIRE(exB == ap);
        exB.clear();
        REQUIRE(exB == nullptr);
        REQUIRE((exB + addStr) == addStr);

    }

    SECTION("3") {
        MyString exC("asdFGhjhjd");
        exC.erase(3,2);
        MyString test("asdhjhjd");
        REQUIRE(exC == test);
        MyString b("123");
    }

    SECTION("4") {
        MyString exD("816274");
        char at3 = exD.at(3);
        char at = '2';
        REQUIRE(at3 == at);
        char at4 = exD[4];
        char a4 = '7';
        REQUIRE(at4 == a4);
        int sizestr = exD.size();
        REQUIRE(sizestr == 6);
    }

    SECTION("5") {
        MyString test("12082002");
        REQUIRE(test.isEmpty() == 0);
        REQUIRE(std::string(test.rawString()) == std::string("12082002"));
        REQUIRE(test.find("02", 0) == 6);
    }

    SECTION("exception") {
        MyString test("123456123");
        try {
            test.insert(20, "12");
        }
        catch(std::exception &test) {
            REQUIRE(std::string(test.what()) == std::string("Called insert(20) on string of size 9"));
        }

        try {
            test.at(14);
        }
        catch(std::exception &test) {
            REQUIRE(std::string(test.what()) == std::string("Called at(14) on string of size 9"));
        }

        try {
            test.erase(15,2);
        }
        catch(std::exception &test) {
            REQUIRE(std::string(test.what()) == std::string("Called erase(15) on string of size 9"));
        }        
    }

    SECTION("compare") {
        MyString ex("123");
        MyString ex1("1234");
        REQUIRE(ex1.compare(ex) == 1);
        REQUIRE(ex.compare(ex1) == -1);
        MyString exChar("abcg");
        MyString exCh("1sdb");
        REQUIRE(exChar.compare(exCh) == 48);
        REQUIRE(exCh.compare(exChar) == -48);
        MyString ex2("123");
        REQUIRE(ex.compare(ex2) == 0);
    }

    SECTION("operator") {
        MyString ex("123");
        MyString ex1("1234");
        REQUIRE((ex == ex1) == 0);
        REQUIRE((ex != ex1) == 1);
        REQUIRE((ex > ex1) == 0);
        REQUIRE((ex < ex1) == 1);
        REQUIRE((ex >= ex1) == 0);
        REQUIRE((ex <= ex1) == 1);
    }
}