#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	unsigned char letter;
	unsigned char part_one_letter;
	unsigned char part_two_letter;
	unsigned char new_letter;

	unsigned char n128 = 0x80;
	unsigned char n64 = 0x40;
	unsigned char n32 = 0x20;
	unsigned char n16 = 0x10;
	char zero = 0;

	string text;

	FILE * pfile;
	pfile = fopen("write.txt", "w");
	if (pfile == NULL) perror("Error opening file");

	srand(time(NULL));

	printf(">> ");

	do
	{
		text.clear();

		// Separando a letra em duas partes
		letter = getchar();
		part_one_letter = letter >> 4;
		part_two_letter = letter << 4;
		part_two_letter = part_two_letter >> 4;

		// Sair do loop caso tenha acabado o texto
		if (letter == '\n')
			break;

		// Formando uma letra nova mas mantendo uma parte da antiga
		new_letter = 0;
		new_letter = new_letter | part_one_letter;
		if (rand() % 2 == 1)
			new_letter = new_letter | n128;
		if (rand() % 2 == 1)
			new_letter = new_letter | n64;
		if (rand() % 2 == 1)
			new_letter = new_letter | n32;
		if (rand() % 2 == 1)
			new_letter = new_letter | n16;

		// Adicionando letra
		if (new_letter == 0)
			text.append(1, '0');
		else
			text.append(1, new_letter);

		// Formando uma letra nova mas mantendo uma parte da antiga
		new_letter = 0;
		new_letter = new_letter + part_two_letter;
		if (rand() % 2 == 1)
			new_letter = new_letter + n128;
		if (rand() % 2 == 1)
			new_letter = new_letter + n64;
		if (rand() % 2 == 1)
			new_letter = new_letter + n32;
		if (rand() % 2 == 1)
			new_letter = new_letter + n16;

		// Adicionando letra
		if (new_letter == 0)
			text.append(1, '0');
		else
			text.append(1, new_letter);

		// Escreve no arquivo
		fprintf(pfile, "%s", text.c_str());

	} while (letter != '\n');

	fclose(pfile);

	return 0;
}