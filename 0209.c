#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "point1.h"

int main()
{
    List l1; //리스트 : 나열하는 구조, 중복을 허용하는 구조 ->순차적으로 삽입,제거/ 순차적으로 보기 위한 장치들
    point comppos;
    point * ppos; //동적 메모리 할당으로 데이터를 생성하기 위함
    ListInit(&l1); //create list

    ppos = (point*)malloc(sizeof(point));//1.담을 데이터에 대한 동적 메모리 할당 
    //->리스트가 *point자료형이라서 각각의 주소를 받음
    printf("%d\n",sizeof(ppos));
    setPointPos(ppos,2,1);//2.데이터의 구체적인 입력
    LInsert(&l1,ppos); //3.리스트에 순차적인 삽입

    ppos = (point*)malloc(sizeof(point));//1.담을 데이터에 대한 동적 메모리 할당
    printf("%d\n",sizeof(ppos));
    setPointPos(ppos,2,2);//2.데이터의 구체적인 입력
    LInsert(&l1,ppos); //3.리스트에 순차적인 삽입

    ppos = (point*)malloc(sizeof(point));//1.담을 데이터에 대한 동적 메모리 
    printf("%d\n",sizeof(ppos));
    setPointPos(ppos,3,1);//2.데이터의 구체적인 입력
    LInsert(&l1,ppos); //3.리스트에 순차적인 삽입
    
    ppos = (point*)malloc(sizeof(point));//1.담을 데이터에 대한 동적 메모리 할당
    printf("%d\n",sizeof(ppos));
    setPointPos(ppos,3,2);//2.데이터의 구체적인 입력
    LInsert(&l1,ppos); //3.리스트에 순차적인 삽입    

    printf("%d\n",LCount(&l1));

    if(LFirst(&l1,&ppos)) //LData *pdata -> 포인터 변수를 받으니 입력값은 주소값 = *ppos의 변수명 = 주소값 -> ppos(no asterisk)
    {                     //typedef point* LData -> LData * = point**->받을 주소값? ppos = *point의 주소값 -> &ppos
        showpointpos(ppos);
        while(LNext(&l1,&ppos))
        {
            showpointpos(ppos);
        }

    }
    comppos.xpos = 2;
    comppos.ypos = 0;
    //xpos == 2 -> remove it
    
    if(LFirst(&l1,&ppos))
    {
        if(pointcomp(ppos,&comppos) == 1)
        {
            ppos = LRemove(&l1); //LRemove가 제외한 데이터를 return하는 이유 : 할당한 메모리를 지우기 위함 -> point* ppos 
            free(ppos);             //동시에 typedef *point LData;인 이유 : 자유롭게 구조체 주소를 지우기 위함? -> 효율적인 관리
        }

        while(LNext(&l1,&ppos))
        {
            if(pointcomp(ppos,&comppos) == 1)
            {
                ppos = LRemove(&l1);
                free(ppos);
            }

        }
        
    }
    printf("%d\n",LCount(&l1));
    if(LFirst(&l1,&ppos)) //LData *pdata -> 포인터 변수를 받으니 입력값은 주소값 = *ppos의 변수명 = 주소값 -> ppos(no asterisk)
    {                     //typedef point* LData -> LData * = point**->받을 주소값? ppos = *point의 주소값 -> &ppos
        showpointpos(ppos);
        while(LNext(&l1,&ppos))
        {
            showpointpos(ppos);
        }

    }

//gcc -o 0209 0209.c ArrayList.c point1.c
}