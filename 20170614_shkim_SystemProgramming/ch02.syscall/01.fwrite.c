#include <stdio.h>
#include <stdlib.h>
#include "00.info.h"

int main(int argc, char *argv[])
{
	INFO data[5] = { "kim", 20, 170.1F,
					 "lee", 25, 180.3F,
					 "park", 21, 176.2F,
					 "choi", 28, 167.9F,
					 "kang", 25, 172.5F };
	FILE *fp;
	int i;

	if ((fp = fopen(argv[1], "wb")) == NULL)
	{
		perror("fopen");
		exit(1);
	}

#if 1
	// 5번 루프를 돌면서 레코드 1개씩 저장
	for(i=0; i<5; i++)
	{
		if(fwrite(&data[i], sizeof(INFO), 1, fp) != 1 ) {
			perror("fwrite");
			fclose(fp);
			exit(2);
		}
	}
#else
	// 한번에 저장
	if (fwrite(&data[0], sizeof(INFO), 5, fp) != 5)
	{
		perror("fwrite");
		fclose(fp);
		exit(2);
	}
#endif

	fclose(fp);
	return 0;
}
