#include <stdio.h>

int main (void) {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];

    int dir=0, i=0, j=0, counter=0;
    int right_bound = n - 1,
    upper_bound = 0,
    left_bound = -1,
    lower_bound = m - 1;
    while (counter < n * m) {
        counter++;
        matrix[i][j] = counter;

        if (j == right_bound && i == upper_bound) {
            dir = (dir + 1) % 4;
            left_bound++;}
        else if (i == lower_bound && j == right_bound) {
            dir = (dir + 1) % 4;
            upper_bound ++;}
        else if (j == left_bound && i == lower_bound) {
            dir = (dir + 1) % 4;
            right_bound --;}
        else if (i == upper_bound && j == left_bound){
            dir = (dir + 1) % 4;
            lower_bound --;}

        switch (dir) {
            case 0: j++; break; //вправо
            case 1: i++; break; //вниз
            case 2: j--; break; //влево
            case 3: i--; break; //вверх
        }                
    }

    //печать матрицы
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++)
        printf("%3d", matrix[i][j]);
    printf("\n");}
 
    return 0;
}