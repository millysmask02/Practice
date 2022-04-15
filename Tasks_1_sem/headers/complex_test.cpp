#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "Complex.h"

Complex add(Complex a, Complex b);
TEST_CASE("add") 
{
    SECTION( "Ex1" ) 
    {
        Complex first = {1, 1};
        Complex second = {2, 2};
        Complex res = {3, 3};
        Complex test = add(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex2" ) 
    {
        Complex first = {0, 0};
        Complex second = {1, 1};
        Complex res = {1, 1};
        Complex test = add(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex3" ) 
    {
        Complex first = {-1, 0};
        Complex second = {1, 0};
        Complex res = {0, 0};
        Complex test = add(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
}


Complex mul(Complex a, Complex b);
TEST_CASE("mul") 
{
    SECTION( "Ex1" ) 
    {
        Complex first = {1, 1};
        Complex second = {2, 2};
        Complex res = {1, 3};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex2" ) 
    {
        Complex first = {0, 0};
        Complex second = {1, 1};
        Complex res = {0, 0};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex3" ) 
    {
        Complex first = {-1, 0};
        Complex second = {1, 0};
        Complex res = {-1, 0};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex4" ) 
    {
        Complex first = {0, 1};
        Complex second = {0, 1};
        Complex res = {-1, 0};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex5" ) 
    {
        Complex first = {-1, 1};
        Complex second = {3, 0};
        Complex res = {-3, 3};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex6" ) 
    {
        Complex first = {-1, 1};
        Complex second = {0, 3};
        Complex res = {-3, -3};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex7" ) 
    {
        Complex first = {3, 1};
        Complex second = {3, -1};
        Complex res = {10, 0};
        Complex test = mul(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
}


Complex div(Complex a, Complex b);
TEST_CASE("div") 
{
    SECTION( "Ex1" ) 
    {
        Complex first = {2, 2};
        Complex second = {1, 1};
        Complex res = {2, 0};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex2" ) 
    {
        Complex first = {2,1};
        Complex second = {0, 1};
        Complex res = {1, -2};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex3" ) 
    {
        Complex first = {0, 5};
        Complex second = {1, 0};
        Complex res = {0, 5};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex4" ) 
    {
        Complex first = {0, 5};
        Complex second = {0, 1};
        Complex res = {5, 0};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex5" ) 
    {
        Complex first = {2, 3};
        Complex second = {1, 2};
        Complex res = {1.6, -0.2};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex6" ) 
    {
        Complex first = {2, 3};
        Complex second = {1, -2};
        Complex res = {-0.8, 1.4};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
    SECTION( "Ex7" ) 
    {
        Complex first = {2, 0};
        Complex second = {0, 1};
        Complex res = {0, -2};
        Complex test = div(first, second);
        REQUIRE(res.x == test.x);
        REQUIRE(res.y == test.y);
    }
}


float mod(Complex a);
TEST_CASE("mod") 
{
    SECTION( "Ex1" ) 
    {
        Complex test1 = {1, 1};
        REQUIRE(mod(test1) == sqrt(2));
        Complex test2 = {0, 2};
        REQUIRE(mod(test2) == 2);
        Complex test3 = {1, 0};
        REQUIRE(mod(test3) == 1);
        Complex test4 = {3, 4};
        REQUIRE(mod(test4) == 5);
        Complex test5 = {-2, 1};
        REQUIRE(mod(test5) == sqrt(5));
        Complex test6 = {0, 0};
        REQUIRE(mod(test6) == 0);
        Complex test7 = {-3, -4};
        REQUIRE(mod(test7) == 5);
    }
}

# define M_PI
float arg(Complex a);
TEST_CASE("arg") 
{
    SECTION( "Ex1" ) 
    {
        Complex test1 = {1, 1};
        REQUIRE(mod(test1) == (float)atan(1));
        Complex test2 = {0, 2};
        REQUIRE(mod(test2) == (float)90);
        Complex test3 = {1, 0};
        REQUIRE(mod(test3) == (float)0);
        Complex test4 = {3, 4};
        REQUIRE(mod(test4) == (float)atan(4/3));
        Complex test5 = {-2, 1};
        REQUIRE(mod(test5) == (float)(M_PI - atan(1/2)));
        Complex test6 = {0, 0};
        REQUIRE(mod(test6) == (float)0);
        Complex test7 = {-3, -4};
        REQUIRE(mod(test7) == (float)(-1 * M_PI + atan(4/3)));
        Complex test8 = {1, -4};
        REQUIRE(mod(test8) == (float)(-1*atan(4)));
        Complex test9 = {-3, 0};
        REQUIRE(mod(test9) == (float)(-M_PI + 0));
        Complex test10 = {0, -1};
        REQUIRE(mod(test10) == (float)(-0.5* M_PI + 0));
    }
}
