#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
	FILE* pf;
	pf= fopen(argv[2], "r");
	int count = 0;
	if (pf == NULL)
	{
		puts("Error!!\n");
		return 0;
	}
	if (argv[1][1] == 'w')
	{
		char str[1024];
		while (fscanf(pf, "%str", str) != EOF)
		{
			count++;
			for (int i = 1; i < strlen(str) - 1; i++)
				if (str[i] == ',' && str[i - 1] != ',' && str[i + 1] != ',')
					count++;
		}
		printf("µ¥´ÊÊý=%d\n", count);
	}
	else if (argv[1][1] == 'c')
	{
		char c;
		while ((c = fgetc(pf)) != EOF) count++;
		printf("×Ö·ûÊý=%d", count);
	}
	fclose(pf);
	return 0;
}
