#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int matrix[310][310], temp[310], top, bottom;

int sumPotential(int N)
{
    int max = INT_MIN, sum = 0, local_top = 0;
    bool check = false;
    
    for (int i = 0; i < N; i++)
    {
        if (temp[i] >= 0) check = true;
        
        sum = sum + temp[i];
        
        if (sum < 0)
        {
            sum = 0;
            local_top = i + 1;
        }
        else if (sum > max)
        {
            max = sum;
            top = local_top;
            bottom = i;
        }
    }
    
    if (check)
        return max;
    
    max = INT_MIN;
    
    for (int i = 0; i < N; i++)
    {
        if (max < temp[i])
        {
            max = temp[i];
            top = bottom = i;
        }
    }
    
    return max;
}

void maxPotential(int N)
{
    int max_potential = INT_MIN;
        
    for (int l = 0; l < N; l++)
    {
        memset(temp, 0, sizeof(temp));      

        for (int r = l; r < N; r++)
        {
            for (int i = 0; i < N; i++)
            {
                temp[i] += matrix[i][r];
            }

            int potential = sumPotential(N);
            
            if (potential > max_potential)
            {
                max_potential = potential;
            }
        }
    }
    
    cout << max_potential;
}

int main()
{
    int N;
    while (cin >> N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> matrix[i][j];
            }
        }
        maxPotential(N);
    }
    
    return 0;
}
