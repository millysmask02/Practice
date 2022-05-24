//ЗАДАЧИ НА 1 СЕМЕСТР\\ 
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\

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
Используя оператор цикла do while, составить программу, которая будет требовать ввод цифр
с клавиатуры до тех пор, пока не будет введен 0. Вывести сумму введенных цифр.
Example:
input: 1 3 2 8 5 0
output: 19
Задача 30.
tags: С, сложность E, 1 семестр, условные операторы 
Даны два уравнения линий: y = ax^2 + bx + c и y = dx + k. Пользователь вводит числа a, b, c, d, k.
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
В функцию подаются числа a и b. Сгенерировать случайные числа в интервале [a;b] и заполнить
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




//ЗАДАЧИ НА 2 СЕМЕСТР\\
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\

/*
Задача 1.
tags: C++, сложность E, семестр 2, список
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
tags: C++, сложность E, семестр 2, словари, работа с файлами
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
tags: C++, сложность D, семестр 2, вектор, сортировка
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
tags: C++, сложность D, семестр 2, стек, сортировка
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
tags: C++, сложность E, семестр 2, вектор
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
tags: C++, сложность D, семестр 2, массив, сортировка
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
tags: C++, сложность D, семестр 2, вектор, сортировка
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
tags: C++, сложность D, семестр 2, генерация чисел, циклы
Напишите программу, реализующую игру "Угадай число".
Компьютер загадывает число от 0 до 999 (используйте генерацию случайных чисел). 
На каждом шаге пользователь делает предположение, а компьютер сообщает, 
является ли это число больше, меньше или равно загаданному. 
Когда пользователь отгадывает задуманное число, игра заканчивается.
*/

/*
Задача 9.
tags: C++, сложность С, семестр 2, ООП
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
tags: C++, сложность С, семестр 2, ООП, работа с файласм
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
tags: C++, сложность С, семестр 2, ООП
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
tags: C++, сложность С, семестр 2, ООП
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
tags: C++, сложность С, семестр 2, ООП
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
tags: C++, сложность E, семестр 2
Дана последовательность целых чисел, заканчивающаяся числом 0. 
Выведите эту последовательность в обратном порядке.
При решении этой задачи нельзя пользоваться массивами и прочими динамическими
структурами данных. Рекурсия вам поможет.
*/

/*
Задача 15.
tags: C++, сложность B, семестр 2, массивы, ООП
Реализовать класс матрицы целых чисел. Размерность матриц не ограничена. Класс должен:
* считывать элементы матрицы из файла формата csv;
* реализовывать конструкторы копирования и перемещения (если необходимо);
* реализовывать операторы копирующего и перемещающего присваивания (если необходимо);
* реализовывать операторы сложения, вычитания, умножения матриц;
* обрабатывать ошибки с использованием исключений
*/

/*
Задача 16.
tags: C++, сложность E, семестр 2
Напишите программу, которая будет выводить календарь на месяц и год, который вводит пользователь.
P.s. отсчет вести от 01.01.1919 (среда)
Example:
input: 5 2022
output: 
Mo Tu We Th Fr Sa Su
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31
*/

/*
Задача 17.
tags: C++, сложность E, семестр 2
Пользователь вводит число N. Написать программу, которая выводит спиральный массив.
Спиральный   массив   представляет собой квадратное расположение первых   N^2   натуральных чисел, где
числа последовательно увеличиваются по мере того, как вы идете по краям массива по спирали внутрь.
Example:
input:
5
output:
0 1 2 3 4
15 16 17 18 5
14 23 24 19 6
13 22 21 20 7
12 11 10 9 8
*/

/*
Задача 18.
tags: C++, сложность E, семестр 2, случайная генерация
Игра   «Свинья»   — это многопользовательская игра, в которой используется один шестигранный кубик. 
Цель игры —   набрать 100   и более очков. Игра ведется по очереди. В свой ход у этого человека есть выбор:
1. Бросание костей : когда к их счету за этот ход добавляется результат от двух до шести, и ход игрока продолжается, 
поскольку игроку снова предоставляется тот же выбор; или бросок   1   теряет общее количество очков игрока   за этот ход,
и его ход заканчивается передачей игры следующему игроку.
2. Удерживание : счет игрока за этот раунд добавляется к его общему количеству и становится безопасным от эффектов
выбрасывания   1   (единицы). Ход игрока заканчивается передачей хода следующему игроку.
Создайте программу для подсчета очков и имитации бросков костей в игре для двух человек.
*/

