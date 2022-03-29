// структура контакта:
struct Contact
{
	char name[80];
	char phone[12];
	int group;
};

//группы, к которым может принадлежать контакт
enum Groups
{
	NO_GROUP,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

//наличие/отсутствие сортировки
enum SortParam 
{
	WithoutSorting,
	WithSorting,
};

//добавить контакт
void addContact(const char* fileName, const Contact* contact, const SortParam param);
//удалить контакт
void removeContact(const char* fileName, const char* phoneNumber);
//редактировать контакт
void editContact(const char* fileName,
	const char* phoneNumber,
	const Contact* newContact);
//вывод контакты из файла в консоль
void printContacts(const char* fileName);
//очистить файл с контактами
void clearPhonebook(const char* fileName);
//количество контактов в файле
int countContacts(const char* fileName);
//получить контакты
Contact* getContacts(const char* fileName);
//отсортировать контакты в файле
void sortContacts(const char* fileName);
//проверка файла на существование
void checkFileExists(const char* fileName);
//удаление символа \n в строке
void trimString(const size_t size, char* str);