#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int getTotalLine(char* filename) { // csv파일의 총 라인 수를 받는 코드
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	fclose(fp);
	return(line);
}
int voicefishing()
{
	int answer;
ReFishing:
	printf("\n\n\n\n※※※※※※보이스피싱 피해예방 안내※※※※※※\n\n");
	printf("검찰, 경찰, 금융감독원이나 모르는 사람이 전화로\n");
	printf("출금 및 이체를 요청하셨습니까?\n\n\n");
	printf("1. 예\t\t 2. 아니오\n");
	printf("\n선택 : ");
	scanf_s("%d", &answer);
	if (answer == 1)
		return 1;
	else if (answer == 2)
		return 2;
	else
	{
		printf("다시 입력하세요\n");
		goto ReFishing;
	}

}