//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
#include"matrix.h"


//extern struct Array_format Array_first;


int main(void) {
	
	int row, col, row_2, col_2, select = 0;
	
		printf("���ϴ� ù��° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &row);
		printf("���ϴ� ù��° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &col);
		printf("���ϴ� �ι�° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &row_2);
		printf("���ϴ� �ι�° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &col_2);
		puts("");

		arrayInput(row, col, row_2, col_2);

		if (row == row_2 && col == col_2) {
			if (col == row_2) {
				printf("��� ������ �������Դϴ� <+(1), -(2), *(3)> �� �ϳ��� �����Ͻÿ� : ");
				scanf("%d", &select);
				puts("");
				if (select < 1 || select > 3) {
					printf("�߸��� �Է��Դϴ�.\n");
					exit(-1);
				}
			}
			else {
				printf("��� ������ �������Դϴ� <+(1), -(2)> �� �ϳ��� �����Ͻÿ� : ");
				scanf("%d", &select);
				puts("");
				if (select < 1 || select > 2) {
					printf("�߸��� �Է��Դϴ�.\n");
					exit(-1);
				}
			}
		}
		else {
			if (col == row_2) {
				printf("��� ������ �����ڰ� * �ۿ� �����ϴ� 3�� �Է����ּ��� : ");
				scanf("%d", &select);
				puts("");
				if (select != 3) {
					printf("�߸��� �Է��Դϴ�.\n");
					exit(-1);
				}
			}
			else {
				printf("��밡���� ������ �����ϴ�.\n");
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

	
	

