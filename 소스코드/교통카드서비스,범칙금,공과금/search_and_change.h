#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"PersonStruct.h"
#include "ViewAccount.h"

int getTotalLine(char* filename) { // csv������ �� ���� ���� �޴� �ڵ�
	FILE* fp;
	int line = 0;
	char c;
	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF)
		if (c == '\n') line++;
	fclose(fp);
	return(line);
}

int search(char* filename, Person* people, Person*person) {// person=ã������ ���� ������ ��Ÿ���� ����ü�迭,people=������ ��ü ������ ���� ����ü �迭
    int accnum, acpw;
    int i=1,j;

    printf("���¹�ȣ�� �Է��ϼ���\n");// ã������ ������ �� ���¹�ȣ
    scanf("%d", &accnum);
    printf("��й�ȣ�� �Է��ϼ���\n");// ã������ ������ �� ��й�ȣ
    scanf("%d", &acpw);

    read_csv_file(filename, people, 100);

    for (j = 0; j < 100; j++)//people�迭 �� person�� ���� ���� �ִ��� Ȯ��
    {
        if (people[j].AccountNumber == accnum)// ���¹�ȣ ������ person�� ����
            *person = people[j];
    }

    view:
    if (person->AccountPW == acpw)// ��й�ȣ�� �ùٸ��� �Է����� ��
    {
        printf("������ ������ �ҷ��ɴϴ�\n");
        printf("%s�� �ܾ�:%d\\\n", person->ClientName, person->NowMoney);
    }

    else
    {
        while (i < 3)// ��й�ȣ�� 3ȸ���� ���� Ʋ���� ��
        {
            printf("��й�ȣ�� %dȸ Ʋ�Ƚ��ϴ�.\n", i);
            if (i < 3) printf("�ٽ� �Է��ϼ���\n");
            scanf("%d", &acpw);
            if (people[i].AccountPW == acpw)
            {
                goto view;
                break;
            }
            i++;
        }
    }
    if (i == 3)//��й�ȣ 3ȸ Ʋ���� �� 1��ȯ
    {
        printf("��й�ȣ�� %dȸ Ʋ�Ƚ��ϴ�\n", i);
        return 1;
    }

    return 0;//�����۵� �� 0 ��ȯ
}

int change(char* filename, Person* people, Person* person) // ������ ������ ���Ͽ� �����ϴ� �ڵ�
{
	read_csv_file(filename, people,100);// people�� ���� ���� ����
	for (int i = 0; i < 100; i++)
	{
		if (people[i].AccountNumber == person->AccountNumber) // ���� ���¹�ȣ�� ���� �ȿ� ���� ��� ��� �ܾ����� ����
		{
			people[i].NowMoney = person->NowMoney;
		}
	}
	FILE* fp = fopen(filename, "w");// ���� ����
	if (fp == NULL) {
		printf("File open error!\n");
		return 1;
	}
	fprintf(fp, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");// ���� ����(���� ����) ���Ͽ� �Է�
	if (people->BankName != NULL)
	{
		for (int i = 0; i < 100 - 1; i++, people++)// ��ü ������ �Է�
		{
			fprintf(fp, "%s,%d,%d,%s,%d,%d,%d,%d,%d\n", people->BankName, people->BankCode, people->ClientCode, people->ClientName, people->CardNumber, people->AccountNumber, people->NowMoney, people->AccountPW, people->AccountDate);
		}
	}
	fclose(fp);// ���� �ݱ�
	return 0;
}