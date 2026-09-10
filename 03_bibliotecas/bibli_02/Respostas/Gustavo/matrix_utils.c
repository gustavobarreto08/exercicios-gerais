#include "matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int r,c;
    for(r=0;r<rows;r++){
        for(c=0;c<cols;c++){
            scanf("%d",&matrix[r][c]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int r,c;
    for(r=0;r<rows;r++){
        printf("|");
        for(c=0;c<cols;c++){
            printf("%d",matrix[r][c]);
            if(!(c==cols-1)){
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(cols1==cols2){
        if(rows1==rows2){
            return 1;
        }
    }
    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if(cols1==cols2){
        if(rows1==rows2){
            return 1;
        }
    }
    return 0;
}

int possible_matrix_multiply(int cols1, int rows2){
    if(cols1==rows2){
        return 1;
    }
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1],
int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int r,c;
    for(r=0;r<rows1;r++){
        for(c=0;c<cols1;c++){
            result[r][c] = matrix1[r][c]+matrix2[r][c];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1],
int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int r,c;
    for(r=0;r<rows1;r++){
        for(c=0;c<cols1;c++){
            result[r][c] = matrix1[r][c]-matrix2[r][c];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    int r,cr,lr;
    for(lr=0;lr<rows1;lr++){
        for(cr=0;cr<cols2;cr++){
            result[lr][cr]=0;
        }
    }
    for(cr=0;cr<cols2;cr++){
        for(lr=0;lr<rows1;lr++){
            for(r=0;r<rows2;r++){
                result[lr][cr] += matrix1[lr][r]*matrix2[r][cr];
            }
        }
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    int l,c;
    for(c=0;c<rows;c++){
        for(l=0;l<cols;l++){
            result[l][c] = matrix[c][l];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    int l,c;
    for(l=0;l<rows;l++){
        for(c=0;c<cols;c++){
            matrix[l][c]*=scalar;
        }
    }
}