#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList_name.h"
int main()
{
    List information;
    ListInit(&information);
    NameCard * pnc;
    char name1[] = "SYJ"; char name2[] = "KEVIN"; char name3[] = "PARK" ;
    char phone1[] ="2339-6614"; char phone2[]= "4321-8765"; char phone3[] = "789-123";
    pnc = MakeNameCard(name1,phone1);
    LInsert(&information,pnc);
    pnc = MakeNameCard(name2,phone2);
    LInsert(&information,pnc);
    pnc = MakeNameCard(name3,phone3);
    LInsert(&information,pnc);
    //1. 데이터 입력
    char searchto[] = "SYJ";
    char changenameto[] = "PARK";
    char changeto[] ="9999-8888";
    char removeto[] = "KEVIN";
    if(LFirst(&information,&pnc)) //이중포인터니까 입력값은 포인터의 주소값 -> &pnc , 
    {
        int check = 0;
        if(NameCompare(pnc,searchto)== 0)
        { 
            ShowNameCardInfo(pnc);
            
        }
        else
        {
            int check = 0;
            while(LNext(&information,&pnc))
            {
                if(NameCompare(pnc,searchto) == 0)              
                {
                    ShowNameCardInfo(pnc);
                    check =1;
                }

            }
            if(check == 0)  
                printf("2.Can't find \n");

        }
    } //2. 이름을 통해 데이터 출력
    if(LFirst(&information,&pnc))
    {
        int check2 = 0;
        if(NameCompare(pnc,changenameto) == 0)
        {
            ChangePhoneNum(pnc,changeto);
        }
        else
        {
            while(LNext(&information,&pnc))
            {
                
                if(NameCompare(pnc,changenameto) == 0)
                {
                    ChangePhoneNum(pnc,changeto);
                    check2 = 1;
                }
            }
            if(check2 == 0)
                printf("3.Can't find\n");
        }
    }//3.이름을 통해 번호 변경

    if(LFirst(&information,&pnc))
    {
        if(NameCompare(pnc,removeto) == 0)
        {
            pnc = LRemove(&information);
            free(pnc);
        }
        else
        {
            int check1 =0;
            while(LNext(&information,&pnc))
            {
                if(NameCompare(pnc,removeto) == 0)
                {
                    pnc = LRemove(&information);
                    check1 = 1;
                    free(pnc);
                }
            }
            if(check1 == 0)
                printf("3. Can't find \n");
        }
    }//4.이름을 통해 삭제
    printf("Remain \n");
    if(LFirst(&information,&pnc))
    {
        ShowNameCardInfo(pnc);
        while(LNext(&information,&pnc))
        {
            ShowNameCardInfo(pnc);
        }
    }//5.남은만큼 출력
    






//gcc -o 0211 0211.c ArrayList_name.c NameCard.c -g

}


