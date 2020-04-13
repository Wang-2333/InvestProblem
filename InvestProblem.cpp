#include<stdio.h>
#include<string>

int main() {
    int n = 4, m = 5; // n个项目,投资m万元
    int f[5][6] = { {0,0,0,0,0,0},{0,11,12,13,14,15},{0,0,5,10,15,20},{0,2,10,30,32,40},{0,20,21,22,23,24} };//f[i][j]表示第i项投资j万元的收益 1 <= i <= n, 1 <= j <= m
    int F[5][6]; // F[i][j]表示投资前i项项目不超过j元钱的最大收益 1 <= i <= n, 1 <= j <= m
    int x[5][6]; // 标记函数

    int i, j, k, tmp;
    for (i = 2; i <= n; i++)
        memset(F[i], -1, sizeof(int) * (m + 1)); // 设置最大收益值的最小数目是-1
    for (i = 0; i <= m; i++)
        F[1][i] = f[1][i]; // 投资第一个项目
    for (i = 2; i <= n; i++) { // 投资前i个项目
        F[i][0] = 0; // 投资前i个项目不超过0元的收益是0
        x[i][0] = 0; // 标记
        for (j = 1; j <= m; j++) { // 投资钱数不超过j
            for (k = 0; k <= j; k++) { // 投资当前项目的钱数
                tmp = f[i][k] + F[i - 1][j - k];
                if (tmp > F[i][j])
                {
                    F[i][j] = tmp; // 更新当前的最有解
                    x[i][j] = k; // 更新标记函数
                }
            }
        }
    }
    printf("The max profit is:\n%d\n", F[n][m]);
    return 0;
}
