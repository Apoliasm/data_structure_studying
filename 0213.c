#include <stdio.h>
#include <stdlib.h>
#include "D_linkedlist.h"
#include "point1.h"

int compare (LData one, LData two)
{

    if((one->xpos < two->xpos) || ((one->xpos == two->xpos)&&(one->ypos <two->ypos)))
    {
        return 1;
    }
    else
        return 2;
}//정렬방식 구체화 : x의 오름차순대로 하겠다는 의미, x가 같으면 y 오름차순
    
int main()
{
    //1. 넣은 순서대로 만든 연결리스트
    Dlist d_list;    //Dlist*로 주소값 참조가 아닌 직접 참조의 이유는? ->동적 메모리 할당이 아니라서?
    //직접참조로 생성 되는 것:주소값을(포인터변수) 담을 그릇, 정수를 담을 그릇 -> 굳이 동적할당 필요 x?
    //동적메모리할당을 하는 이유 : 리스트 같이 크기가 불분명한 것에 대한 효율적인 메모리 관리
    //주소값들을 담을 껍데기인 구조체에 할 필요는 없다 : 사실 다 일반 변수이므로 크기가 무관함
    //결론 : 그 자료형이 무엇인지에 따라 동적메모리할당을 할지 변수지정을 할지 정하기
    ListInit(&d_list);
    //함수 포인터 (변수이름에 괄호친 형태) : 함수의 주소를 받아서 그 함수를 쓰겠다는 의미
    //그 함수의 parameters는 
    point* ppo; //동적할당 받고 함수에 활용하기 위한 포인터변수 선언 

    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,2,1);
    LInsert(&d_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,22,1);
    LInsert(&d_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,22,33);
    LInsert(&d_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,2,33);
    LInsert(&d_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,5,6);
    LInsert(&d_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,2,4);
    LInsert(&d_list,ppo);


    point* receiveto ;
    receiveto = (point*)malloc(sizeof(point));
    Lcount(&d_list);
    if(LFirst(&d_list,&receiveto))//LData * = point** ->point* = receiveto
    {
        showpointpos(receiveto);
        while(LNext(&d_list,&receiveto))
        {
            showpointpos(receiveto);
        }
    }

    //2.정렬 룰에 따른 연결리스트
    Dlist sorted_list;
    ListInit(&sorted_list);
    Set_Sort_rule(&sorted_list,&compare); //int (*comp) (LData data1, LData data2) 함수 포인터 입력값 = 함수의 주소
    
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,55,7);
    LInsert2(&sorted_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,44,7);
    LInsert2(&sorted_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,66,8);
    LInsert2(&sorted_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,55,6);
    LInsert2(&sorted_list,ppo);
    ppo = (point*)malloc(sizeof(point));
    setPointPos(ppo,11,7);
    LInsert2(&sorted_list,ppo);    
    
    if(LFirst(&sorted_list,&receiveto))
    {
        showpointpos(receiveto);
        while(LNext(&sorted_list,&receiveto))
        {
            showpointpos(receiveto);
        }
    }
    
}
/*
gcc -o 0213 0213.c D_linkedlist.c point1.c -g
*/