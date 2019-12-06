#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include "List_ADT.h"

const short STR_MAX = 41;




void main()

{
	CUSTOMER* cus;
	LIST* list;

	while (1) {

		int flag;
		int i;
		printf("추가 : 1 / 삭제 : 2 / 검색 : 3 / 출력 : 4\n입력 :");

		scanf("%d", &flag);



		switch (flag) {

		case 1:
			addNode(list,cus);

			break;

		case 2:

			printf("삭제할 회원번호를 입력하세요:");

			scanf("%d", &i);

			removeNode(list, &i, cus);

			fflush(stdin);

			break;

		case 3:

			printf("탐색할 회원번호를 입력하세요:");

			scanf("%d", &i);

			searchList(list, &i, cus);

			fflush(stdin);

			break;

		case 4:
			DisplayList(list);


		default:


			printf("잘못된 입력\n");

		}

	}

}
