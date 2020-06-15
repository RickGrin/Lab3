#include <stdio.h>
#include <string.h>

int count = 0;

void func() 
{  
	printf("%i", count);
}

int main() 
{
	printf("Enter word: ");
	char word[81];
	scanf_s("%s", word, 81);
	FILE* file;
	fopen_s(&file, "test.txt", "r");

	int ChisloSlov = strlen(word);

	do

	{

		char str[81];
		fgets(str, 81, file);
		char* strtok = str;

		while (true)

		{

			strtok = strstr(strtok, word);

			if (!strtok) //Возвращает позицию первого вхождения подстроки

				break;

			char& c = strtok[ChisloSlov];

			if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'))
				count++;
			strtok += ChisloSlov;

		}

	}
	
	while (!feof(file));
	fclose(file);
	func();

	return 0;

}