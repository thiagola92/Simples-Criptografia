#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{

	unsigned char letter2;
	unsigned char part_one_letter2;
	unsigned char part_two_letter2;
	unsigned char new_letter2;

	string text2;

	int x;

	FILE * pfile2;
	pfile2 = fopen("read.txt", "w");
	if (pfile2 == NULL) perror("Error opening file");

	FILE * pfile3;
	pfile3 = fopen("write.txt", "r");
	if (pfile3 == NULL) perror("Error opening file");

	do
	{

		// Pegando primeira parte
		x = fgetc(pfile3);
		letter2 = (unsigned char)x;
		// Sair do loop caso tenha acabado o texto
		if (x == EOF)
			break;
		part_one_letter2 = letter2 << 4;
		new_letter2 = part_one_letter2;
		printf("%d\n", part_one_letter2);

		// Pegando segunda parte
		x = fgetc(pfile3);
		letter2 = (unsigned char)x;
		// Sair do loop caso tenha acabado o texto
		if (x == EOF)
			break;
		part_two_letter2 = letter2 << 4;
		part_two_letter2 = part_two_letter2 >> 4;
		printf("%d\n", part_two_letter2);

		// Juntando as partes
		new_letter2 = part_one_letter2 + part_two_letter2;
		printf("%d\n", new_letter2);

		// Escrevendo o texto
		text2.append(1, new_letter2);

	} while (x != EOF);

	fprintf(pfile2, "%s", text2.c_str());
	fclose(pfile2);
	fclose(pfile3);

	return 0;
}