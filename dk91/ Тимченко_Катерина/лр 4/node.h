#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//��������������� ����������
typedef struct __CharNode CharNode;

typedef struct __CharNode
{
    int size;
    char *words;
	CharNode *nextNode;
};

//����� ���� �� ��������� int
CharNode *SLCreateNodeWithCharValue(char value[], int aValue);
//������������ ��������� ����
void SLFreeCharNode(CharNode *aNode);

#endif // NODE_H_INCLUDED
