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
		printf("�߰� : 1 / ���� : 2 / �˻� : 3 / ��� : 4\n�Է� :");

		scanf("%d", &flag);



		switch (flag) {

		case 1:
			addNode(list,cus);

			break;

		case 2:

			printf("������ ȸ����ȣ�� �Է��ϼ���:");

			scanf("%d", &i);

			removeNode(list, &i, cus);

			fflush(stdin);

			break;

		case 3:

			printf("Ž���� ȸ����ȣ�� �Է��ϼ���:");

			scanf("%d", &i);

			searchList(list, &i, cus);

			fflush(stdin);

			break;

		case 4:
			DisplayList(list);


		default:


			printf("�߸��� �Է�\n");

		}

	}

}
