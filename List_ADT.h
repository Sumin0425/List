#include<stdio.h>
#pragma once
#include<stdlib.h>

typedef struct {
	char name[30];
	char phone[30];
	int number;
}CUSTOMER;

typedef struct node {
	struct CUSTOMER* dataptr;
	struct node*link;
}NODE;

typedef struct {
	int count;
	NODE* pos;
	NODE* head;
	NODE* rear;
	NODE* here;
	int(*compare)(void* argu1, void*argu2);
}LIST;

bool _search(LIST* pList, NODE** pPre, NODE** pLoc, CUSTOMER*pArgu)
{

	CUSTOMER* n = (*pLoc)->dataptr;
	CUSTOMER* m = pList->rear->dataptr;
#define COMPARE \
(((*pList->compare)(pArgu->number,n->number)))

#define COMPARE_LAST \
((*pList->compare)(pArgu,m->number))

	int result;

	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->count == 0)
		return false;

	if (COMPARE_LAST > 0)
	{
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	}

	while ((result = COMPARE) > 0)
	{
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}

	if (result == 0)
		return true;

	else
		return false;
}

static bool _insert(LIST* pList, NODE*pPre, struct CUSTOMER * dataInPtr)
{
	NODE*pNew;
	if (!(pNew = (NODE*)malloc(sizeof(NODE))))
		return false;

	pNew->dataptr = dataInPtr;
	pNew->link = NULL;

	if (pPre == NULL)
	{
		pNew->link = pList->head;
		pList->head = pNew;
		if (pList->count == 0)
			pList->rear = pNew;
	}
	else {

		if (pNew->link = NULL)
			pList->rear = pNew;
	}

	(pList->count)++;
	return true;

}
LIST* createList(int(*compare)(void* argu1, void* argu2))
{
	LIST* list;
	list = (LIST*)malloc(sizeof(LIST));
	if (list)
	{
		list->head = NULL;
		list->pos = NULL;
		list->rear = NULL;
		list->count = 0;
		list->compare = compare;
	}

	return list;
}

int addNode(LIST* pList, CUSTOMER*dataInPtr)
{

	bool found;
	bool success;

	NODE*pPre;
	NODE*pLoc;

	printf("이름 : ");

	scanf("%s", &(dataInPtr->name));

	fflush(stdin);

	printf("전화번호 : ");

	scanf("%s", &(dataInPtr->phone));

	fflush(stdin);

	printf("회원번호 : ");

	scanf("%d", &(dataInPtr->number));

	fflush(stdin);



	found = _search(pList, &pPre, &pLoc, dataInPtr);
	if (found)
		return(+1);

	success = _insert(pList, pPre, dataInPtr);
	if (!success)
		return(-1);

	return(0);
}



bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr)
{
	bool found;
	NODE* pPre;
	NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, keyPtr);
	if (found)
_delete(pList, pPre, pLoc, dataOutPtr);

return found;
}
void _delete(LIST*pList, NODE*pPre, NODE*pLoc, void*dataOutPtr)
{
	dataOutPtr = pLoc->dataptr;
	if (pPre = NULL)
		pList->head = pLoc->link;

	if (pLoc->link == NULL)
		pList->rear = pPre;

	(pList->count)--;
	free(pLoc);

	return;
}

bool searchList(LIST* pList, void*pArgu, CUSTOMER* pDataOut)
{
	bool found;
	NODE* pPre;
	NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found)
	{
		pDataOut = pLoc->dataptr;

		printf("%s ,%d ,%s ", pDataOut->name, pDataOut->number, pDataOut->phone);
	}
	else
	{
		pDataOut = NULL;

		printf("존재하지 않습니다");
	}
	return found;
}



static bool retrieveNode(LIST* pList, void*pArgu, void** dataOutPtr)
{
	bool found;
	NODE* pPre;
	NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found) {
		*dataOutPtr = pLoc->dataptr;
		return true;
	}

	*dataOutPtr = NULL;
	return false;

}

bool emptyList(LIST* pList)
{
	return(pList->count == 0);
}

int listCount(LIST*pList)
{
	return pList->count;
}

bool fullList(LIST*pList)
{
	NODE* temp;

	if ((temp) = (NODE*)malloc(sizeof(*(pList->head))))
	{
		free(temp);
		return false;
	}

	return true;
}

bool traverse(LIST* pList, int fromWhere, void** dataPtrOut)
{
	if (pList->count == 0)
		return false;

	if (fromWhere == 0)
	{
		pList->pos = pList->head;
		*dataPtrOut = pList->pos->dataptr;
		return true;
	}
	else
	{
		if (pList->pos->link == NULL)
			return false;
		else {
			pList->pos = pList->pos->link;
			*dataPtrOut = pList->pos->dataptr;
			return true;
		}

	}
}

LIST* destroyList(LIST* pList)
{
	NODE* deletePtr;

	if (pList)
	{
		while (pList->count > 0)
		{
			free(pList->head->dataptr);

			deletePtr = pList->head;
			pList->head = pList->head->link;
			pList->count--;
			free(deletePtr);
		}
		free(pList);
	}
	return NULL;
}


void DisplayList(LIST* list)

{

	printf("Display all element : ");


	list->here = list->head;

	while (list->here!= NULL) {
		list->here = list->pos;

		
		CUSTOMER* n = list->here->dataptr;

		printf("이름:%s 전화번호%s 회원번호:%d", n->name,n->phone,n->number);

		list->here=list->pos;

	}

}
