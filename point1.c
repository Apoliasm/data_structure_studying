#include <stdio.h>
#include "point1.h"

void setPointPos(point * ppos,int xpos,int ypos);
//구조체 변수에 값 저장
void showpointpos(point * ppos);
//정보 출력
int pointcomp(point * pos1, point * pos2);
//정보 비교

void setPointPos(point * ppos,int xpos,int ypos)
{
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

void showpointpos (point *ppos)
{
    printf("[x=%d,y=%d]\n",ppos->xpos,ppos->ypos);
}
int pointcomp(point * pos1, point * pos2)
{
    if(pos1->xpos == pos2->xpos)
    {
        if(pos1->ypos == pos2 ->ypos)
        {
            return 0;
        }
        else
            return 1;
    }
    else if(pos1->ypos == pos2->ypos)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}