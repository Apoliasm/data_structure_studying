#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void ListInit(List * plist)
{

    plist->curPosition = -1;
    plist->numOfData = 0;
    return ; //listinit는 명령어일뿐 => void 자료형 -> return할 자료형이 정해져 있다면 void가 아닌 다른 자료형으로 써야했을 것
}
void LInsert(List * plist, LData data)
{
    //예외처리 필요
    if (LIST_LEN < plist->numOfData)
    {
        puts("No empty");
        return ;
    }
    
    plist->arr[plist->numOfData] = data;
    plist->numOfData ++;
}

int LFirst(List * plist, LData * pdata)
{

    if(plist->arr[0])
    {
        *pdata = plist->arr[0];
        plist->curPosition = 0;
        //pdata = plist->arr[0]; -> *pdata = 데이터 간접 참조, pdata = 데이터의 주소값 ->포인터의 기본
        return TRUE;
    }
        
    else
    {
        puts("no first");
        return FALSE;
    }

}

int LNext(List * plist, LData * pdata)
{
    if(plist->curPosition >= (plist->numOfData)-1)
        return FALSE;

    else 
    {
        plist->curPosition ++;
        *pdata = plist->arr[plist->curPosition];
        return TRUE;
    }
}

LData LRemove(List * plist)
{
    if(plist->arr[plist->curPosition])
    {
        int curindex = plist->curPosition;
        int numD = plist->numOfData;
        LData cur = plist->arr[plist->curPosition] ;
        for(int i = curindex;i<numD;i++)
        {
            plist->arr[i] = plist->arr[i+1];
        }    
        plist->numOfData --;   
        plist->curPosition --; 
        // 현재 화살표도 한 칸 뒤로 옮겨줘야함 : 아직 참조가 이뤄지지 않았으므로 -> 리스트 자료구조 특징 살리기
        return cur;
    }
    else
    {
        return FALSE;
    }
}

int LCount(List * plist)
{
	return plist->numOfData;
}