/*
Задача 19.
tags: C++, сложность E, семестр 2, вектор
Число вампира — это натуральное десятичное число с четным количеством цифр, которое можно разложить на два целых числа.
Эти два числа называются клыками и должны обладать следующими свойствами:
 * каждый из них содержит половину десятичных цифр исходного числа
 * вместе они состоят из тех же десятичных цифр, что и исходное число
 * самое большее одно из них имеет конечный ноль
Выведите первые N чисел вампиров и их клыки
Пример номера вампира и его клыков:   1260 : (21, 60)
*/

/*
Задача 20.
tags: C++, сложность E, семестр 2, массивы, сортировка
Отсортируйте массив (или список) элементов, используя алгоритм сортировки выбором.
Это работает следующим образом:
Сначала найдите в массиве наименьший элемент и замените его на элемент в первой позиции, затем найдите второй наименьший 
элемент и замените его на элемент во второй позиции, и так далее, пока весь массив не будет отсортирован.
Его асимптотическая сложность составляет   O (n 2 )   , что делает его неэффективным на больших массивах.
Его основная цель - когда запись данных очень дорогая (медленная) по сравнению с чтением, например. запись во флэш-память или EEPROM.
Никакой другой алгоритм сортировки не имеет меньшего количества перемещений данных.
*/



//ЗАДАЧИ НА 3 СЕМЕСТР\\ 
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\


/*
Задача 1.
tags: C++, сложность D, семестр 3, STL, stack
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
tags: C++, сложность D, семестр 3, STL, работа с файлами
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
tags: C++, сложность D, семестр 3, STL, работа с файлами
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
tags: C++, сложность D, семестр 3, STL, вектор
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
tags: C++, сложность E, семестр 3
Напишите функцию sumNumber, которая принимает две строки - числа в разных системах счисления (со 2 по 36)
и выводит их сумму в двоичной системе счисления. Числа представлены в виде: число_системаСчисления
Example:
input: 10011_2 171_8
output: 10001100
*/

std::string sumNumber(std::string first, std::string second);
TEST_CASE("Sum two number") 
{
    REQUIRE(sumNumber("10011_2", "171_8") == std::string("10001100"));
    REQUIRE(sumNumber("1011_2", "8A5_16") == std::string("100010110000"));
    REQUIRE(sumNumber("FF_16", "HELLO_36") == std::string("1101111100001011011011011"));
    REQUIRE(sumNumber("120802_10", "171765_8") == std::string("101100101111010111"));
    REQUIRE(sumNumber("851_10", "123_10") == std::string("11 1100 1110"));
}


/*
Задача 6.
tags: C++, сложность D, семестр 3, STL, работа с файлами
Даны 12 csv-файлов с логинами и их зашифрованными через радуждные таблицы версиями. 
Пользователь вводит зашифрованный логин, необходимо найти в файлах его оригинал.
*/


/*
Задача 7.
tags: C++, сложность C, семестр 3, ООП
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

/*
Задача 8.
tags: C++, сложность D, семестр 3, работа с файлами
Написать программу, которая построчно объединяет файлы, переданные ей как аргументы командной строки, 
и выводит их в новый текстовый файл.
Передачу имен файлов реализовать через аргументы командной строки.
Объединение происходит таким образом, что сначала выводятся первые строки всех файлов по 
порядку следования, потом вторые, третьи и т. д.
Если какие-то из файлов не могут быть найдены или открыты, программа должна выдать 
предупреждение об этом в стандартный вывод ошибок (cerr) и продолжить работу, игнорируя неоткрытые файлы.
Example:
input:
Файл 1.txt:
aa
bb
cc
Файл 2.txt:
0
1
Файл 3.txt:
hey
output:
aa
0
hey
bb
1
cc
*/

/*
Задача 9.
tags: C++, сложность D, семестр 3, STL
Дано N чисел, требуется выяснить, сколько среди них различных.
В первой строке дано число N – количество чисел. (1 <= N <= 100000) 
Во второй строке даны через пробел N чисел, каждое не превышает 2*10^9 по модулю.
Выведите число, равное количеству различных чисел среди данных.
Примечание: использовать STL.
Example:
input:
5
1 0 1 2 0
output:
3
*/

