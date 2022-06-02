//делает строку числом
int strToInt(const char* str);
//Перевод в нижний регистр, изменяя исходную строку
void mutableToLower(char* str);
//Перевод в нижний регистр, не изменяя исходную строку
char* immutableToLower(const char* str);
//Перевод в верхний регистр, изменяя исходную строку 
void mutableToUpper(char* str);
//Перевод в верхний регистр, не изменяя исходную строку 
char* immutableToUpper(const char* str);
//удаляет пробелы в начале и конце строки, изменяя ее
void mutableStrip(char* str);
//удаляет пробелы в начале и конце строки, не изменяя ее 
char* immutableStrip(const char* str);
// удаляет все пробелы в строке, изменяя ее
void mutableRemoveSpaces(char* str);
// удаляет все пробелы в строке, не изменяя ее 
char* immutableRemoveSpaces(const char* str);
// Удаляет из строки все, кроме чисел и букв, изменяя ее
void mutableFilter(char* str);
// Удаляет из строки все, кроме чисел и букв, не изменяя ее 
char* immutableFilter(const char* str);

// Проверяет, является ли строка числом
bool isNumber(const char* str);
// Проверяет, является ли строка набором букв
bool isAlpha(const char* str);
