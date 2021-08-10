#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000111222
#define eps 1e-5
#define maxN 10011

int m = 10000;
int X[maxN];
bool temp[maxN];

void function(int N, int M)
{
    int p, q;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d.%d", &p, &q);
        X[i] = p * 100 + q;
    }

    swap(X[M - 1], X[0]);

    memset(temp, 0, sizeof(temp));

    temp[X[0]] = true;

    for (int i = 1; i < N; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (temp[j] && j + X[i] <= m)
            {
                temp[j + X[i]] = true;
            }
        }
    }

    double result = INF;

    for (int i = 5001; i <= m; i++)
    {
        if (temp[i])
        {
            result = i;
            break;
        }
    }

    printf("%.2lf\n", (X[0] * 100.0 / result) + eps);
}

int main() {
    int N, M;
    
    while (scanf("%d %d", &N, &M) && (N || M)) 
    {
        function(N, M);
    }
    
    return 0;
}
