//ЗАДАЧИ НА 1 СЕМЕСТР\\ 

#define CATCH_CONFIG_MAIN
#include "catch2\catch.hpp"

/*
Задача 1. 
tags: С, сложность F, 1 семестр, простые операторы, циклы
В функцию подается натуральное число. Вывести произведение его нечетных цифр.
Сигнатура: int multiplyOdd(int n);
Примечание: если нечетных нет, вывести 0.
Example 1:
input: 456789
output: 315
Example 2:
input: 123
output: 3
*/

int multiplyOdd(int n);
TEST_CASE("the product of odd digits")
{
    REQUIRE( multiplyOdd(1) == 1 );
    REQUIRE( multiplyOdd(456789) == 315 );
    REQUIRE( multiplyOdd(123) == 3 );
    REQUIRE( multiplyOdd(0) == 0 );
    REQUIRE( multiplyOdd(246) == 0 );
}


/*
Задача 2. 
tags: C, сложность F, 1 семестр, условные операторы
В функцию подаются три целых неотрицательных числа. Определить, может ли существовать треугольник с такими
сторонами, и если да, то какой он? 
Вывод: 0 - не существует, 1 - разносторонний, 2 - равнобедренный, 3 - равносторонний, 4 - прямоугольный
Сигнатура: int triangle(int a, int b, int c);
Example 1:
input: 3 4 5
output: 4
Example 2:
input: 2 4 10
output: 0
*/

int triangle(int a, int b, int c);
TEST_CASE( "type of triangle" ) 
{
    REQUIRE( triangle(3,4,5) == 4 );
    REQUIRE( triangle(2,4,10) == 0 );
    REQUIRE( triangle(2,2,1) == 2 );
    REQUIRE( triangle(0,0,0) == 0 );
    REQUIRE( triangle(3,3,3) == 3 );
    REQUIRE( triangle(2,3,4) == 1 );
}


/*
Задача 3. (+) (+)
tags: C, сложность E , 1 семестр, функции, циклы
Напишите функции по вычислению факториала и нахождению n-ого элемента ряда Фибоначчи. 
n - целое неотрицательное число.
Сигнатура: 
int Factorial(int number) 
int Fibonacci(int number)
Example 1: Факториал
input: 3
output: 6
Example 1: Фибоначчи
input: 3
output: 2
*/

int Factorial(int number);
int Fibonacci(int number);

TEST_CASE( "Factorials are computed") {
    REQUIRE( Factorial(0) == 1 );
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE( "Fibonacci are computed") {
    REQUIRE( Fibonacci(1) == 1 );
    REQUIRE( Fibonacci(2) == 1 );
    REQUIRE( Fibonacci(3) == 2 );
    REQUIRE( Fibonacci(10) == 55 );
    REQUIRE( Fibonacci(20) == 6765 );
}


/*
Задача 4. 
tags: С, сложность F, 1 семестр, массивы, циклы
Напишите функцию, которая считает сумму нечетных элементов массива.
В функцию подается массив целых чисел и количество элементов в массиве.
Сигнатура: int sumOdd(int mus[], int number);
Example 1:
input: 1 2 3 4 5 6
output: 9
Example 2:
input: 0 1 -1 5 6
output: 5
*/

int sumOdd(int* array, int number);
TEST_CASE( "Sum odd" )
{
    int m[6] = {-1, 0, 1, -2, -4, 5};
    REQUIRE(sumOdd(m, 6) == 5);

    int mus[1] = {1};
    REQUIRE(sumOdd(mus, 1) == 1);

    int array[1] = {2};
    REQUIRE(sumOdd(array, 1) == 0);

    int null_mus[1];
    REQUIRE(sumOdd(null_mus, 1) == 0);
}


/*
Задача 5. 
tags: C, сложность E, 1 семестр, циклы, массивы
Напишите функцию, которая считает произведение двух матриц.
Примечание: размер первой матрицы - M x N, второй - N x M.
Сигнатура: int** mulMatrix(int** matr_f, int** matr_s, int m, int n);
Example:
Input: 
matrix_1
1 4
2 0 
2 3

matrix_2
0 1 2
0 4 3

N = 2 
M = 3

output: 
16 7
16 9
*/

int** mulMatrix(int** matr_f, int** matr_s, int m, int n);
TEST_CASE( "Mul matrix" )
{
    int mf[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mf[i][j] = i + j;
        }
    }

    int ms[3][3] = {
        {2, 4, 6},
        {7, 3, 5},
        {3, 8, 12}
    };

    int mrt[3][3] = {
        {13, 19, 29},
        {37, 49, 75},
        {61, 79, 121}
    };

    int** mr = mulMatrix((int**)mf, (int**)ms, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            REQUIRE(mrt[i][j] == mr[i][j]);
        }
    }
}