/*
Задача 10.
tags: C++, сложность D, семестр 3, STL
Напишите программу, которая моделирует игру в пьяницу и определяет, кто выигрывает. 
В игре участвует 10 карт, имеющих значения от 0 до 9, большая карта побеждает меньшую, карта со значением 0 побеждает карту 9.
Программа получает на вход две строки: первая строка содержит 5 чисел, разделенных пробелами — номера карт первого игрока, 
вторая – аналогично 5 карт второго игрока. Карты перечислены сверху вниз, то есть каждая строка начинается с той карты, которая будет открыта первой.
Программа должна определить, кто выигрывает при данной раздаче, и вывести слово first или second, после чего вывести количество ходов, 
сделанных до выигрыша. Если на протяжении 10^6 ходов игра не заканчивается, программа должна вывести слово botva.
Примечание: использовать STL.
Example:
input:
1 3 5 7 9
2 4 6 8 0
output:
second 5
*/


/*
Задача 11.
tags: C++, сложность C, семестр 3, STL, stack
На складе хранятся контейнеры с товарами N различных видов. Все контейнеры составлены в N стопок. 
В каждой стопке могут находиться контейнеры с товарами любых видов (стопка может быть изначально пустой).
Автопогрузчик может взять верхний контейнер из любой стопки и поставить его сверху в любую стопку. 
Необходимо расставить все контейнеры с товаром первого вида в первую стопку, второго вида – во вторую стопку и т.д.
Программа должна вывести последовательность действий автопогрузчика или сообщение о том, что задача решения не имеет.
В первой строке входных данных записано одно натуральное число N, не превосходящее 500. 
В следующих N строках описаны стопки контейнеров: сначала записано число ki – количество контейнеров в стопке, 
а затем ki чисел – виды товара в контейнерах в данной стопке, снизу вверх. В каждой стопке вначале 
не более 500 контейнеров (в процессе переноса контейнеров это ограничение может быть нарушено).
Программа должна вывести описание действий автопогрузчика: для каждого действия напечатать два 
числа – из какой стопки брать контейнер и в какую стопку класть. (Обратите внимание, что минимизировать 
количество операций автопогрузчика не требуется.) Если задача не имеет решения, необходимо вывести одно число 0. 
Если контейнеры изначально правильно размещены по стопкам, то  выводить ничего не нужно.
римечание: использовать STL.
Example:
input:
3
4 1 2 3 2
0
0
output:
1 2
1 3
1 2
Объяснение примера. Изначально в первой стопке лежат четыре контейнера – снизу контейнер с товаром первого вида, 
над ним – с товаром второго вида, над ним третьего, и сверху еще один контейнер с товаром второго вида. Вторая и третья стопки – пусты.
*/

/*
Задача 12.
tags: C++, сложность D, семестр 3, STL, работа с файлами
Для транспортирования материалов из цеха А в цех В используется конвейер. Материалы упаковываются в одинаковые контейнеры и размещаются на
ленте один за одним в порядке изготовления в цехе А. Каждый контейнер имеет степень срочности обработки в цехе В. Для упорядочивания 
контейнеров по степени срочности используют накопитель, который находится в конце конвейера перед входом в цех В. Накопитель работает пошагово, 
на каждом шаге возможны следующие действия:
* накопитель перемещает первый контейнер из ленты в цех В;
* накопитель перемещает первый контейнер из строки в склад (в складе каждый следующий контейнер помещается на предыдущий);
* накопитель перемещает верхний контейнер из склада в цех В.
Напишите программу, которая по последовательности контейнеров определит, можно ли упорядочить их по степени срочности пользуясь описанным накопителем.
Входной файл в первой строке содержит количество тестов N. Далее следует N строк, каждый из которых описывает отдельный тест и содержит целое 
число K (1 ≤ K ≤ 10000) — количество контейнеров в последовательности и K действительных чисел — степеней срочности контейнеров в порядке 
их поступления из цеха А (меньшим числам соответствует большая степень срочности).
Выходные данные
Каждая строка выходного файла должна содержать ответ для одного теста. Необходимо вывести 1, если необходимое упорядочивание возможно, или 0 в противном случае.
Example:
input:
2
2 2.9 2.1
3 5.6 9.0 2.0
output:
1
0
*/

