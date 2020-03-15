#include <stdio.h>
#include <stdlib.h>
#include "00.info.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	int i;
	INFO data;

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		perror("fopen");
		exit(1);
	}

	while (1)
	{
		if (fread(&data, sizeof(INFO), 1, fp) != 1)
		{
			perror("fwrite");
			fclose(fp);
			exit(2);
		}

		// EOF문자는 window와 linux가 다름
		if (feof(fp))
		{
			break;
		}
		printf("name:%s, age:%d, height:%.1f\n", data.name, data.age, data.height);
	}

	fclose(fp);
	return 0;

}
