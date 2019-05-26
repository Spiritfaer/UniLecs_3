#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

/*
Задача:
 		Напишите функцию, заменяющий все пробелы в строке символами '%20'.
 		Можно предположить, что длина строки позволяет сохранить дополнительные символы
 		и «истинная» длина строки известна.

(Примечание: при реализации метода на C# используйте сим-вольный массив.)
(Примечание от меня: при реализации метода на C можно использовать тот же сим-вольный массив)

Пример:
		Ввод: "Mr John Smith "
		Вывод: "Mr%20John%20Smith%20"
 */

#define MAX 256

int32_t	replace_space_by_special_symbols(char *str, char *symbols, char ch)
{
	int32_t count, str_length, symbols_length, new_str_length;
	char *tmp;

	if (!str || !*str || !symbols || !*symbols || !isascii(ch))
		return (0);
	count = 0;
	tmp = symbols;
	while (*tmp)
		tmp++;
	symbols_length = (int32_t)(tmp - symbols);
	tmp = str;
	while (*tmp)
	{
		if (*tmp == ch) {
			count++;
		}
		tmp++;
	}
	str_length = (int32_t)(tmp - str);
	new_str_length = str_length + ((--symbols_length) * count);
	if (new_str_length > MAX)
		return (0);
	tmp = str + new_str_length;
	*tmp-- = '\0';
	while (str_length)
	{
		*tmp = *(str + --str_length);
		if (*tmp == ch)
		{
			count = symbols_length;
			while(count >= 0)
			{
				*tmp-- = *(symbols + count);
				count--;
			}
		}
		else
			tmp--;
	}
	return (new_str_length);
}

int main(void)
{
	char str[MAX] = {"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore."};
	char *symbols = "__%42__";
	char ch = ' ';

	printf("%s;\n\n", str);
	(replace_space_by_special_symbols(str, symbols, ch)) ? printf("%s;\n", str) : printf("Line is too long!\n");
	return (0);
}
