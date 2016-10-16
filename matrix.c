#include "matrix.h"
#include <time.h>
#include <stdlib.h>

int **Array_first = NULL;
int **Array_second = NULL;
int i, j = 0;

//struct Array_format Array_first;
//struct Array_format Array_second;

void arrayInput(int row, int col, int row_2, int col_2) {

	 //struct Array_format array_1 = { .arrData = NULL,.row = 0,.col = 0 };
		srand(time(NULL));
		Array_first = (int **)malloc(sizeof(int *)*row);

		for (i = 0; i < row; i++) {
			Array_first[i] = (int *)malloc(sizeof(int)*col);
		}
		if (Array_first == NULL) {
			printf("Heap is full");
			exit(-1);
		}

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				Array_first[i][j] = (rand() % MAX + 1);
				if (Array_first == NULL) {
					printf("Heap is full");
					exit(-1);
				}
			}
		}

		Array_second = (int **)malloc(sizeof(int *)*row_2);

		for (i = 0; i < row_2; i++) {
			Array_second[i] = (int *)malloc(sizeof(int)*col_2);
		}
		if (Array_second == NULL) {
			printf("Heap is full");
			exit(-1);
		}
		for (i = 0; i < row_2; i++) {
			for (j = 0; j < col_2; j++) {
				Array_second[i][j] = (rand() % MAX + 1);
				if (Array_second == NULL) {
					printf("Heap is full");
					exit(-1);
				}
			}
		}

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				Array_first[i][j] = (rand() % MAX + 1);
			}
		}

		Array_second = (int **)malloc(sizeof(int *)*row_2);

		for (i = 0; i < row_2; i++) {
			Array_second[i] = (int *)malloc(sizeof(int)*col_2);
		}

		for (i = 0; i < row_2; i++) {
			for (j = 0; j < col_2; j++) {
				Array_second[i][j] = (rand() % MAX + 1);
			}
		}

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				printf("%5d  ", Array_first[i][j]);
			}
			puts("");
		}

		puts("");

		for (i = 0; i < row_2; i++) {
			for (j = 0; j < col_2; j++) {
				printf("%5d  ", Array_second[i][j]);
			}
			puts("");
		}

		puts("");

}


void arrayFree(int row, int row_2) {
	
	
	int i = 0;
	for (i = 0; i < row; i++) {
		free(Array_first[i]);
	}
	free(Array_first);

	for (i = 0; i < row_2; i++) {
		free(Array_second[i]);
	}
	free(Array_second);

}

void arrayAdd(int row, int col) {

	int i, j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			Array_first[i][j] = Array_first[i][j] + Array_second[i][j];
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d  ", Array_first[i][j]);
		}
		puts("");
	}
	puts("");

}

void arraySubtract(int row, int col) {

	int i, j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			Array_first[i][j] = Array_first[i][j] - Array_second[i][j];
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d  ", Array_first[i][j]);
		}
		puts("");
	}
	puts("");

}

void arrayMultiply(int row, int col, int row_2, int col_2) {

	int i, j, k = 0;
	int **result = NULL;

	result = (int**)malloc(sizeof(int*)*row);

	if (result == NULL) {
		printf("result가 동적할당 안됨...죽음... ㅠㅠ");
		return;
	}

	for (i = 0; i < row; i++) {
		result[i] = (int*)malloc(sizeof(int)*col_2);
		if (result[i] == NULL) {
			printf("result가 동적할당 안됨...죽음... ㅠㅠ");
			return;
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col_2; j++) {
			result[i][j] = 0;
		}
	}

	for (k = 0; k < row; k++) {
		for (j = 0; j < col_2; j++) {
			for (i = 0; i < col; i++) {
				result[k][j] += Array_first[k][i] * Array_second[i][j];
			}
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col_2; j++) {
			printf("%5d  ", result[i][j]);
		}
		puts("");
	}

	for (i = 0; i < row; i++) {
		free(result[i]);
	}
	free(result);
}

void array_2by2_Reverse(void){

	int i, j, k = 0;
	double num = 0;
	double Array[2][2] = { 0.0, };
	double Array_reverse[2][2] = { 0.0, };
	double Array_result[2][2] = { 0.0, };
	double temp = 0;
	printf("2 by 2 행렬의 인덱스 값을 입력하시오 : ");


	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			scanf("%lf", &Array[i][j]);
		}
	}

	temp = Array[0][0] * Array[1][1] - Array[0][1] * Array[1][0];

	if (temp == 0) {
		printf("det(A) = 0 이므로 역행렬을 구할 수 없습니다.");
		return 0;
	}

	puts("");
	printf("입력한 행렬 => \n");

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%5lf  ", Array[i][j]);
		}
		puts("");
	}

	puts("");
	puts("");

	puts("역행렬 => \n");

	num = (1 / temp);


	Array_reverse[0][0] = Array[1][1];
	Array_reverse[0][1] = -Array[0][1];
	Array_reverse[1][0] = -Array[1][0];
	Array_reverse[1][1] = Array[0][0];

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			Array_reverse[i][j] = num * Array_reverse[i][j];
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%5lf  ", Array_reverse[i][j]);
		}
		puts("");
	}

	puts("");
	printf("입력한 행렬 X 역행렬 = \n\n");

	for (k = 0; k < 2; k++) {
		for (j = 0; j < 2; j++) {
			for (i = 0; i < 2; i++) {
				Array_result[k][j] += Array[k][i] * Array_reverse[i][j];
			}
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%5lf  ", Array_result[i][j]);
		}
		puts("");
	}

}


	
