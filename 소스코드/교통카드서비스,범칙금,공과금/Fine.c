#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#include "PersonStruct.h"
#include "change.h"



int main()
{
	Person person;
	Person* people = malloc(sizeof(Person) * 100);
	int a;
	a = search("people.csv", &person, 100);
	if (a == 0)
	{
		Fine(&person);
		change("people.csv", people, &person);
	}
	else
		printf("결제가 취소되었습니다.\n");

	free(people);

	return 0;
}