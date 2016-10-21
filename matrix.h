/*
1. matrix.c ���Ͽ� struct�� �̿��Ͽ� �����͸� �ѹ��� �����
2. struct ������ ��������
3. �Լ��� �Ű������� struct�� �ٲ�
4. printf �ϳ��� �Լ��� ����
5. struct �������� �տ� static ���̱�
6. �Է½� ������ �ʱ�ȭ ���ִ��� Ȯ��
*/
#define DEBUG
#ifndef _matrix_h
#define _matrix_h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

struct Array_format {
	int **arrData;
	unsigned int row;
	unsigned int col;
};

void arrayFree(struct Array_format*, struct Array_format*);
void arrayInput(struct Array_format*, struct Array_format*);
struct Array_format arrayAdd(struct Array_format, struct Array_format);
struct Array_format arraySubtract(struct Array_format, struct Array_format);
struct Array_format* arrayMultiply(struct Array_format *, struct Array_format *);
void array_2by2_Reverse(void);
void printArray(struct Array_foramt*);


#endif