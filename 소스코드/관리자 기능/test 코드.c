#pragma warning(disable: 4996)
#include<stdio.h>

#include"ViewAccount.h"
#include"CreatAccount.h"
#include"MergeAccount.h"
#include"NameChange.h"
//PersonStruct.h ������ �ʿ��ϴ� �Ű���ּ��� 

int main(){
	ViewAccount(12);//������ people.csv ���Ͽ� �ִ� ��� �� ���� 10���� ������ ��ȸ�մϴ�. �ִ� 100����� ���� �� �ֽ��ϴ�. 
	
	//CreatAccount();//���°����� ����� �մϴ�. ���⿡�� �Է��� �ϸ� new_people.csv ���Ϸ� ��������ϴ�. 
	//MergeAccount();//new_people.csv�� �����͸� people.csv���Ͽ� �����ϰ� merged.csv������ ����ϴ�. 
	//NameChange();//�����ϰ� �� �� ������ ������ ������ �ִ� people.csv������ ����� merged.csv������ people.csv���Ϸ� �ٲߴϴ�. 

	return 0;
}
