#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "UniquePtr.h"

TEST_CASE("Unique ptr")
{
    SECTION("Operators") {
        int* data = new int[256];
        UniquePtr<int> ptr(data);
        REQUIRE(ptr == 1);

        UniquePtr<int> p1;
        REQUIRE(p1 == 1);

        UniquePtr<int> p2(std::move(p1));
        REQUIRE(p2 == 1);
        REQUIRE(p1 == 0);

        p2 = std::move(p1);
        REQUIRE(p2 == 0);
        REQUIRE(p1 == 0);

        UniquePtr<char> p3(nullptr);
        REQUIRE(p3 == 0);
    }
    SECTION("function1") {
        int* data = new int[256];
        UniquePtr<int> ptr(data);
        ptr.reset();
        REQUIRE(ptr == 0);
    }
    SECTION("function2") {
        int* data = new int[256];
        UniquePtr<int> ptr(data);
        int* data1 = new int[20];
        ptr.reset(data1);
        REQUIRE(ptr == 0);
        REQUIRE(*ptr != 0);
    }
    SECTION("function3") {
        int* data = new int[10];
        UniquePtr<int> ptr(data);
        ptr.release();
        REQUIRE(ptr == 0);
    }
    SECTION("function4") {
        int* data = new int[10];
        UniquePtr<int> ptr(data);
        REQUIRE(ptr.get() == data);
    }
}