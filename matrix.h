/*
1. matrix.c 파일에 struct를 이용하여 데이터를 한번에 모아줌
2. struct 변수는 전역변수
3. 함수별 매개변수가 struct로 바뀜
4. printf 하나의 함수로 빼기
5. struct 전역번수 앞에 static 붙이기
6. 입력시 변수가 초기화 되있는지 확인
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