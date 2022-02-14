#include <stdio.h>
#include <stdlib.h>
#include "D_linkedlist.h"
#include "point1.h"


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

 //중요!:연결 리스트의 인덱스는 노드가 어디로 향하는가로 구분한다! ->새로운 사고방식에 적응하기! 


void ListInit (Dlist* list)
//연결 리스트 생성
{
    list->head = (node*)malloc(sizeof(node)); //리스트 생성 시 더미노드를 head에 생성
    list->head->next = NULL;
    list->before = NULL;
    list->current = NULL;
    list->numofdata = 0;
    list->comp = NULL;
}
void LInsert (Dlist* list,LData data)
//넣은 순서대로 삽입
{
    if(list->comp == NULL)//정렬 기준이 없을 때와 있을 때 나누기 ->기준 있으면 머리에 노드 추가시키기
    {
        node * newcode = (node*)malloc(sizeof(node));//노드 추가 = 메모리 할당
        newcode->data=data;                         // 새 노드에 데이터,화살표 추가
        newcode->next = list->head->next;           // 가장 최근에 추가된 노드의 위치는 항상 같으므로 list.head.next
        list->head->next=newcode;                   
        list->numofdata++;
        //1.함수 안에 새로운 변수 지정 후 동적 메모리할당 
        //2.메모리할당한 주소값을 input한 list 주소값에 박아 넣음
        //결과 : newcode는 사라지지만 heap(동적메모리할당으로 할당해놓은 메모리)은 안사라짐
        //       할당한 heap 메모리의 주소를 저장해놓음 = 함수가 종료되더라도 힙의 주소는 남으므로 유지 가능   
        //결론 : 새롭게 동적메모리 할당 후에 할당한 주소만 input pointer에 잘 저장만 해놓으면 문제 없음
    }
    else
    {
        //
    }
}

int LFirst (Dlist* list,LData* receive)
//첫 데이터 가리킴 = dummy
{
    if(list->head->next == NULL)    
    {
        printf("LFIRST IS NULL\n");
        return 0;
    }
    else//true에서 return했으면 굳이 else를 안 써도 된다
    {
        list->current=list->head->next;
        list->before=list->head; //LRemove에서 구현해도 좋을 듯 하지만, 지속적인 데이터 갱신을 위해
        *receive = list->current->data;
        //receive = list.current.data가 아닌 이유? ->  *receive가 실 내용에 영향을 미치고, receive는 주소값일 뿐이므로
        return 1;
    }
}
int LNext (Dlist* list,LData* receive)
//다음 데이터 가리킴
{
    if(list->current->next == NULL)
    {
        printf("LNEXT IS NULL\n");
        return 0;
    }
    else
    {
        list->before=list->current;
        list->current=list->current->next; //current를 정의한 후 current 이용하는 게 훨씬 코드가 깔끔한게 당연하다.
        *receive = list->current->data; //정의 후 이용하기,그 역순은 x
        return 1;
    }

}
LData LRemove (Dlist* list)
//특정 노드 삭제
{
    node* removeto = list->current; 
    LData datatoremove = removeto->data;
    list->before->next = list->current->next;    
    list->current=list->before;//삭제 후 current를 그 전으로 되돌리기
    list->numofdata --;
    free(removeto); //메모리 할당 제거? -> 연결리스트가 직접할 일이 아닌가?
    return datatoremove;//제거할 데이터 return = 제거할 데이터의 주소값,정보 등등
}
//기본적 코드 작성 순서 : 1.새 변수 선언, 2.기존 변수에 대해 새로운 선언, 3.변수에 대한 행동들 작성

int Lcount(Dlist* list)
//노드의 수 세기
{
    return list->numofdata;
}
void LInsert2(Dlist *list,LData data)
//compare 함수에 따라서 정렬 = 값을 대소가 정렬 기준이 point의 xpos값, x가 같으면 y 순서대로
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    node *tempnode = list->head;
    while((tempnode->next != NULL) && (list->comp(tempnode->next->data,newnode->data) == 1))
    {
        tempnode = tempnode->next;
    }
    newnode->next = tempnode->next;
    tempnode->next = newnode;
}
void Set_Sort_rule(Dlist* list,int (*comp)(LData d1, LData d2))
//노드를 정렬하는 규칙 설정 -> int (*comp) =함수 포인터 = 함수의 주소값이 결과인 함수 -> 함수의 주소값을 입력해서 결과값 int를 출력
//main함수에서 정렬 방식을 지정하면 그 함수의 주소값을 받아와 d_list 구조체에 초기화
{
    list->comp = comp;
}

