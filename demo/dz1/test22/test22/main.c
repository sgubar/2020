//
//  main.c
//  test22
//
//  Created by Slava Gubar on 3/10/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include <stdio.h>
//void multiply(int multyplier, int **matix, int row, int col); //#1
//int ** multiply(int multyplier, int **matix, int row, int col); //#2
//void multiply(int multyplier, int **matix, int row, int col, int **out_matrix); //#3
void multiply(int multyplier, int *matrix, int row, int col);

int ** create_matrix(int row, int col);

int main(int argc, const char * argv[]) {
	// insert code here...
	int input_matrix[4][4];
	int output_matrix[4][4];
	
	multiply(5, input_matrix, 4, 4, output_matrix)
	
	printf("Hello, World!\n");
	return 0;
}

//#1

//void multiply(int multyplier, int **matrix, int row, int col)
//{
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < col; j++)
//		{
//			matrix[i][j] = matrix[i][j] * multyplier;
//		}
//}

//#2

//int ** multiply(int multyplier, int **matrix, int row, int col) //#2
//{
//	int ** result = create_matrix(row, col);
//
//	for (int i = 0; i < row; i ++)
//		for (int j = 0; j < col; j ++)
//			result[i][j] = matrix[i][j] * multyplier;
//
//	return result;
//}
//
//int ** create_matrix(int row, int col)
//{
//	int ** result = (int **)malloc(sizeof(int) * row);
//
//	for (int k = 0; k < col; k++)
//	{
//		result[k] = (int *)malloc(sizeof(int)*col);
//	}
//
//	return result;
//}
//
//void free_matrix(int **matrix, int row)
//{
//
//}

//void multiply(int multyplier, int **matrix, int row, int col, int **out_matrix)
//{
//	for (int i = 0; i < row; i ++)
//		for (int j = 0; j < col; j ++)
//			out_matrix[i][j] = matrix[i][j] * multyplier;
//}

void multiply(int multyplier, int *matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j ++)
		{
			matrix[(i * col) + j] = matrix[(i * col) + j] * multyplier;
		}
}