/*
Задача 6.
tags: С, сложность F, 1 семестр, циклы, массивы
Написать функцию, которая считает определитель матрицы 3х3. 
Сигнатура: int detMatrix(int** matr);
Example:
input:  
1 2 0
4 3 -1
-2 0 4
output: -16
*/

int detMatrix(int** matr);
TEST_CASE( "Det matrix" ) 
{   
    SECTION("Ex1") 
    { 
        int m[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = i + j;
            }
        }
        REQUIRE(detMatrix((int**)m)  == 0);
    }

    SECTION("Ex2") 
    {
        int m[3][3] = {
            {2, 4, 6},
            {7, 3, 5},
            {3, 8, 12}
        };
        REQUIRE(detMatrix((int**)m)  == -2);
    }
}

/*
Задача 7.
tags: C, сложность F, циклы, строки, условные операторы
Напишите функцию, которая из строки, состоящую из разных символов, берет цифры и переходит
их в соответствующее число. Если в строке нет цифр, вернуть -1.
Сигнатура: int strToInt(char* str);
Example:
input: "1jdj-5kd%7"
output: 157
*/

int strToInt(char* str);
TEST_CASE( "Str to int" ) 
{    
    REQUIRE(strToInt("ss1df3sd5df")  == 135);
    REQUIRE(strToInt("1&2(3")  == 123);
    REQUIRE(strToInt("ssds*&js")  == -1);
}


/*
Задача 8. 
tags: C, сложность F, циклы
Напишите функцию, которая натуральное число n раскладывает в произведение простых множителей.
Множители выводятся в порядке неубывания через знак *.
Сигнатура: char* pastMult(int n);
Example:
input: 60
output: 2*2*3*5
*/

char* pastMult(int n);
TEST_CASE( "Past Mult" ) 
{    
    REQUIRE(std::string(pastMult(60))  == std::string("2*2*3*5"));
    REQUIRE(std::string(pastMult(1))  == std::string("1"));
    REQUIRE(std::string(pastMult(17))  == std::string("17"));
}


/*
Задача 9.
tags: С, сложность F, 1 семестр, циклы, простые операторы
Напишите функцию, которая целое неотрицательное число n переводит в восьмиричную систему счисления.
Сигнатура: int numbToEight(int n);
Example:
input: 127
output: 177
*/

int numbToEight(int n);
TEST_CASE( "Number to 8-system" ) 
{    
    REQUIRE(numbToEight(127)  == 177);
    REQUIRE(numbToEight(0)  == 0);
    REQUIRE(numbToEight(8)  == 10);
    REQUIRE(numbToEight(7)  == 7);
}


/*
Задача 10. 
tags: C, сложнось F, 1 семестр, циклы, строки
Написать функцию, которая переводит строку в верхний регистр.
Сигнатура: char* toUpper(char* str);
Example:
input: abcd
output: ABCD
*/

char* toUpper(char* str);
TEST_CASE( "Str to Upper" ) 
{    
    REQUIRE(std::string(toUpper("1abc2"))  == std::string("1ABC2"));
    REQUIRE(std::string(toUpper("123"))  == std::string("123"));
    REQUIRE(std::string(toUpper(""))  == std::string(""));
    REQUIRE(std::string(toUpper("aDc!21cA"))  == std::string("ADC!21CA"));
}


/*
Задача 11. 
tags: С, сложность F, 1 семестр, условные операторы
Написать функцию, которая определяет, в какой четверти расположена точка (x,y).
Если точка лежит на координатной оси, вывести 0.
Сигнатура: int wherePoint(int x, int y);
Example:
input: 3 -2
output: 4
*/

int wherePoint(int x, int y);
TEST_CASE( "Where is point?" ) 
{    
    REQUIRE(wherePoint(3, -2)  == 4);
    REQUIRE(wherePoint(0,0)  == 0);
    REQUIRE(wherePoint(1,1)  == 1);
    REQUIRE(wherePoint(-2,1)  == 2);
    REQUIRE(wherePoint(-3, -2)  == 3);
    REQUIRE(wherePoint(1, 0)  == 0);
    REQUIRE(wherePoint(0,1)  == 0);
}



