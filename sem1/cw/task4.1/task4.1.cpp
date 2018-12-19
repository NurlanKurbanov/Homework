#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
using namespace std;


int main()
{
	int n = 0;
	const int maxSize = 256;
	FILE *ptrFile = fopen("doc.txt", "rt");

	if (ptrFile == NULL)
	{
		printf("error");
		return 0;
	}

	int line = 0;
	bool isText = false;
	while (!feof(ptrFile))
	{
		char str[maxSize];
		fgets(str, maxSize, ptrFile);
		int length = strlen(str);
		int i = 0;
		bool haveComment = false;
		for (i = 0; i < length - 1; i++)
		{
			if (str[i] == '/' && str[i + 1] == '*')
			{
				line++;
				break;
			}
			else if (str[i] == '"')
			{
				isText = !isText;
			}

			else if (str[i] == '*' && str[i + 1] == '/')
			{
				line--;
			}

			if (!isText && str[i] == '/' && str[i + 1] == '/')
			{
				haveComment = true;
				break;
			}
		}

		if (haveComment && !line && !isText)
		{
			for (; i < length; i++)
			{
				printf("%c", str[i]);
			}
			printf("\n");
		}
	}
	fclose(ptrFile);
	scanf("%d", line);
}

