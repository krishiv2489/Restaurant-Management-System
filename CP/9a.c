#include <stdio.h>
void f(int *ptr, int , int m);
int main() {
    int n, m;
    printf("Enter the number of n and columns: ");
    scanf("%d %d", &n, &m);
    int arr[n][m];
    printf("Enter %d elements one by one:\n", n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    f(&arr[0][0], n, m); 

    printf("The modified 2D array is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void f(int *ptr, int n, int m) {
    int total = n * m;
    for (int i = 0; i < total; i++) {
        if (*(ptr + i) % 2 == 0)
            *(ptr + i) += 2;
        else
            *(ptr + i) += 1;
    }
}
