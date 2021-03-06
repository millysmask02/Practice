/* Программа позволять создавать, редактировать и просматривать контакты.
Количество контактов заранее неизвестно. Каждый контакт содержит:
1. «Имя» – до 80 символов,
2. «Номер телефона» – до 12 символов,
3. «Группа» – одно из: нет группы, семья, друзья, коллеги.

Программа выводит на консоль меню с вариантами действий, ожидает,
пока пользователь введет символ, обозначающий какую либо команду,
выполнят ее, и, если команда не означает завершение работы, опять выводит меню и тд. 

Варианты действий:
* «Добавить контакт» – запрашиваем данные для полей и сохраняем,
  имена контактов должны быть уникальны
* «Удалить контакт» – запрашиваем имя и удаляем контакт с таким именем
* «Изменить имя/телефон/группу» – делаем подменю, спрашиваем имя,
  потом что делать и новое значение
* «Вывести» – делаем подменю, спрашиваем как выводить, и, если надо, что искать:
	контакт по имени – запрашиваем имя и красиво выводим в консоль данные,
	контакт по телефону,
	все контакты,
	все контакты из указанной группы.
* «Завершить работу».

Имя группы пользователь вводит строкой, в структуре хранить с помощью enum. 
*/

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
