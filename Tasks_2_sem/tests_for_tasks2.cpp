//ЗАДАЧИ НА 2 СЕМЕСТР

#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"

/*
Задача 1.
Напишите функцию, которая циклически сдвигает элементы односвязного списка вправо
(A[0] переходит на место A[1],  A[1] на место A[2], ..., последний элемент переходит на место A[0])
Сигнатура: std::list<int> cyclicShift(std::list<int> input);
Example 1:
input: 1 2 3 4 5 6 7
output: 7 1 2 3 4 5 6 
*/

std::list<int> cyclicShift(std::list<int> input);
TEST_CASE("Cyclic Shift") {
    SECTION("Ex1") {
        std::list<int> example1 = {1, 2, 3, 4, 5};
        std::list<int> res = {5, 1, 2, 3, 4};
        REQUIRE(cyclicShift(example1) == res);
    }
    SECTION("Ex2") {
        std::list<int> example1 = {1, 2};
        std::list<int> res = {2,1};
        REQUIRE(cyclicShift(example1) == res);
    }
    SECTION("Ex3") {
        std::list<int> example1 = {2};
        std::list<int> res = {2};
        REQUIRE(cyclicShift(example1) == res);
    }
    SECTION("Ex4") {
        std::list<int> example1 = {};
        std::list<int> res = {};
        REQUIRE(cyclicShift(example1) == res);
    }
}


/*
Задача 2.
В функцию подается название файла input.txt, в котором записан текст на английском.
Реализовать функцию, которая сделает словарь из всех имеющихся слов и отсортирует его по популярности.
Сигнатура: std::map<std::string, int> popularWord(std::string file);
input.txt:
apple
my apple,
my red apple

output:
apple 3
my 2
red 1
*/

std::map<std::string, int> popularWord(std::string file);
TEST_CASE("")
{ 
    std::map<std::string, int> res = {{"apple", 3}, {"my", 2}, {"red", 1}};
    REQUIRE(popularWord("input.txt") == res);
}


/*
Задача 3.
Даны два отсортированных вектора целых чисел. 
Написать функцию, которая объединяет их в один отсортированный вектор. Реализовать за O(n).
Сигнатура: std::vector<int> sumVect(std::vector<int> vec_f, std::vector<int> vec_s);
Example:
input: 
-5 -1 4 6
-6 -3 0 1 5 8
output:
-6 -5 -3 -1 0 1 4 5 6 8
*/