/*
Задача 12. 
tags: С, сложность F, 1 семестр, условные операторы, циклы, массивы
Написать функцию, которая определяет, является число палиндромом.
Сигнатура: bool palindrome(int n);
Example 1:
input: 12521
output: 1
Example 2:
input: 2222
output: 1
Example 3:
input: 123
output: 0
*/

bool palindrome(int n);
TEST_CASE( "palindrome" ) 
{    
    REQUIRE(palindrome(11511)  == 1);
    REQUIRE(palindrome(123)  == 0);
    REQUIRE(palindrome(22)  == 1);
    REQUIRE(palindrome(1)  == 1);
    REQUIRE(palindrome(12312)  == 0);
}


/*
Задача 13.
tags:  С, сложность F, 1 семестр, циклы, массивы
Напишите функцию, которая считает след квадратной матрицы NxN.
Сигнатура: int trMatrix(int** matr, int n);
Example:
input:
2 -1
4 0
2
output: 2
*/

int trMatrix(int** matr, int n);
TEST_CASE( "tr matrix" ) 
{   
    SECTION("Ex1") 
    {
        int m[3][3] = {
            {2, 4, 6},
            {7, 3, 5},
            {3, 8, 12}
        };
        REQUIRE(trMatrix((int**)m, 3)  == 17);
    }

    SECTION("Ex2") 
    {
        int m[2][2] = {
            {0, 1},
            {7, 3}
        };
        REQUIRE(trMatrix((int**)m, 2)  == 3);
    }

    SECTION("Ex3") 
    {
        int m[1][1] = {{1}};
        REQUIRE(trMatrix((int**)m, 1)  == 1);
    }
}


/*
Задача 14.
tags: C, сложность E, 1 семестр, работа с файлами, строки, массивы
В текстовом файле input.txt хранится строка, содержащая открывающиеся и закрывающиеся фигурные скобки.
Напишите функцию, которая проверяет баланс скобок (для каждой открывающейся скобки есть своя закрывающася).
В случае выполнения баланса записать в файл output.txt 1, в случае невыполнения - 0.
Сигнатура:  void balance(char* input, char* output)
Example:
input.txt:
{{{}{}}{
output.txt
0
*/


void balance(char* input, char* output);
TEST_CASE("") {
    SECTION("ex1") {
        //input.txt: {{{}{}}{
        balance("input.txt", "output.txt");
        std::ifstream file("output.txt");
        int N; 
        file >> N;
        REQUIRE(N == 0); 
    }
    SECTION("ex2") {
        //input2.txt: {{}}
        balance("input2.txt", "output.txt");
        std::ifstream file("output.txt");
        int N; 
        file >> N;
        REQUIRE(N == 1); 
    }
    SECTION("ex3") {
        //input3.txt: {{}}}
        balance("input3.txt", "output.txt");
        std::ifstream file("output.txt");
        int N; 
        file >> N;
        REQUIRE(N == 0); 
    }
    SECTION("ex4") {
        //input4.txt: {
        balance("input4.txt", "output.txt");
        std::ifstream file("output.txt");
        int N; 
        file >> N;
        REQUIRE(N == 0); 
    }
}


/*
Задача 15.
tags: С, сложность E, 1 семестр, строки
Напишите функцию, в которую подаются две строки. Первая - строка, вторая - множество символов. 
Посчитать количество повторений множества в строке.
Сигнатура: int numberRepetitions(const char* str, const char* plenty);
Example:
input:
abcdsfabcerdabc
abc
output:
3
*/

int numberRepetitions(const char* str, const char* plenty);
TEST_CASE( "number of repetitions" )
{
    REQUIRE(numberRepetitions("abcdsfabcerdabc", "abc") == 3);
    REQUIRE(numberRepetitions("a", "abc") == 0);
    REQUIRE(numberRepetitions("abcababaabb", "ab") == 4);
    REQUIRE(numberRepetitions("", "abc") == 0);
    REQUIRE(numberRepetitions("abc", "abc") == 1);
    REQUIRE(numberRepetitions("abcdsfabcerdabc", " ") == 0);
    REQUIRE(numberRepetitions("acdsbc", "bc") == 1);
    REQUIRE(numberRepetitions("abcdfgdf", "ab") == 1);
}


/*
Задача 16.
tags: С, сложность F, 1 семестр, массивы
Написать функцию, которая удаляет из массива все четные элементы. 
Сигнатура: int* deletingEven(int* mus)
Example:
input:
1 2 6 9 -1 0 3
output:
1 9 -1 3
*/

