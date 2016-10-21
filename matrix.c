#include "matrix.h"
#include <time.h>
#include <stdlib.h>


static int i, j, k = 0;



void arrayInput(struct Array_format *Array_first_p, struct Array_format *Array_second_p) {

		
		srand(time(NULL));
		
		Array_first_p -> arrData = (int **)malloc(sizeof(int *)*(Array_first_p -> row));

		if (Array_first_p->arrData == NULL) {
			printf("Heap is full");
			exit(-1);
		}

		for (i = 0; i < Array_first_p->row; i++) {
			(Array_first_p->arrData)[i] = (int *)malloc(sizeof(int)*(Array_first_p -> col));
			if (Array_first_p -> arrData == NULL) {
				printf("Heap is full");
				exit(-1);
			}
		}
		


		for (i = 0; i < Array_first_p -> row; i++) {
			for (j = 0; j < Array_first_p -> col; j++) {
				(Array_first_p->arrData)[i][j] = (rand() % MAX + 1);
				
			}
		}

		Array_second_p -> arrData = (int **)malloc(sizeof(int *)*(Array_second_p -> row));
		
		if (Array_second_p->arrData == NULL) {
			printf("Heap is full");
			exit(-1);
		}

		for (i = 0; i < (Array_second_p->row); i++) {
			(Array_second_p->arrData)[i] = (int *)malloc(sizeof(int)*(Array_second_p->col));
			if (Array_second_p->arrData == NULL) {
				printf("Heap is full");
				exit(-1);
			}
		}
		
		for (i = 0; i < (Array_second_p->row); i++) {
			for (j = 0; j < Array_second_p -> col; j++) {
				(Array_second_p -> arrData)[i][j] = (rand() % MAX + 1);
			}
		}
	

}


void arrayFree(struct Array_format *Array_first_p, struct Array_format *Array_second_p) {
	
	

	for (i = 0; i < Array_first_p -> row; i++) {
		free(Array_first_p -> arrData[i]);
	}
	free(Array_first_p -> arrData);

	for (i = 0; i < Array_second_p -> row; i++) {
		free(Array_second_p -> arrData[i]);
	}
	free(Array_second_p -> arrData);

	
	
}


struct Array_format arrayAdd(struct Array_format Array_first, struct Array_format Array_second) {



	for (i = 0; i < Array_first.row; i++) {
		for (j = 0; j < Array_first.col; j++) {
			Array_first.arrData[i][j] = Array_first.arrData[i][j] + Array_second.arrData[i][j];
		}
	}

	
	return Array_first;

}

struct Array_format arraySubtract(struct Array_format Array_first, struct Array_format Array_second) {

	

	for (i = 0; i < Array_first.row; i++) {
		for (j = 0; j < Array_first.col; j++) {
			Array_first.arrData[i][j] = Array_first.arrData[i][j] - Array_second.arrData[i][j];
		}
	}

	
	return Array_first;

}

struct Array_format* arrayMultiply(struct Array_format *Array_first_p, struct Array_format *Array_second_p) {

	
	int **result = NULL;

	result = (int**)malloc(sizeof(int*)*(Array_first_p->row));

	if (result == NULL) {
		printf("Heap is full");
		exit(-1);
	}

	for (i = 0; i < Array_first_p->row; i++) {
		result[i] = (int*)malloc(sizeof(int)*(Array_second_p->col));
		if (result[i] == NULL) {
			printf("Heap is full");
			exit(-1);
		}
	}

	for (i = 0; i < Array_first_p->row; i++) {
		for (j = 0; j < Array_second_p->col; j++) {
			result[i][j] = 0;
		}
	}

	for (k = 0; k < Array_first_p->row; k++) {
		for (j = 0; j < Array_second_p->col; j++) {
			for (i = 0; i < Array_first_p->col; i++) {
				result[k][j] += (Array_first_p -> arrData[k][i]) * (Array_second_p -> arrData[i][j]);
			}
		}
	}

	for (i = 0; i < Array_first_p->row; i++) {
		free(Array_first_p->arrData[i]);
	}
	free(Array_first_p->arrData);

	Array_first_p->arrData = (int**)malloc(sizeof(int*)*(Array_first_p->row));
	if (Array_first_p->arrData == NULL) {
		printf("Heap is full");
		exit(-1);
	}

	for (i = 0; i < Array_first_p->row; i++) {
		Array_first_p->arrData[i] = (int*)malloc(sizeof(int)*(Array_second_p->col));
		if (Array_first_p->arrData[i] == NULL) {
			printf("Heap is full");
			exit(-1);
		}
	}

	Array_first_p->col = Array_second_p->col;

	for (i = 0; i < Array_first_p->row; i++) {
		for (j = 0; j < Array_second_p->col; j++) {
			Array_first_p->arrData[i][j] = result[i][j] ;
		}
	}
	
	for (i = 0; i < Array_first_p->row; i++) {
		free(result[i]);
	}
	free(result);

	return Array_first_p;
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

void printArray(struct Array_format* Array_first_p) {
	for (i = 0; i < Array_first_p->row; i++) {
		for (j = 0; j < Array_first_p->col; j++) {
			printf("%5d  ", Array_first_p->arrData[i][j]);
		}
		puts("");
	}
	puts("");
}
	
