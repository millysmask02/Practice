typedef struct
{
    char    lastName[64];   // �������
    int     id;             // ����
    int     mark;           // ������: 0 - fail, 1 - pass
} Student;

//�������� ������
void reverse(char* string);
//����� ���������� � ��������
void print(const Student* student);
//����� ������ ���� ���������
void printAll(const char* fileName);