std::vector<int> sumVect(std::vector<int> vec_f, std::vector<int> vec_s);
TEST_CASE(" ") {
    SECTION("Ex1") {
        std::vector<int> ex_f = {-5, -1, 4, 6};
        std::vector<int> ex_s = {-6, -3, 0, 1, 5, 8};
        std::vector<int> res = {-6, -5, -3, -1, 0, 1, 4, 5, 6, 8};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex2") {
        std::vector<int> ex_f = {-1, 0, 1, 2};
        std::vector<int> ex_s = {3, 5, 8};
        std::vector<int> res = {-1, 0, 1, 2, 3, 5, 8};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex3") {
        std::vector<int> ex_f = {-1, 0, 1};
        std::vector<int> ex_s = {1, 3, 5};
        std::vector<int> res = {-1, 0, 1, 1, 3, 5};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex4") {
        std::vector<int> ex_f = {-1, 0, 2};
        std::vector<int> ex_s = {-4, 1, 3, 5};
        std::vector<int> res = {-4, -1, 0, 1, 2, 3, 5};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex5") {
        std::vector<int> ex_f = {-1};
        std::vector<int> ex_s = {1};
        std::vector<int> res = {-1, 1};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex6") {
        std::vector<int> ex_f = {-1, 0, 2};
        std::vector<int> ex_s = {};
        std::vector<int> res = {-1, 0, 2};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex7") {
        std::vector<int> ex_f = {};
        std::vector<int> ex_s = {-1, 0, 2};
        std::vector<int> res = {-1, 0, 2};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex8") {
        std::vector<int> ex_f = {1};
        std::vector<int> ex_s = {1};
        std::vector<int> res = {1, 1};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex9") {
        std::vector<int> ex_f = {1, 2, 3};
        std::vector<int> ex_s = {-10, -5, -2, 0};
        std::vector<int> res = {-10, -5, -2, 0, 1, 2, 3};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
    SECTION("Ex10") {
        std::vector<int> ex_f = {1, 2, 3};
        std::vector<int> ex_s = {-2, 0, 1};
        std::vector<int> res = {-2, 0, 1, 1, 2, 3};
        REQUIRE(sumVect(ex_f, ex_s) == res);
    }
}


/*
Задача 4.
Даны два отсортированных по убыванию стека. Написать функцию,
которая объединяет стеки в один с порядком по возрастанию.
Сигнатура: std::stack<int> sorted(std::stack<int> first, std::stack<int> second);
Example:
input: 
8, 4, 2, -5
5, 2, -1
output:
-5, -1, 2, 2, 4, 5, 8
*/

std::stack<int> sorted(std::stack<int> first, std::stack<int> second);
TEST_CASE(" ") {
    SECTION("Ex1") {
        std::stack<int> ex_f;
        ex_f.push(5);
        ex_f.push(-1);
        std::stack<int> ex_s;
        ex_s.push(6);
        ex_s.push(0);
        ex_s.push(-5);
        std::stack<int> test;
        test.push(-5);
        test.push(-1);
        test.push(0);
        test.push(5);
        test.push(6);
        std::stack<int> res = sorted(ex_f, ex_s);
        while(!test.empty()) {
            REQUIRE(test.top() == res.top());
            test.pop();
            res.pop();
        }
    }
    SECTION("Ex2") {
        std::stack<int> ex_f;
        ex_f.push(5);
        std::stack<int> ex_s;
        ex_s.push(0);
        std::stack<int> test;
        test.push(0);
        test.push(5);
        std::stack<int> res = sorted(ex_f, ex_s);
        while(!test.empty()) {
            REQUIRE(test.top() == res.top());
            test.pop();
            res.pop();
        }
    }
    SECTION("Ex3") {
        std::stack<int> ex_f;
        ex_f.push(5);
        ex_f.push(-1);
        std::stack<int> ex_s;
        ex_s.push(0);
        std::stack<int> test;
        test.push(-1);
        test.push(0);
        test.push(5);
        std::stack<int> res = sorted(ex_f, ex_s);
        while(!test.empty()) {
            REQUIRE(test.top() == res.top());
            test.pop();
            res.pop();
        }
    }
    SECTION("Ex4") {
        std::stack<int> ex_f;
        std::stack<int> ex_s;
        std::stack<int> res = sorted(ex_f, ex_s);
        REQUIRE(res.empty() == 1);
    }
}


/*
Задача 5.
Напишите функцию, которая разворачивает вектор целых чисел.
Сигнатура: std::vector<int> reverseVec(std::vector<int> vec);
Example:
input: 1 2 3 4 5
output: 5 4 3 2 1
*/

std::vector<int> reverseVec(std::vector<int> vec);
TEST_CASE("")
{
    SECTION("ex1") 
    {
        std::vector<int> input = {-1, 1, 4, 5};
        std::vector<int> res = reverseVec(input);
        std::reverse(input.begin(), input.end());
        for(int i = 0; i < input.size(); ++i)
            REQUIRE(input[i] == res[i]);
    }
    SECTION("ex2") 
    {
        std::vector<int> input = {-1, 1};
        std::vector<int> res = reverseVec(input);
        std::reverse(input.begin(), input.end());
        for(int i = 0; i < input.size(); ++i)
            REQUIRE(input[i] == res[i]);
    }
    SECTION("ex3") 
    {
        std::vector<int> input = {1};
        std::vector<int> res = reverseVec(input);
        std::reverse(input.begin(), input.end());   
        for(int i = 0; i < input.size(); ++i)
            REQUIRE(input[i] == res[i]);
    }
    SECTION("ex4") 
    {
        std::vector<int> input = {};
        std::vector<int> res = reverseVec(input);
        REQUIRE(res.empty() == 1);
    }
}


/*
Задача 6.
Напишите программу, которая объединяет два упорядоченных по возрастанию
массива в один (тоже упорядоченный) массив.
Сигнатура: int* sortedArray(int* one, int* two);
Example:
input:
-2 1 4
-3 -2 0
output:
-3 -2 -2 1 0 4
*/

int* sortedArray(int* one, int* two);
TEST_CASE("sum two mus") 
{   
    SECTION("Ex1") {
        int ex_f[4] = {-5, -1, 4, 6};
        int ex_s[6] = {-6, -3, 0, 1, 5, 8};
        int res[10] = {-6, -5, -3, -1, 0, 1, 4, 5, 6, 8};
        int* test = sortedArray(ex_f, ex_s);
        for (int i = 0; i < 10; ++i)
            REQUIRE(res[i] == test[i]);
    }
    SECTION("Ex2") {
        int ex_f[1] = {-1};
        int ex_s[1] = {1};
        int res[2] = {-1, 1};
        int* test = sortedArray(ex_f, ex_s);
        for (int i = 0; i < 2; ++i)
            REQUIRE(res[i] == test[i]);
    }

    SECTION("Ex3") {
        int ex_f[4] = {-1, 0, 1, 2};
        int ex_s[3] = {3, 5, 8};
        int res[7] = {-1, 0, 1, 2, 3, 5, 8};
        int* test = sortedArray(ex_f, ex_s);
        for (int i = 0; i < 7; ++i)
            REQUIRE(res[i] == test[i]);
    }
    SECTION("Ex4") {
        int ex_f[3] = {-1, 0, 1};
        int ex_s[3] = {1, 3, 5};
        int res[6] = {-1, 0, 1, 1, 3, 5};
        int* test = sortedArray(ex_f, ex_s);
        for (int i = 0; i < 6; ++i)
            REQUIRE(res[i] == test[i]);
    }  
} 


/*
Задача 7. 
На вход подается отсортированный по возрастанию вектор целых чисел. 
Напишите функцию, которая возращает отсортированный по возрастанию вектор квадратов значений данного вектора.
Example:
input:
-4, -1, 0, 1, 2, 4, 6
output:
0, 1, 1, 2, 16, 16, 36
*/

std::vector<int> sqrtVec(std::vector<int> input);
TEST_CASE("vector sqrt") 
{
    SECTION("Ex1") {
        std::vector<int> input = {-1, 1, 4, 5};
        std::vector<int> res = {1, 1, 16, 25};
        std::vector<int> test = sqrtVec(input);
        for (int i = 0; i < res.size(); ++i)
            REQUIRE(res[i] == test[i]);
    }
    SECTION("Ex2") {
        std::vector<int> input = {-8, -6, -4, 0, 1, 3, 4, 6};
        std::vector<int> res = {0, 1, 9, 16, 16, 36, 36, 64};
        std::vector<int> test = sqrtVec(input);
        for (int i = 0; i < res.size(); ++i)
            REQUIRE(res[i] == test[i]);
    }
    SECTION("Ex3") {
        std::vector<int> input = {-5, -3, -1 , 0};
        std::vector<int> res = {0, 1, 9, 25};
        std::vector<int> test = sqrtVec(input);
        for (int i = 0; i < res.size(); ++i)
            REQUIRE(res[i] == test[i]);
    }
    SECTION("Ex4") {
        std::vector<int> input = {0, 1, 2, 4, 5, 7};
        std::vector<int> res = {0, 1, 4, 16, 25, 49};
        std::vector<int> test = sqrtVec(input);
        for (int i = 0; i < res.size(); ++i)
            REQUIRE(res[i] == test[i]);
    }
    SECTION("Ex5") {
        std::vector<int> input = {};
        std::vector<int> test = sqrtVec(input);
        REQUIRE(test.size() == 0);
    }
}


/*
Задача 8. 
Напишите программу, реализующую игру "Угадай число". 
Компьютер загадывает число от 0 до 999 (используйте генерацию случайных чисел). 
На каждом шаге пользователь делает предположение, а компьютер сообщает, 
является ли это число больше, меньше или равно загаданному. 
Когда пользователь отгадывает задуманное число, игра заканчивается.
*/

/*
Задача 9.
Напишите программу, которая содержит текущую информацию о 10 заявках на авиабилеты. 
Каждая заявка имеет: 
* пункт назначения
* номер рейса 
* ФИО пассажира 
* желаемую дату вылета.
Программа должна обеспечивать: 
1. хранение всех заявок в виде списка
2. добавление заявок
3. удаление заявок
4. вывод всех заявок.
*/

/*
Задача 10.
Напишите программу учета оценок студентов. 
Для этого создайте текстовый файл с именем input.txt, содержащий список 
из 10 студентов и их оценки по 3 предметам: математика, физика и информатика. 
Содержимое файла: в первой строке находится общее число студентов, 
в каждой следующей находится ФИО студента и три целых числа(оценки). Данные в строке отделяются пробелами. 
Создайте класс, с помощью которого вы будете считывать данные из файла.
На экран выведите ФИО студентов с оценкаи в порядке убывания их среднего балла. 
*/

/*
Задача 11.
Создайте класс с именем Student, содержащую слудующие поля: 
Name, 
Year, 
Rating (успеваемость, массив из пяти элементов).
Функции  класса: 
* ввод данных в массив Rating, 
* вывод в консоль записи, 
* вывод среднего балла
*/

/*
Задача 12.
Создайте класс Деньги для работы с денежными суммами. 
Число должно быть представлено двумя полями: 
типа long для рублей и типа unsigned char - для копеек. 
Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой. 
Реализовать:
1. сложение
2. вычитание
3. деление сумм
4. деление суммы на дробное число, 
5. умножение на дробное число
6. операции сравнения. 
В функции main проверить эти методы.
*/

/*
Задача 13.
Разработать три класса, которые следует связать между собой, используя наследование:
* класс Product, который имеет три элемент-данных — имя, цена и вес товара (базовый класс для всех классов);
* класс Buy, содержащий данные о количестве покупаемого товара в штуках, 
  о цене за весь купленный товар и о весе товара (производный класс для класса 
  Product и базовый класс для класса Check);
* класс Check, не содержащий никаких элемент-данных. 
  Данный класс должен выводить на экран информацию о товаре и о покупке ( производный класс для класса Buy);
Для взаимодействия с данными классов разработать set- и get—методы. 
Все элемент-данные классов объявлять как private.
*/

/* 
Задача 14.
Дана последовательность целых чисел, заканчивающаяся числом 0. 
Выведите эту последовательность в обратном порядке.
При решении этой задачи нельзя пользоваться массивами и прочими динамическими
структурами данных. Рекурсия вам поможет.
*/

/*
Задача 15.
Реализовать класс матрицы целых чисел. Размерность матриц не ограничена. Класс должен:
* считывать элементы матрицы из файла формата csv;
* реализовывать конструкторы копирования и перемещения (если необходимо);
* реализовывать операторы копирующего и перемещающего присваивания (если необходимо);
* реализовывать операторы сложения, вычитания, умножения матриц;
* обрабатывать ошибки с использованием исключений
*/