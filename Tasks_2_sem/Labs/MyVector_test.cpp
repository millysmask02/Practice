#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "MyVector.h"

TEST_CASE("Vector") 
{
    SECTION(" ") {
        MyVector<int> test = MyVector<int>(3, 5, ResizeStrategy::Additive, 6);
        std::vector<int> res = {5, 5, 5};
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == res[i]);
        }
        REQUIRE(test.size() == 3);
        REQUIRE(test.capacity() == 9);
        
        MyVector<int> test1 = MyVector<int>(2, 1, ResizeStrategy::Additive, 3);
        std::vector<int> res1 = {1, 1};
        for (int i = 0; i < test1.size(); i++) {
            REQUIRE(test1[i] == res1[i]);
        }
        REQUIRE(test1.size() == 2);
        REQUIRE(test1.capacity() == 5);

        std::vector<int> vec_ins = {5, 1, 1, 5, 5};
        test.insert(1, test1);
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == vec_ins[i]);
        }

        test.insert(3, 4);
        test.insert(5, 7);
        test.insert(2, 3);
        std::vector<int> ins = {5, 1, 3, 1, 4, 5, 7, 5};
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == ins[i]);
        }

        test.erase(4, 2);
        test.pushFront(9);
        std::vector<int> push = {9, 5, 1, 3, 1, 7, 5};
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(test[i] == push[i]);
        }
    }

    SECTION("Constructors") {
        MyVector<int> test(1,ResizeStrategy::Additive, 6);
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
        std::vector<int> vec = {5,5,5,1,1};
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
        test.insert(0,4);
        test.insert(3,5);
        test.insert(3,ins);
        std::vector<int> res = {4, 1, 1, 2, 2, 5};
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(res[i] == test[i]);
        }

        test.popBack();
        test.erase(1);
        test.erase(2,2);
        std::vector<int> vecEr = {4,1};
        for (int i = 0; i < test.size(); i++) {
            REQUIRE(vecEr[i] == test[i]);
        }
    }
}