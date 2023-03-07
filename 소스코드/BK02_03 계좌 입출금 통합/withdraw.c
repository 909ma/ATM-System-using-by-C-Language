#include<stdio.h>
#include"ViewAccount.h"
#include"ibchulguem.h"

int main()
{
	Person* people = malloc(sizeof(Person) * 100);
	withdraw("people.csv", people);
	return 0;
}
