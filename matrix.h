/*
1. matrix.c 파일에 struct를 이용하여 데이터를 한번에 모아줌
2. struct 변수는 전역변수
3. 함수별 매개변수가 struct로 바뀜
4. printf 하나의 함수로 빼기
5. struct 전역번수 앞에 static 붙이기
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