typedef struct
{
	float x;
	float y;
} Complex;

// ��������
Complex add(Complex a, Complex b);
// ���������
Complex mul(Complex a, Complex b);
// �������
Complex div(Complex a, Complex b);
// ��������� ������
float mod(Complex a);
// ��������� ���������
float arg(Complex a);
// ��������� �����������
Complex add(Complex a);
// ����� � �������������� �����
void printAlg(Complex a);
// ����� � ������������������ �����
void printTrig(Complex a);
// ����� � ������������� �����
void printExp(Complex a)
