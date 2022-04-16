#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "String.h"

int strToInt(const char* str);
TEST_CASE(" ")
{
    SECTION( "" ) 
    {
        REQUIRE(strToInt("123") == (int)123);
        REQUIRE(strToInt("0123") == (int)123);
        REQUIRE(strToInt("01") == (int)1);
        REQUIRE(strToInt("012030") == (int)12030);
        REQUIRE(strToInt("-123") == (int)(-123));
        REQUIRE(strToInt("0") == (int)0);
        REQUIRE(strToInt("-0120") == (int)(-120));
    }
}


void mutableToLower(char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        char str[] = "wOrDs ";
        mutableToLower(str);
        REQUIRE(std::string(str) == std::string("words "));

        char str1[] = "Sleep";
        mutableToLower(str1);
        REQUIRE(std::string(str1) == std::string("sleep"));

        char str2[] = " worD ";
        mutableToLower(str2);
        REQUIRE(std::string(str2) == std::string(" word "));

        char str3[] = "123GOOD";
        mutableToLower(str3);
        REQUIRE(std::string(str3) == std::string("123good"));

        char str4[] = "!@G OOd";
        mutableToLower(str4);
        REQUIRE(std::string(str4) == std::string("!@g ood"));
    }
}


char* immutableToLower(const char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        REQUIRE(std::string(immutableToLower("Wo rD s")) == std::string("wo rd s"));
        REQUIRE(std::string(immutableToLower("Sleep")) == std::string("sleep"));
        REQUIRE(std::string(immutableToLower(" worD ")) == std::string(" word "));
        REQUIRE(std::string(immutableToLower("123GooD ")) == std::string("123good"));
        REQUIRE(std::string(immutableToLower("1@rYKv# j H")) == std::string("1@rykv# j h"));
        REQUIRE(std::string(immutableToLower("1")) == std::string("1"));
        REQUIRE(std::string(immutableToLower("")) == std::string(""));
    }
}


void mutableToUpper(char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        char str[] = "wOrDs ";
        mutableToUpper(str);
        REQUIRE(std::string(str) == std::string("WORDS "));

        char str1[] = "Sleep";
        mutableToUpper(str1);
        REQUIRE(std::string(str1) == std::string("SLEEP"));

        char str2[] = " worD ";
        mutableToUpper(str2);
        REQUIRE(std::string(str2) == std::string(" WORD "));

        char str3[] = "123GOOD";
        mutableToUpper(str3);
        REQUIRE(std::string(str3) == std::string("123GOOD"));

        char str4[] = "!@G OOd";
        mutableToUpper(str4);
        REQUIRE(std::string(str4) == std::string("!@G OOD"));

        char str5[] = "";
        mutableToUpper(str5);
        REQUIRE(std::string(str5) == std::string(""));
    }
}


char* immutableToUpper(const char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        REQUIRE(std::string(immutableToUpper("Wo rD s")) == std::string("WO RD S"));
        REQUIRE(std::string(immutableToUpper("Sleep")) == std::string("SLEEP"));
        REQUIRE(std::string(immutableToUpper(" worD ")) == std::string(" WORD "));
        REQUIRE(std::string(immutableToUpper("123GooD ")) == std::string("123GOOD"));
        REQUIRE(std::string(immutableToUpper("1@rYKv# j H")) == std::string("1@RYKV# J H"));
        REQUIRE(std::string(immutableToUpper("1")) == std::string("1"));
        REQUIRE(std::string(immutableToUpper("")) == std::string(""));
    }
}


void mutableStrip(char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        char str[] = "words ";
        mutableStrip(str);
        REQUIRE(std::string(str) == std::string("words"));

        char str1[] = "Sleep";
        mutableStrip(str1);
        REQUIRE(std::string(str1) == std::string("Sleep"));

        char str2[] = " worD ";
        mutableStrip(str2);
        REQUIRE(std::string(str2) == std::string("worD"));

        char str3[] = "   ";
        mutableStrip(str3);
        REQUIRE(std::string(str3) == std::string(""));

        char str4[] = "!@G OOd     ";
        mutableStrip(str4);
        REQUIRE(std::string(str4) == std::string("!@G OOd"));

        char str5[] = "";
        mutableStrip(str5);
        REQUIRE(std::string(str5) == std::string(""));

        char str6[] = "     f                          ";
        mutableStrip(str6);
        REQUIRE(std::string(str6) == std::string("f"));
    }
}


char* immutableStrip(const char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        REQUIRE(std::string(immutableStrip("words ")) == std::string("words"));
        REQUIRE(std::string(immutableStrip("Sleep")) == std::string("Sleep"));
        REQUIRE(std::string(immutableStrip(" worD ")) == std::string("worD"));
        REQUIRE(std::string(immutableStrip("     ")) == std::string(""));
        REQUIRE(std::string(immutableStrip("!@G OOd     ")) == std::string("!@G OOd"));
        REQUIRE(std::string(immutableStrip("    1    ")) == std::string("1"));
        REQUIRE(std::string(immutableStrip("")) == std::string(""));
        REQUIRE(std::string(immutableStrip("  w  o r d   ")) == std::string("w  o r d"));
    }
}


