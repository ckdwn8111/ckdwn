//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>

#include"matrix.h"


//extern struct Array_format Array_first;


int main(void) {
	
	struct Array_format array_1 = { .arrData = NULL,.row = 0,.col = 0 };
	struct Array_format array_2 = { .arrData = NULL,.row = 0,.col = 0 };
	int select = 0;
	printf("��ɰ��� ������ 1��, 2by2 ����� ����� ������ 2���� �Է��Ͻÿ� : ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		printf("���ϴ� ù��° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &array_1.row);
		printf("���ϴ� ù��° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &array_1.col);
		printf("���ϴ� �ι�° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &array_2.row);
		printf("���ϴ� �ι�° ����� ���� �Է��Ͻÿ� : ");
		scanf("%d", &array_2.col);

		arrayInput(&array_1, &array_2);
		printArray(&array_1);
		printArray(&array_2);
		break;
	case 2:
		array_2by2_Reverse();
		exit(-1);
	default:
		printf("�߸��� �Է��Դϴ�.\n");
		exit(-1);
	}

	if (array_1.row == array_2.row && array_1.col == array_2.col) {
		if (array_1.col == array_2.row) {
			printf("��� ������ �������Դϴ� <+(1), -(2), *(3)> �� �ϳ��� �����Ͻÿ� : ");
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
				printf("�߸��� �Է��Դϴ�.\n");
				exit(-1);
			}
		}
		else {
			printf("��� ������ �������Դϴ� <+(1), -(2)> �� �ϳ��� �����Ͻÿ� : ");
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
				printf("�߸��� �Է��Դϴ�.\n");
				exit(-1);
			}
			}
		}
	else {
		if (array_1.col == array_2.row) {
			printf("��� ������ �����ڰ� * �ۿ� �����ϴ� 3�� �Է����ּ��� : ");
			scanf("%d", &select);
			puts("");
			if (select = 3) {
				arrayMultiply(&array_1, &array_2);
				printArray(&array_1);
			}
			else {
				printf("�߸��� �Է��Դϴ�.\n");
				exit(-1);
			}
		}
		else {
			printf("��밡���� ������ �����ϴ�.\n");
			exit(-1);
		}

	}
	arrayFree(&array_1, &array_2);

	return 0;
}

	
	