int* deletingEven(int* mus);
TEST_CASE( "deleting even numbers" )
{
    int m[6] = {-1, 0, 1, -2, -4, 5};
    int m_test[3] = {-1, 1, 5};
    int* m_res = deletingEven(m); 
    for (int i = 0; i < 3; ++i) {
        REQUIRE(m_res[i] == m_test[i]);
    }

    int mus[1] = {1};
    int mus_test[1] = {1};
    int* mus_res =  deletingEven(mus); 
    REQUIRE(mus_test[0] == mus_res[0]);

    int array[1] = {2};
    REQUIRE(sizeof(deletingEven(array)) == 0);

    int null_mus[1];
    REQUIRE(sizeof(deletingEven(null_mus)) == 0);
}


/*
Задача 17.
tags: С, сложность F, 1 семестр, строки, циклы
Напишите функцию, которая находит в строке наибольшее количество одинаковых подряд идущих элементов.
Сигнатура: int maxRepeatElements(char* str);
Example:
input: aaabbbbdfdas22ewiiiia
output: 4
*/

int maxRepeatElements(char* str);
TEST_CASE("max count repeat elements") 
{
    REQUIRE(maxRepeatElements("abcccd") == 3);
    REQUIRE(maxRepeatElements("1111abc") == 4);
    REQUIRE(maxRepeatElements("abccddd") == 3);
    REQUIRE(maxRepeatElements("abccdd") == 2);
    REQUIRE(maxRepeatElements("abc") == 1);
    REQUIRE(maxRepeatElements("abcdd") == 2);
}


/*
Задача 18.
tags: С, сложность F, 1 семестр, строки
Пользователь вводит строку символов. Строка состоит из слов, которые отделены друг от друга пробелами. 
Напишите функцию, которая возращает самое длинное слово и через пробел его порядковый номер.
Сигнатура: char* longWord(const char* str);
Example:
input:
"A long time ago in a galaxy far far away"
output:
"galaxy 7"
*/

char* longWord(const char* str);
TEST_CASE( "Find the longest word" ) 
{    
    REQUIRE(std::string(longWord("A long time ago in a galaxy far far away"))  == std::string("galaxy 7"));
    REQUIRE(std::string(longWord("the session is coming soon"))  == std::string("session 2"));
    REQUIRE(std::string(longWord("and students will sleep less"))  == std::string("students 2"));
    REQUIRE(std::string(longWord("abc"))  == std::string("abc 1"));
}


/*
Задача 19.
tags: C, сложность F, 1 семестр, массивы
Напишите функцию, которая принимает массив целых чисел, а возвращает максимальное по модулю
произведение двух чисел из этого массива.
Сигнатура: int maxMult(int* mus);
Example:
input: 1, 3, 2, 2, 3, -4
output: 12
*/

int maxMult(int* mus);
TEST_CASE( "max mult" )
{
    int m[6] = {-1, 0, 1, -2, -4, 5};
    REQUIRE(maxMult(m) == 20);

    int mus[1] = {1};
    REQUIRE(maxMult(mus) == 1);

    int array[4] = {-1, 2, 0, 6};
    REQUIRE(maxMult(array) == 12);

    int null_mus[3] = {0, 0, 0};
    REQUIRE(maxMult(null_mus) == 0);
}


/*
Задача 20.
tags: С, сложность E, 1 семестр, строки
Напишите функцию, которая принимает строку, а возвращает ее перевернутый вариант (слова в обратном порядке).
Сигнатура: char* reverse(char* str);
Example:
input: general purpose programming language 
output: language programming purpose general
*/

char* reverse(char* str);
TEST_CASE( "Reverse str" ) 
{    
    REQUIRE(std::string(reverse("general purpose programming language")) ==
    std::string("language programming purpose general"));
    REQUIRE(std::string(reverse("123"))  == std::string("123"));
    REQUIRE(std::string(reverse(""))  == std::string(""));
    REQUIRE(std::string(reverse("im tired"))  == std::string("tired im"));
}


/*
Задача 21.
tags: С, сложность F, 1 семестр, массивы, циклы
Написать функцию сортировки массива в порядке неубывания.
Сигнатура: int* sort(int* mus);
Example:
input: 1 5 8 1 6 4 5 10
output: 1 1 4 5 5 6 8 10
*/

