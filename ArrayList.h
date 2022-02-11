#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "point1.h"
#define TRUE	1
#define FALSE	0

/*** ArrayList�� ���� ****/
#define LIST_LEN	100
typedef point* LData;
//typedef int LData; -> point.h를 만들어서 :LData에 다른 자료형도 담을 수 있다. -> point구조체로 그 주소를 받아 쓸 수 있으므로

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


/*** ArrayList�� ���õ� ����� ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif