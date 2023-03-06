#pragma warning(disable: 4996)
#include<stdio.h>

#include"ViewAccount.h"
#include"CreatAccount.h"
#include"MergeAccount.h"
#include"NameChange.h"
//PersonStruct.h 파일은 필요하니 신경써주세요 

int main(){
	ViewAccount(15);//데이터 peple.csv 파일에 있는 명단 중 상위 15명의 정보를 조회합니다. 
	
	CreatAccount();//계좌개설의 기능을 합니다. 여기에서 입력을 하면 new_people.csv 파일로 만들어집니다. 
	MergeAccount();//new_people.csv의 데이터를 people.csv파일와 병합하고 merged.csv파일을 만듭니다. 
	NameChange();//병합하고 난 뒤 오래된 정보를 가지고 있는 people.csv파일을 지우고 merged.csv파일을 people.csv파일로 바꿉니다. 

	return 0;
}