int* sort(int* mus);
TEST_CASE( "To sort array" )
{   
    SECTION("test 1") 
    {
        int m[6] = {1, 0, 1, 2, 4, 2};
        int m_test[6] = {0, 1, 1, 2, 2, 4};
        int* m_res = deleteRepeat(m);
        for (int i = 0; i < 6; ++i) {
            REQUIRE(m_res[i] == m_test[i]);
        }
    }

    SECTION("test 2") 
    {
        int m[3] = {1,1,1};
        int m_test[3] = {1,1,1};
        int* m_res = deleteRepeat(m);
        for (int i = 0; i < 3; ++i) {
            REQUIRE(m_res[i] == m_test[i]);
        }
    }

    SECTION("test 3") 
    {
        int m[4] = {1, 2, 3, 4};
        int m_test[4] = {1, 2, 3, 4};
        int* m_res = deleteRepeat(m);
        for (int i = 0; i < 4; ++i) {
            REQUIRE(m_res[i] == m_test[i]);
        }
    }
}


/*
Задача 22.
tags: С, сложность E, 1 семестр, массивы
На вход подается одномерный массив рациональных чисел. Необходимо отсортировать массив (можно методом пузырька).
Затем добавить в конец массива
* медиану (отметка, делящая ранжированные данные, либо число по середине ранжированного списка, 
  либо среднее арифметическое из двух по середине)
* моду (наиболее часто встречающееся значение в данных)
* среднее 
* максимум
* минимум
* размах (разность между наибольшим и наименьшим).
Сигнатура: float* mus(float* array);
Example:
input:
5 3 -2 6 -9 2 0 4 8 -2
output:
-9  -2 -2  0 2 3 4 5 6 8 2.5 -2 1.5 8 -9 17
*/

float* mus(float* array);
TEST_CASE(" ") 
{   
    SECTION("Ex1") {
        float arr[10] = {5, 3, -2, 6, -9, 2, 0, 4, 8, -2};
        float res[16] = {-9, -2, -2, 0, 2, 3, 4, 5, 6, 8, 2.5, -2, 1.5, 8, -9, 17};
        float* test = mus(arr);
        for (int i = 0; i < 16; ++i) {
            REQUIRE(res[i] == test[i]);
        }
    }
    SECTION("Ex2") {
        float arr[6] = {5, -9, 8, 1, -4, 1};
        float res[12] = {-9, -4, 1, 1, 5, 8, 1, 1, 0.333333, 8, -9, 17};
        float* test = mus(arr);
        for (int i = 0; i < 12; ++i) {
            REQUIRE(res[i] == test[i]);
        }
    }
}


/*
Задача 23. 
tags: С, сложность E, 1 семестр, массивы
Напишите функцию, которая удаляет из массива все повторяющиеся элементы. 
Сигнатура: int* deleteRepeat(int* mus);
Example:
input: 1 5 8 1 6 4 5 1 10
output: 1 5 8 6 4 10
*/

int* deleteRepeat(int* mus);
TEST_CASE( "delete Repeat" )
{   
    SECTION("test 1") 
    {
        int m[6] = {1, 0, 1, 2, 4, 2};
        int m_test[4] = {1, 0, 2, 4};
        int* m_res = deleteRepeat(m);
        for (int i = 0; i < 4; ++i) {
            REQUIRE(m_res[i] == m_test[i]);
        }
    }

    SECTION("test 2")
    {
        int m[4] = {1, 1, 1, 1};
        int m_test[1] = {1};
        int* m_res = deleteRepeat(m);
        for (int i = 0; i < 1; ++i) {
            REQUIRE(m_res[i] == m_test[i]);
        }
    }

    SECTION("test 3") 
    {
        int m[3] = {1, 2, 3};
        int m_test[3] = {1, 2, 3};
        int* m_res = deleteRepeat(m);
        for (int i = 0; i < 3; ++i) {
            REQUIRE(m_res[i] == m_test[i]);
        }
    }
}



