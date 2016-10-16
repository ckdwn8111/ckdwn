//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
#include"matrix.h"


//extern struct Array_format Array_first;


int main(void) {
	
	int row, col, row_2, col_2, select = 0;
	
		printf("원하는 첫번째 행렬의 행을 입력하시오 : ");
		scanf("%d", &row);
		printf("원하는 첫번째 행렬의 열을 입력하시오 : ");
		scanf("%d", &col);
		printf("원하는 두번째 행렬의 행을 입력하시오 : ");
		scanf("%d", &row_2);
		printf("원하는 두번째 행렬의 열을 입력하시오 : ");
		scanf("%d", &col_2);
		puts("");

		arrayInput(row, col, row_2, col_2);

		if (row == row_2 && col == col_2) {
			if (col == row_2) {
				printf("사용 가능한 연산자입니다 <+(1), -(2), *(3)> 중 하나를 선택하시오 : ");
				scanf("%d", &select);
				puts("");
				if (select < 1 || select > 3) {
					printf("잘못된 입력입니다.\n");
					exit(-1);
				}
			}
			else {
				printf("사용 가능한 연산자입니다 <+(1), -(2)> 중 하나를 선택하시오 : ");
				scanf("%d", &select);
				puts("");
				if (select < 1 || select > 2) {
					printf("잘못된 입력입니다.\n");
					exit(-1);
				}
			}
		}
		else {
			if (col == row_2) {
				printf("사용 가능한 연사자가 * 밖에 없습니다 3을 입력해주세요 : ");
				scanf("%d", &select);
				puts("");
				if (select != 3) {
					printf("잘못된 입력입니다.\n");
					exit(-1);
				}
			}
			else {
				printf("사용가능한 연산이 없습니다.\n");
				exit(-1);
			}

		}

		switch (select) {
		case 1:
			arrayAdd(row, col);
			break;
		case 2:
			arraySubtract(row, col);
			break;
		case 3:
			arrayMultiply(row, col, row_2, col_2);
			break;
		}
		arrayFree(row, row_2);
	
		array_2by2_Reverse();
		return 0;
}

	
	

