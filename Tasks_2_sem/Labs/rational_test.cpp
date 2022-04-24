#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "Rational.h"

TEST_CASE("") 
{
    SECTION("1") {
        Rational x(1,2);
        Rational y(-1,2);
        x.neg();
        REQUIRE((x == y) == 1);
        x.neg();
        REQUIRE((x != y) == 1);
        Rational z(2);
        x.inv();
        REQUIRE((x == z) == 1);
        z.neg();
        y.inv();
        REQUIRE((y == z) == 1);
    }
    SECTION("2") {
        Rational x(2,4);
        Rational y(1,2);
        x.reduce();
        REQUIRE(x == y);
    }
    SECTION("3") {
        Rational x(2,3);
        Rational y(1,4);
        Rational sum(11,12);
        REQUIRE((x + y) == sum);
        Rational sub1(5,12);
        REQUIRE((x - y) == sub1);
        Rational sub2(-5,12);
        REQUIRE((y - x) == sub2);
        Rational mul(1,6);
        REQUIRE((x * y) == mul);
        Rational div1(8,3);
        REQUIRE((x / y) == div1);
        Rational div2(3,8);
        REQUIRE((y / x) == div2);
    }
    SECTION("4") {
        Rational x(1,4);
        Rational y(1,5);
        REQUIRE((x == y) == 0);
        REQUIRE((x != y) == 1);
        REQUIRE((x > y) == 1);
        REQUIRE((x < y) == 0);
        REQUIRE((x >= y) == 1);
        REQUIRE((x <= y) == 0);
        Rational z(2,8);
        z.reduce();
        REQUIRE((x == z) == 1);
        REQUIRE((x != z) == 0);
        REQUIRE((x > z) == 0);
        REQUIRE((x < z) == 0);
        REQUIRE((x >= z) == 1);
        REQUIRE((x <= z) == 1);
    }
    SECTION("5") {
        Rational n(10,5);
        n.reduce();
        Rational m(2);
        REQUIRE((n == m) == 1);
        Rational x(5,5);
        x.reduce();
        Rational y;
        REQUIRE((x == y) == 1);
    }
}

