#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"
#include "priority_queue.h"
#include <queue>
TEST_CASE("Priority queue") 
{
    SECTION("Ex1") {
        PriorityQueue<int, std::vector<int>> q;
        q.push(45);
	    q.push(11);
	    q.push(12);
	    q.push(7);
	    q.push(100);
	    q.push(10);
	    q.push(20);
	    q.push(11);
	    q.push(91);
        
        std::priority_queue<int> test;
        test.push(45);
        test.push(11);
        test.push(12);
        test.push(7);
        test.push(100);
        test.push(10);
        test.push(20);
        test.push(11);
        test.push(91);

        REQUIRE(q.empty() == test.empty());
        REQUIRE(q.pop() == test.top());
        test.pop();
        REQUIRE(q.top() == test.top());
        while(!test.empty()) {
		    REQUIRE(q.pop() == test.top());
            test.pop();
	    }
    }
    SECTION("Ex2") {
        PriorityQueue<int, std::vector<int>> q;
        q.push(10);
	    q.push(20);
	    q.push(30);
	    q.push(5);
        
        std::priority_queue<int> test;
        test.push(10);
        test.push(20);
        test.push(30);
        test.push(5);

        REQUIRE(q.empty() == test.empty());
        REQUIRE(q.pop() == test.top());
        test.pop();
        REQUIRE(q.top() == test.top());
        while(!test.empty()) {
		    REQUIRE(q.pop() == test.top());
            test.pop();
	    }
    }
    SECTION("Ex3") {
        PriorityQueue<int, std::vector<int>> q;
        std::priority_queue<int> test;
        REQUIRE(q.empty() == test.empty());
    }
}