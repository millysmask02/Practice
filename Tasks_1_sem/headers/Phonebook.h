// ��������� ��������:
struct Contact
{
	char name[80];
	char phone[12];
	int group;
};

//������, � ������� ����� ������������ �������
enum Groups
{
	NO_GROUP,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

//�������/���������� ����������
enum SortParam 
{
	WithoutSorting,
	WithSorting,
};

//�������� �������
void addContact(const char* fileName, const Contact* contact, const SortParam param);
//������� �������
void removeContact(const char* fileName, const char* phoneNumber);
//������������� �������
void editContact(const char* fileName,
	const char* phoneNumber,
	const Contact* newContact);
//����� �������� �� ����� � �������
void printContacts(const char* fileName);
//�������� ���� � ����������
void clearPhonebook(const char* fileName);
//���������� ��������� � �����
int countContacts(const char* fileName);
//�������� ��������
Contact* getContacts(const char* fileName);
//������������� �������� � �����
void sortContacts(const char* fileName);
//�������� ����� �� �������������
void checkFileExists(const char* fileName);
//�������� ������� \n � ������
void trimString(const size_t size, char* str);