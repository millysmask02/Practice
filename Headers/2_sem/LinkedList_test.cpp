#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Header.h"

void add5(double& a) {
    a = a + 5;
}

bool moreThen8(double a) {
    return a > 8;
}

double add5(double a) {
    return a + 5;
}

TEST_CASE("List")
{
    SECTION("Default functions") {
        LinkedList test1 = LinkedList();
        test1.insert(0, 1);
        test1.insert(1, 2);
        test1.insert(2, 3);
        test1.insert(3, 4);
        test1.insert(4, 5);

        LinkedList test2 = LinkedList();
        test2.pushBack(1);
        test2.pushBack(2);
        test2.pushBack(3);
        test2.pushBack(4);
        test2.pushBack(5);

        LinkedList test3 = LinkedList();
        test3.pushFront(5);
        test3.pushFront(4);
        test3.pushFront(3);
        test3.pushFront(2);
        test3.pushFront(1);

        REQUIRE(test1.size() == 5);
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1.getNode(i)->_value == test2.getNode(i)->_value);
            REQUIRE(test2[i] == test3[i]);
        }

        test1.remove(0);
        test1.remove(3);
        test2.removeFront();
        test2.removeBack();
        REQUIRE(test1.size() == 3);

        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1[i] == test2[i]);
        }

        LinkedList test4 = LinkedList(test1);
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test4[i] == test2[i]);
        }

        test1 = test4;
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1[i] == test2[i]);
        }

        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test3.findIndex(i) == i - 1);
            REQUIRE(test3.getNode(i) == test3.findNode(i + 1));
        }
    }

    SECTION("Advanced functions") {
        LinkedList test1 = LinkedList();
        test1.insert(0, 1);
        test1.insert(1, 2);
        test1.insert(2, 3);
        test1.insert(3, 4);
        test1.insert(4, 5);

        LinkedList test2 = LinkedList();
        test2.insert(0, 5);
        test2.insert(1, 4);
        test2.insert(2, 3);
        test2.insert(3, 2);
        test2.insert(4, 1);

        test2.reverse();
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1[i] == test2[i]);
        }

        LinkedList test3 = test2.getReverseList();
        LinkedList test4 = test3.getReverseList();
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test2[i] == test4[i]);
        }

        REQUIRE(test4.begin() == test4.getNode(0));
        REQUIRE(test4.end() == nullptr);

    }

    SECTION("Special functions") {
        LinkedList test1 = LinkedList();
        test1.insert(0, 1);
        test1.insert(1, 2);
        test1.insert(2, 3);
        test1.insert(3, 4);
        test1.insert(4, 5);

        LinkedList test2 = LinkedList();
        test2.insert(0, 1);
        test2.insert(1, 2);
        test2.insert(2, 3);
        test2.insert(3, 4);
        test2.insert(4, 5);
        test2.map(add5);

        test1.forEach(add5);
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1[i] == i + 6);
            REQUIRE(test2[i] == i + 6);
        }

        test1.filter(moreThen8);
        REQUIRE(test1.size() == 2);
        REQUIRE(test1[0] == 9);
        REQUIRE(test1[1] == 10);        
    }
}