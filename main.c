//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>

#include"matrix.h"


//extern struct Array_format Array_first;


int main(void) {
	
	struct Array_format array_1 = { .arrData = NULL,.row = 0,.col = 0 };
	struct Array_format array_2 = { .arrData = NULL,.row = 0,.col = 0 };
	int select = 0;
	printf("행령간의 연산은 1번, 2by2 행렬의 역행렬 연산은 2번을 입력하시오 : ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		printf("원하는 첫번째 행렬의 행을 입력하시오 : ");
		scanf("%d", &array_1.row);
		printf("원하는 첫번째 행렬의 열을 입력하시오 : ");
		scanf("%d", &array_1.col);
		printf("원하는 두번째 행렬의 행을 입력하시오 : ");
		scanf("%d", &array_2.row);
		printf("원하는 두번째 행렬의 열을 입력하시오 : ");
		scanf("%d", &array_2.col);

		arrayInput(&array_1, &array_2);
		printArray(&array_1);
		printArray(&array_2);
		break;
	case 2:
		array_2by2_Reverse();
		exit(-1);
	default:
		printf("잘못된 입력입니다.\n");
		exit(-1);
	}

	if (array_1.row == array_2.row && array_1.col == array_2.col) {
		if (array_1.col == array_2.row) {
			printf("사용 가능한 연산자입니다 <+(1), -(2), *(3)> 중 하나를 선택하시오 : ");
			scanf("%d", &select);
			puts("");
			switch (select) {
			case 1:
				array_1 = arrayAdd(array_1, array_2);
				printArray(&array_1);
				break;
			case 2:
				array_1 = arraySubtract(array_1, array_2);
				printArray(&array_1);
				break;
			case 3:
				arrayMultiply(&array_1, &array_2);
				printArray(&array_1);
				break;
			default :
				printf("잘못된 입력입니다.\n");
				exit(-1);
			}
		}
		else {
			printf("사용 가능한 연산자입니다 <+(1), -(2)> 중 하나를 선택하시오 : ");
			scanf("%d", &select);
			puts("");
			switch (select) {
			case 1:
				array_1 = arrayAdd(array_1, array_2);
				printArray(&array_1);
				break;
			case 2:
				array_1 = arraySubtract(array_1, array_2);
				printArray(&array_1);
				break;
			default :
				printf("잘못된 입력입니다.\n");
				exit(-1);
			}
			}
		}
	else {
		if (array_1.col == array_2.row) {
			printf("사용 가능한 연사자가 * 밖에 없습니다 3을 입력해주세요 : ");
			scanf("%d", &select);
			puts("");
			if (select = 3) {
				arrayMultiply(&array_1, &array_2);
				printArray(&array_1);
			}
			else {
				printf("잘못된 입력입니다.\n");
				exit(-1);
			}
		}
		else {
			printf("사용가능한 연산이 없습니다.\n");
			exit(-1);
		}

	}
	arrayFree(&array_1, &array_2);

	return 0;
}

	
	