void mutableRemoveSpaces(char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        char str[] = " w or ds ";
        mutableRemoveSpaces(str);
        REQUIRE(std::string(str) == std::string("words"));

        char str1[] = "   Sl  e e p   ";
        mutableRemoveSpaces(str1);
        REQUIRE(std::string(str1) == std::string("Sleep"));

        char str2[] = " w o r D ";
        mutableRemoveSpaces(str2);
        REQUIRE(std::string(str2) == std::string("worD"));

        char str3[] = "   ";
        mutableRemoveSpaces(str3);
        REQUIRE(std::string(str3) == std::string(""));

        char str4[] = "  ! @G OOd     ";
        mutableRemoveSpaces(str4);
        REQUIRE(std::string(str4) == std::string("!@GOOd"));

        char str5[] = "";
        mutableRemoveSpaces(str5);
        REQUIRE(std::string(str5) == std::string(""));

        char str6[] = "     f                          a";
        mutableRemoveSpaces(str6);
        REQUIRE(std::string(str6) == std::string("fa"));
    }
}


char* immutableRemoveSpaces(const char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        REQUIRE(std::string(immutableRemoveSpaces(" w  o r ds ")) == std::string("words"));
        REQUIRE(std::string(immutableRemoveSpaces(" Sle ep ")) == std::string("Sleep"));
        REQUIRE(std::string(immutableRemoveSpaces(" wo r D ")) == std::string("worD"));
        REQUIRE(std::string(immutableRemoveSpaces("     ")) == std::string(""));
        REQUIRE(std::string(immutableRemoveSpaces("    1    ")) == std::string("1"));
        REQUIRE(std::string(immutableRemoveSpaces("")) == std::string(""));
        REQUIRE(std::string(immutableRemoveSpaces("f    a    g")) == std::string("fag"));
    }
}


void mutableFilter(char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        char str[] = " #w@ #o1r2* d3s &";
        mutableFilter(str);
        REQUIRE(std::string(str) == std::string("wo1r2d3s"));

        char str2[] = " !2w@ 3o 6r +=D ";
        mutableFilter(str2);
        REQUIRE(std::string(str2) == std::string("2w3o6rD"));

        char str3[] = "   ";
        mutableFilter(str3);
        REQUIRE(std::string(str3) == std::string(""));

        char str4[] = "  ! @G OOd     ";
        mutableFilter(str4);
        REQUIRE(std::string(str4) == std::string("GOOd"));

        char str5[] = "";
        mutableFilter(str5);
        REQUIRE(std::string(str5) == std::string(""));

        char str6[] = "!1     f                          a!";
        mutableFilter(str6);
        REQUIRE(std::string(str6) == std::string("1fa"));
    }
}


char* immutableFilter(const char* str);
TEST_CASE(" ")
{
    SECTION( " " ) 
    {
        REQUIRE(std::string(immutableFilter("1! w  o3 r d4s 8")) == std::string("1wo3rd4s8"));
        REQUIRE(std::string(immutableFilter(" Sle ep ")) == std::string("Sleep"));
        REQUIRE(std::string(immutableFilter(" w@o r D !")) == std::string("worD"));
        REQUIRE(std::string(immutableFilter("     ")) == std::string(""));
        REQUIRE(std::string(immutableFilter("    !1#    ")) == std::string("1"));
        REQUIRE(std::string(immutableFilter("")) == std::string(""));
        REQUIRE(std::string(immutableFilter("f :3  + a  -_- =  g")) == std::string("f3ag"));
    }
}


bool isNumber(const char* str);
TEST_CASE("isNumber")
{
    SECTION("positive integers")
    {
        REQUIRE(isNumber("1234") == true);
        REQUIRE(isNumber("0") == true);
        REQUIRE(isNumber("1234positive") == false);
        REQUIRE(isNumber(".1234") == true);
    }
    
    SECTION("negative integers")
    {
        REQUIRE(isNumber("-1234") == true);
        REQUIRE(isNumber("123-") == false);
        REQUIRE(isNumber("12-3") == false);
        REQUIRE(isNumber("--1234") == false);
    }
    
    SECTION("non negative real")
    {
        REQUIRE(isNumber("0.0") == true);
        REQUIRE(isNumber("123.6666") == true);
        REQUIRE(isNumber("12.3.666") == false);
        REQUIRE(isNumber("..1234") == false);
        REQUIRE(isNumber("1234.") == false);
        REQUIRE(isNumber("") == false);
    }
}


bool isAlpha(const char* str);
TEST_CASE(" ")
{
    SECTION( "" ) 
    {
        REQUIRE(isAlpha("123") == false);
        REQUIRE(isAlpha("abcd") == true);
        REQUIRE(isAlpha("0acv") == false);
        REQUIRE(isAlpha("avf0") == false);
        REQUIRE(isAlpha(" ab") == false);
        REQUIRE(isAlpha("ab ") == false);
        REQUIRE(isAlpha("a b") == false);
        REQUIRE(isAlpha("ABc") == true);
        REQUIRE(isAlpha("a+b") == false);
        REQUIRE(isAlpha("") == false);
        REQUIRE(isAlpha("   ") == false);
        REQUIRE(isAlpha("+av ") == false);
        REQUIRE(isAlpha("+") == false);
        REQUIRE(isAlpha("aBcD") == true);
    }
}