#include <stdio.h>
#include "NameCard.h"
#include <stdlib.h>
#include <string.h>
#include "ArrayList_name.h"
/*
typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;
*/

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * MakeNameCard(char * name, char * phone);
   
// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard);
   
// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * pcard, char * name);
   
// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone);

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
//사전작업 : ArrayList_name.h -> typedef Namecard* LData; 데이터를 저장하기 위한 기본 양식 수정
//1.구조체를 위한 메모리 주소를 할당, 2.구조체에 데이터 입력, 3.할당한 주소 반환 -> by address, data can be inserted to list.
NameCard * MakeNameCard(char * name, char * phone)
{
    NameCard* nc;
    nc = (NameCard*)malloc(sizeof(NameCard));
    strcpy(nc->name,name);
    strcpy(nc->phone,phone);
    return nc; //NameCard* nc의 주소값 = nc

    //굳이 길이 구해서 for문으로 하나씩 붙여넣기 x 
    //string.h의 strcpy로 문자열 그대로 복사 붙여넣기 한번에 하기

    /*int s_name = strlen(name);
    int s_phone = strlen(phone);
    for(int i = 0;i<s_name;i++)
    {
        *(nc->name + i) = *(name + i);
    }

    for(int j = 0 ; j<s_phone;j++)
    {
        *(nc->phone + j) = *(phone + j);
    }*/
    
}

// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard) //구조체 주소를 통한 간접 참조
{
    printf("%s\n",pcard->name);
    printf("%s\n",pcard->phone);
}

// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * pcard, char * name)
{
    if(*(pcard->name) == *name)
    {
        return 0;
    }
    else
        return 1;
}

// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone)
{
    if(pcard)
    {
        strcpy(pcard->phone,phone);
    }
    else
        printf("Error:  doesnt exist\n");

}



