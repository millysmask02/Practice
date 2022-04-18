#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "Figure.h"

TEST_CASE("Figure")
{
    SECTION("Triangle")
    {
        Triangle *t = new Triangle(1, 1, 1);
        REQUIRE(t->getName() == std::string("Triangle"));
        REQUIRE(t->calculateP() == 3);
        REQUIRE(t->calculateS() == 0.433013);
    }

    SECTION("RTriangle")
    {
        RTriangle *rt = new RTriangle(1, 1);
        REQUIRE(rt->getName() == std::string("RTriangle"));
        REQUIRE(rt->calculateP() == 3.41421 );
        REQUIRE(rt->calculateS() == 0.5);
    }

    SECTION("ITriangle")
    {
        ITriangle *it = new ITriangle(1, 1);
        REQUIRE(it->getName() == std::string("ITriangle"));
        REQUIRE(it->calculateP() == 3 );
        REQUIRE(it->calculateS() == 0.433013);
    }

    SECTION("ETriangle")
    {
        ETriangle *et = new ETriangle(1);
        REQUIRE(et->getName() == std::string("ETriangle"));
        REQUIRE(et->calculateP() == 3 );
        REQUIRE(et->calculateS() == 0.433013);
    }

    SECTION("Parallelogram")
    {
        Parallelogram *p = new Parallelogram(1, 2, 30);
        REQUIRE(p->getName() == std::string("Parallelogram"));
        REQUIRE(p->calculateP() == 6);
        REQUIRE(p->calculateS() == 1);
    }

    SECTION("Rectangle")
    {
        Rectangle *r = new Rectangle(5, 4);
        REQUIRE(r->getName() == std::string("Rectangle"));
        REQUIRE(r->calculateP() == 18);
        REQUIRE(r->calculateS() == 20);
    }

    SECTION("Square")
    {
        Square *s = new Square(5);
        REQUIRE(s->getName() == std::string("Square"));
        REQUIRE(s->calculateP() == 20);
        REQUIRE(s->calculateS() == 25);
    }

    SECTION("Ellipse")
    {
        Ellipse *e = new Ellipse(3, 1);
        REQUIRE(e->getName() == std::string("Ellipse"));
        REQUIRE(e->calculateP() == 13.4248);
        REQUIRE(e->calculateS() == 9.42478);
    }

    SECTION("Circle")
    {
        Circle *c = new Circle(5);
        REQUIRE(c->getName() == std::string("Circle"));
        REQUIRE(c->calculateP() == 31.4159);
        REQUIRE(c->calculateS() == 78.5398);
    }
}