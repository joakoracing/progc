#include "tda_nodo.h"
#define MAX_STR 200

int createNode(TDA_Nodo* Node,int commentCount)
{
    int i;
    int k;
    int j = 0;
    Node->Siguiente = NULL;
    Node->comments = (char**) malloc(sizeof(int)*commentCount);
    if(!Node->comments) return RES_MEM_ERROR;

    for(i=0;i<commentCount;i++)
    {
        if(j==0) Node->comments[i]=(char*) malloc(sizeof(char)*MAX_STR+1); /*es + 1 por el \0*/
        if(!Node->comments[i])
        {
            j = i;
        }
    }

    if(j!=0)
    {
        for(k=j;k>=0;--k)
        {
            free(Node->comments[k]);
        }
        free(Node->comments);
        return RES_MEM_ERROR;
    }

    return RES_OK;

}

int setNextNode(TDA_Nodo* Node,TDA_Nodo* nextNode)
{
    Node->Siguiente = nextNode;
    return RES_OK;
}

int setCommentsNode(TDA_Nodo* Node,char** Comments)
{
    Node->comments = Comments;
    return RES_OK;
}

int getCommentsNode(TDA_Nodo Node)
{
    return Node->comments;
}

int getNextNode(TDA_Nodo Node)
{
    return Node->Siguiente;
}

int destroyNode(TDA_Nodo* Node)
{
    int i = 0;
    int pcomLen = 0;

    Node->Siguiente = NULL;
    pcomLen = strlen(Node->comments);

    if(pcomLen==0)
    {
        free(Node->comments);
    }
    else
    {
        for(i=pcomLen;i>=0;--i)
        {
            free(Node->comments[i]);
        }
        free(Node->comments);
    }
    return RES_OK;
}