/*
Задача 24.
tags: С, сложность F, 1 семестр, циклы, простые операторы
Вводится пятизначное число. Необходимо вывести отдельно каждую цифру в новой строке.
Example:
input: 15341
output:
1
5
3
4
1


Задача 25.
tags: С, сложность F, 1 семестр, циклы, простые операторы
Пользователь вводит натуральное число n - количество слагаемых и целое число k - степень.
Найти алгебраическую сумму для выражения: 1^k + 2^k + 3^k + … + N^k.
Example:
input: 3 3
output: 36


Задача 26. 
tags: С, сложность F, 1 семестр, циклы, простые операторы, условные операторы
Вводится натуральное число. Найти наибольшую и наименьшую цифру в числе.
Example:
input: 157693
output: 9 1


Задача 27. 
tags: С, сложность F, 1 семестр,  простые операторы
Вводятся 3 рациональных числа x,y,z - координаты вектора. Найти его длину. Ответ округлить до сотых. 
Example:
input: -2 4 -4
output: 6


Задача 28. 
tags: С, сложность F, 1 семестр, условные операторы, циклы
Пользователь вводит нечетное число n >= 3, затем вводится число, где  1 - *,2 -  +, 3 - #.
Составить программу, которая будет печатать ромб выбранным значком. 
Выбор значков организовать оператором switch.
Example:
input:
5
1
output:
  *
 ***
*****
 ***
  *


Задача 29.
tags: C, сложность F, 1 семестр, циклы
Используя оператор цикла do while, составить программу, которая будет требовать ввод цифр
с клавиатуры до тех пор, пока не будет введен 0. Вывести сумму введенных цифр.
Example:
input: 1 3 2 8 5 0
output: 19


Задача 30.
tags: С, сложность E, 1 семестр, условные операторы 
Даны два уравнения линий: y = ax^2 + bx + c и y = dx + k. Пользователь вводит числа a, b, c, d, k.
Вывести координаты (x,y) точки/точек пересечения. Если линии не пересекаются, вывести 0. 
Example:
input: 1 2 3 1 5
output:
1 6
-2 3

+
Задача 31.
tags: С, сложность F, 1 семестр, массивы
Задача на динамическое выделение памяти. Изначально есть указатель на массив с одним элементом.
Пользователь вводит число. Если оно больше 0 записываем его в массив. Далее пользователь вводит второе число.
Если оно больше 0, надо перевыделить память для 2-х элементов массива и записать в массив второе число. 
И так далее…  для 3-х элементов, для 4-х…  пока пользователь не введет отрицательное число. 
Вывести сумму введенных элементов и размер массива.  
Example:
input:
4 5 3 2 1 -1
output:
15 6


Задача 32.
tags: C, сложность E, 1 семестр, массивы, циклы, генерация значений
В функцию подаются числа a и b. Сгенерировать случайные числа в интервале [a;b] и заполнить
ими двумерный массив размером 6 на 6. В массиве необходимо найти максимальный и минимальный элемент. 
Заменить числа на главной диагонали на максимальный элемент, а числа на побочной - на минимальный. 
На место пересечения - сумму максимального и минимального. Вернуть полученный массив.
Сигнатура: int** matrix(int a, int b);
Example:
input:
-9 9
output:
8 5 6 -2  4 -7
3 8 -1 3 -7 2
1 6 8 -7 1 0
2 3 -7 8 2 -3
1 -7 0 -1 8 2
-7 2 3 -2 4 8


Задача 33. 
tags: C, сложность E, 1 семестр, работа с файлами, массивы
Дан файл, в котором записан некоторый текст на английском языке. Требуется вывести в алфавитном
порядке все буквы, которые встречаются в файле и их количество.
Example:
input.txt:
aaaa cbb abb
output:
a - 5
b - 4 
c - 1


Задача 34. 
tags: С, сложность F, 1 семестр, циклы
На вход подается число N. Вывести на экран треугольник из символов "*" из N линий.
Example:
input:
5
output:
    *
   ***
  *****
 *******
*********


Задача 35.
tags: С, сложность F, 1 семестр, простые операторы
Даны значения двух моментов времени, принадлежащих одним и тем же суткам: часы, минуты и секунды для каждого
из моментов времени. Известно, что второй момент времени наступил не раньше первого. Определите, сколько секунд
прошло между двумя моментами времени.
Example:
input:
12 32 45
17 43 06
output:
18621


Задача 36.
tags: С, сложность F, 1 семестр, массивы
Определите наименьшее расстояние между двумя локальными максимумами последовательности натуральных чисел,
завершающейся числом 0. Если в последовательности нет двух локальных максимумов, выведите число 0.
Example:
input: 3 4 5 1 6 2 1 3 5 0
output: 1


Задача 37.
tags: С, сложность Е, 1 семестр, простые операторы
Даны действительные коэффициенты a, b, c. Решите уравнение ax2 + bx + c = 0 и выведите все его корни.
Если данное уравнение не имеет корней, выведите число 0. Если уравнение имеет один корень, 
выведите число 1, а затем этот корень. Если уравнение имеет два корня, выведите число 2, а затем два корня
в порядке возрастания. Если уравнение имеет бесконечно много корней, выведите число 3.
Example:
input:
1 -5 4
output:
2
4 1
*/