/*
Задача 13.
tags: C++, сложность C, семестр 3, STL
На барже располагается K грузовых отсеков. В каждый отсек можно поместить некоторое количество бочек с одним из 10 000 видов топлива.
Причём извлечь бочку из отсека можно лишь в случае, если все бочки, помещённые в этот отсек после неё, уже были извлечены.
Таким образом в каждый момент времени в каждом непустом отсеке имеется ровно одна бочка, которую можно извлечь не трогая остальных. 
Будем называть такие бочки крайними.
Изначально баржа пуста. Затем она последовательно проплывает через N доков, причём в каждом доке на баржу либо погружается бочка
с некоторым видом топлива в некоторый отсек, либо выгружается крайняя бочка из некоторого отсека. Однако, если указанный отсек пуст,
либо если выгруженная бочка содержит не тот вид топлива, который ожидалось, следует зафиксировать ошибку. Если на баржу оказывается
погружено более P бочек или если после прохождения всех доков она не стала пуста, следует также зафиксировать ошибку.
От вас требуется либо указать максимальное количество бочек, которые одновременно пребывали на барже либо зафиксировать ошибку.
В первой строке три целых числа N, K и P (1 ≤ N, K, P ≤ 100 000). Далее следует N строк с описанием действия, выполняемого в очередном доке. Если в нём происходит погрузка, то строка имеет вид «+ A B», где A — номер отсека, в который помещается бочка, а B — номер вида топлива в ней. Если же док занимается разгрузкой, то строка имеет вид «- A B», где A — номер отсека, из которого извлекается бочка, а B — номер ожидаемого вида топлива.
Вывести либо одно число, равное искомому максимуму в случае безошибочного прохождения баржой маршрута, либо вывести слово «Error» в противном случае.
Example:
input:
6 1 2
+ 1 1
+ 1 2
- 1 2
- 1 1
+ 1 3
- 1 3
output:
2
*/

/*
Задача 14.
tags: C++, сложность C, семестр 3, работа с файлами
На секретную базу в Арктике поступила шифровка – последовательность из n десятичных цифр. Она содержит номер секретной базы в Антарктиде, 
который является последовательностью из k десятичных цифр. При этом для того, чтобы отличить его от ненужной Вам информации, он повторен 
в шифровке хотя бы два раза (возможно, эти два вхождения перекрываются).
Напишите программу, которая по шифровке и длине номера секретной базы определяет, содержит ли шифровка номер базы. Учтите, что у базы может
быть несколько номеров, и все они могут быть переданы в шифровке.
Первая строка входного файла INPUT.TXT содержит два целых числа: n (1 ≤ n ≤ 10^5) и k (1 ≤ k ≤ 5) – длину шифровки и длину номера секретной 
базы соответственно. Вторая строка содержит n цифр – шифровку. Помните, что цифры в шифровке не разделяются пробелами.
В выходной файл OUTPUT.TXT выведите «YES», если шифровка содержит номер секретной базы, и «NO» в противном случае.
Example:
input:	
10 5
0123456789
output:
NO
input:
13 2
0123400056789
output:
YES
*/

/*
Задача 15.
tags: C++, сложность D, семестр 3, работа с файлами
В первой строке входного файла INPUT.TXT находится два числа N и M (1 ≤ N ≤ 103, 1 ≤ M ≤ 105). В следующих N строках находится по одному
слову из словаря. Все слова состоят из строчных английских букв. Длина каждого слова не превышает 20. Каждое слово состоит хотя бы из 
одного символа. Лишних пробелов перед словом и после него нет.
В следующих M строках находится текст сочинения. Текст состоит из заглавных и строчных английских букв, пробелов и знаков препинания: 
точек (.), запятых (,), двоеточий (:), точек с запятыми (;), тире (-), апострофов ('), кавычек ("), восклицательных (!) и вопросительных (?) знаков.
Общая длина текста не превосходит 104 символов. В данной задаче большие и маленькие буквы в словах не различаются.
В выходной файл OUTPUT.TXT выведите «Everything is going to be OK.», если с сочинением все в порядке. Если не все слова из текста встречаются в 
словаре, выведите «Some words from the text are unknown.». Если же предыдущее неверно, но некоторые слова из словаря не встречаются в тексте, 
выведите «The usage of the vocabulary is not perfect.».
Example:
№	INPUT.TXT	            OUTPUT.TXT
1	3 1
    am
    bill
    i
    I am Bill, am I?	    Everything is going to be OK.
2	2 2
    seven
    day
    On the
    seventh day	            Some words from the text are unknown.
3	4 1
    vocabulary
    wide
    too
    much
    Too wide vocabulary.	The usage of the vocabulary is not perfect.
*/