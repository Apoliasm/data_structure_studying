#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
#include <stdio.h>
#include "point1.h"
typedef struct _node //typedef 1.노드, 노드 :데이터,다음 데이터 화살표
{
    point* data;
    struct _node* next;
}node; 
typedef point* LData; //typedef 2.노드 안에 들어갈 데이터(실제 내용물) -> int가 아닌 다른거로 변형 가능
//연결리스트가 몇 개 쓰일지 당연히 모른다 -> 구조체로 묶어두기
typedef struct _dlist//typedef 3.연결리스트 -> head,current,데이터 수 확인,
{
    node* head ;
    node* current ;
    node* before ;
    int numofdata;
    int (*comp) (LData d1,LData d2); //정렬할 함수 입력: 함수 포인터로 함수의 주소를 받고 int로 return.

}dlist;
typedef dlist Dlist;

void ListInit (Dlist* list);
//연결 리스트 생성
void LInsert (Dlist* list,LData data);
//데이터 삽입
int LFirst (Dlist* list,LData* receive);
//첫 데이터 가리킴
int LNext (Dlist* list,LData* receive);
//다음 데이터 가리킴
LData LRemove (Dlist* list);
//특정 노드 삭제
int Lcount(Dlist* list);
//노드의 수 세기
void Set_Sort_rule(Dlist* list,int (*comp)(LData d1, LData d2));
//노드를 정렬하는 규칙 설정 -> int (*comp) =함수 포인터 = 함수의 주소값이 결과인 함수 -> 함수의 주소값을 입력해서 결과값 int를 출력
void LInsert2(Dlist *list,LData data);

#endif