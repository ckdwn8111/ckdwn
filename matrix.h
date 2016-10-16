/*
1. matrix.c ���Ͽ� struct�� �̿��Ͽ� �����͸� �ѹ��� �����
2. struct ������ ��������
3. �Լ��� �Ű������� struct�� �ٲ�
4. printf �ϳ��� �Լ��� ����
5. struct �������� �տ� static ���̱�
*/
#define DEBUG
#ifndef _matrix_h
#define _matrix_h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX 50

struct Array_format {
	int **arrData;
	unsigned short row;
	unsigned short col;
};

void arrayFree(int , int);
void arrayInput( int, int, int, int);
void arrayAdd(int, int);
void arraySubtract(int, int);
void arrayMultiply(int, int, int, int);
void array_2by2_Reverse(void);


#endif