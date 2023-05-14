#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int knapsack(int W, int wt[], int val[], int n) {
    int i, j;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i] <= j)
                K[i][j] = MAX(val[i] + K[i-1][j-wt[i]], K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }

    return K[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value that can be obtained: %d\n", knapsack(W, wt, val, n));

    return 0;
}