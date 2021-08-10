#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

#define INT_MAX 50000

int minUang(array<int, 500> uang, int N, int V)
{
    array<int, INT_MAX> cek;
 
    cek[0] = 0;
 
    for (int i = 1; i <= V; i++)
    {
        cek[i] = INT_MAX;
    }
 
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (uang[j] <= i)
            {
                int sub_res = cek[i - uang[j]];
                if (sub_res != INT_MAX && sub_res + 1 < cek[i])
                {
                    cek[i] = sub_res + 1;
                }
            }
        }
    }
   
    if (cek[V] == INT_MAX)
        return -1;
   
    return cek[V];
}

int main()
{
    int N, V;
    array<int, 500 > uang;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> uang[i];
    }
    
    cin >> V;
    
    cout << minUang(uang, N, V);
    
    return 0;
}
