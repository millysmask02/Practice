typedef struct
{
    char    lastName[64];   // фамилия
    int     id;             // шифр
    int     mark;           // оценка: 0 - fail, 1 - pass
} Student;

//разворот строки
void reverse(char* string);
//вывод информации о студенте
void print(const Student* student);
//вывод оценок всех студентов
void printAll(const char* fileName);
