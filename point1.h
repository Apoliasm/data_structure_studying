#ifndef __POINT1_H__
#define __POINT1_H__

typedef struct _point
{
    int xpos;
    int ypos;
}point;


void setPointPos(point * ppos,int xpos,int ypos);

void showpointpos(point * ppos);

int pointcomp(point * pos1, point * pos2);



#endif