#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Header.h"



TEST_CASE("List")
{
    SECTION(" ") {
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

        /*
        std::vector<int> res = { 5, 5, 5 };
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == res[i]);
        }
        REQUIRE(test.size() == 3);
        REQUIRE(test.capacity() == 9);

        MyVector<int> test1 = MyVector<int>(2, 1, ResizeStrategy::Additive, 3);
        std::vector<int> res1 = { 1, 1 };
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1[i] == res1[i]);
        }
        REQUIRE(test1.size() == 2);
        REQUIRE(test1.capacity() == 5);

        std::vector<int> vec_ins = { 5, 1, 1, 5, 5 };
        test.insert(1, test1);
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == vec_ins[i]);
        }

        test.insert(3, 4);
        test.insert(5, 7);
        test.insert(2, 3);
        std::vector<int> ins = { 5, 1, 3, 1, 4, 5, 7, 5 };
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == ins[i]);
        }

        test.erase(4, 2);
        test.pushFront(9);
        std::vector<int> push = { 9, 5, 1, 3, 1, 7, 5 };
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == push[i]);
        }
    }

    SECTION("Constructors") {
        MyVector<int> test(1, ResizeStrategy::Additive, 6);
        REQUIRE(test[0] == 0);
        test.pushBack(1);
        test.pushFront(3);
        MyVector<int> tcopy(test);
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(tcopy[i] == test[i]);
        }

        MyVector<int> tOperCopy = test;
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(tOperCopy[i] == test[i]);
        }

        MyVector<int> vec(std::move(test));
        REQUIRE(test.size() == 0);
        for (int i = 0; i < tOperCopy.size(); i++) {
            REQUIRE(tOperCopy[i] == vec[i]);
        }
    }

    SECTION("size and capacity") {
        MyVector<int> test(3, 5, ResizeStrategy::Additive, 6);
        REQUIRE(test.loadFactor() == 0.333333);

        test.resize(5, 1);
        std::vector<int> vec = { 5,5,5,1,1 };
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(vec[i] == test[i]);
        }

        test.reserve(10);
        REQUIRE(test.capacity() == 10);

        test.clear();
        REQUIRE(test.size() == 0);

        REQUIRE(test[2] == 5);
    }

    SECTION("insert/erase") {
        MyVector<int> test(2, 1, ResizeStrategy::Additive, 10);
        MyVector<int> ins(2, 2, ResizeStrategy::Additive, 4);
        test.insert(0, 4);
        test.insert(3, 5);
        test.insert(3, ins);
        std::vector<int> res = { 4, 1, 1, 2, 2, 5 };
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(res[i] == test[i]);
        }

        test.popBack();
        test.erase(1);
        test.erase(2, 2);
        std::vector<int> vecEr = { 4,1 };
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(vecEr[i] == test[i]);
        }
    */    
    }
}
