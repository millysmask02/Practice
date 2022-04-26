//ЗАДАЧИ НА 3 СЕМЕСТР\\

#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"

/*
Задача 1.
Дана строка вида (){}[]{}{})(){)))
Необходимо проверить, что:
1. Для каждой открывающей скобки есть соответственная закрывающая;
2. Не возникает ситуаций вида ( { ) } — скобки закрываются "не там".
Если условия не выполнены, вывести, по какому индексу в строке произошла ошибка.
Реализовать с помощью std::stack.
Напишите функцию balance, которая проверяет выполнение баланса скобок. 
Функция принимает строку, возращает std::pair<int, int>. 
Если баланс выполняется,  на первое место записывается 1, на второе -1. 
Если не выполняется, на первое записывается 0, на второе - индекс, где произошла ошибка.
Примечание: в строке могут быть другие символы.
Example 1:
input: 
(){}([])
output:
1 -1
Example 2:
input: 
([{aaa})]
output:
0 7
*/

std::pair<int,int> balance(std::string str);
TEST_CASE("Balance") 
{
    SECTION("ex1") {
        std::pair<int,int> test(1,-1);
        std::pair<int,int> res = balance("(){}([])");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex2") {
        std::pair<int,int> test(0,7);
        std::pair<int,int> res = balance("([{aaa})]");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex3") {
        std::pair<int,int> test(1,-1);
        std::pair<int,int> res = balance("{()[][()]}");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex4") {
        std::pair<int,int> test(0,4);
        std::pair<int,int> res = balance("([])(");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex5") {
        std::pair<int,int> test(0,0);
        std::pair<int,int> res = balance(")([]");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex6") {
        std::pair<int,int> test(0,0);
        std::pair<int,int> res = balance(")");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex7") {
        std::pair<int,int> test(0,0);
        std::pair<int,int> res = balance("{");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex8") {
        std::pair<int,int> test(1,-1);
        std::pair<int,int> res = balance("()");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex9") {
        std::pair<int,int> test(1,-1);
        std::pair<int,int> res = balance("");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
    SECTION("ex10") {
        std::pair<int,int> test(0,6);
        std::pair<int,int> res = balance("()([[])]");
        REQUIRE(test.first == res.first);
        REQUIRE(test.second == res.second);
    }
}


/*
Задача 2.
В функцию numberOfSequences подаются две строки - названия входного и выходного файла.
В единственной строке входного файла находится последовательность, 
содержащая произвольную комбинацию 0 и 1, разделенных пробелом.
Записать во второй файл (выходной) два числа - количество последовательностей из 1 и 0. 
Примечание: использовать unique(), count().
Примечание 2: данные в выходном файле перезаписываются. 
Example 1:
input: 
1 0 1 1
output:
2 1
Example 2:
input: 
0 0 0 
output:
0 1
*/

void numberOfSequences(std::string input, std::string output);
TEST_CASE("") 
{
    SECTION("1") {
        //input.txt 1 0 1 1
        numberOfSequences("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 2);
        file >> n;
        REQUIRE(n == 1);
        file.close();
    }
    SECTION("2") {
        //input.txt 0 0 0
        numberOfSequences("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 0);
        file >> n;
        REQUIRE(n == 1);
        file.close();
    }
    SECTION("3") {
        //input.txt 1 0 1 1 0 0 1
        numberOfSequences("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 3);
        file >> n;
        REQUIRE(n == 2);
        file.close();
    }
    SECTION("4") {
        //input.txt 0 1 0 1 0
        numberOfSequences("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 2);
        file >> n;
        REQUIRE(n == 3);
        file.close();
    }
    SECTION("5") {
        //input.txt 1 1
        numberOfSequences("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 1);
        file >> n;
        REQUIRE(n == 0);
        file.close();
    }
    SECTION("6") {
        //input.txt (empty)
        numberOfSequences("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 0);
        file >> n;
        REQUIRE(n == 0);
        file.close();
    }
}


/*
Задача 3.
В функцию playingCards подаются две строки - названия входного и выходного файла.
Первая строка входного файла содержит одно четное натуральное число N. 
Вторая строка входного файла содержит ровно N чисел - числа, написанные на игральных карточках. 
Все числа в строке разделяются одиночными пробелами. Игроки выбирают закрытые карточки, 
первый выбирает половину карточек, второй забирает оставшуюся половину. 
Во второй файл записать максимальный выигрыш, который можно получить, т.е разница между суммами чисел на карточках. 
Примечание: используйте sort()/partial_sort(), reverve(), accumulate(), std::greater
Example 1:
input: 
2
1 3
output:
2
Example 2:
input: 
4
3 1 8 100  
output:
104
*/

void playingCards(std::string input, std::string output);
TEST_CASE("playing Cards") 
{
    SECTION("1") {
        //input.txt 
        //2
        //1 3
        playingCards("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 2);
        file.close();
    }
    SECTION("2") {
        //input.txt 
        //4
        //3 1 8 100
        playingCards("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 104);
        file.close();
    }
    SECTION("3") {
        //input.txt 
        //6
        //5 10 8 9 19 14
        playingCards("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 21);
        file.close();
    }
    SECTION("4") {
        //input.txt 
        //4
        //2 2 2 2
        playingCards("input.txt", "output.txt");
        int n;
        std::ifstream file("output.txt");
        file >> n;
        REQUIRE(n == 0);
        file.close();
    }
}


/*
Задача 4.
Напишите функцию deleteElement, которая исключит из вектора первый четный элемент, следующий за максимальным. 
На вход подается вектор целых чисел. 
На выход - напечатать позицию элемента и его значение, вернуть массив после удаления элемента. 
Примечание: resize(), copy() и ofstream_iterator (для вывода вектора), max_element(), 
find_if с лямбда-функцией для определение четности число ([](тип значение) {код}), distance(), erase().
*/

std::vector<int> deleteElement(std::vector<int> input);
TEST_CASE(" ")
{
    SECTION("1") {
        std::vector<int> input = {1, 5, 6, 8, -1, 4};
        std::vector<int> res = {1, 5, 6, 8, -1};
        std::vector<int> test = deleteElement(input);
        for (int i = 0; i < res.size(); i++) {
            REQUIRE(res[i] == test[i]);
        }
    }
    SECTION("2") {
        std::vector<int> input = {8, 1, 2, 3};
        std::vector<int> res = {8, 1, 3};
        std::vector<int> test = deleteElement(input);
        for (int i = 0; i < res.size(); i++) {
            REQUIRE(res[i] == test[i]);
        }
    }
    SECTION("4") {
        std::vector<int> input = {1, 2, 3, 4};
        std::vector<int> res = {1, 2, 3, 4};
        std::vector<int> test = deleteElement(input);
        for (int i = 0; i < res.size(); i++) {
            REQUIRE(res[i] == test[i]);
        }
    }
    SECTION("5") {
        std::vector<int> input = {1, 4, 3, -1};
        std::vector<int> res = {1, 4, 3, -1};
        std::vector<int> test = deleteElement(input);
        for (int i = 0; i < res.size(); i++) {
            REQUIRE(res[i] == test[i]);
        }
    }
}


/*
Задача 5.
Даны 12 csv-файлов с логинами и их зашифрованными через радуждные таблицы версиями. 
Пользователь вводит зашифрованный логин, необходимо найти в файлах его оригинал.
*/


/*
Задача 6.
Разработать шаблонный класс Pair, хранящий пару значений разных типов. Класс должен:
● реализовывать методы для доступа к значениям и задания значений;
● реализовывать операторы сравнения (==, !=);
● реализовывать оператор сложения, складывающий соответствующие элементы пары;
● реализовывать оператор выставки в поток (<<), выводящий в консоль пару в виде “(first, second)”; 
● реализовать оператор извлечения из потока (>>), принимающий два значения из консоли и заполняющий ими пару строк;
● метод, принимающий два значения и возвращающий составленную из них пару;
● метод, принимающий пару и возвращающий пару, в которой первое значение поставлено
  на место второго, второе – на место первого 
*/

//добавить задачки на stl