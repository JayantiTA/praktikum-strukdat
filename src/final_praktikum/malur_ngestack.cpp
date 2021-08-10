#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int N, stamina = 0;
    
    cin >> N;
    
    array<int, 1000> tinggi;
        
    for (int i = 0; i < N; i++)
    {
        cin >> tinggi[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        int temp = tinggi[i];
        
        stack<int > height;
        height.push(tinggi[i]);
        
        for (int j = i + 1; j < N; j++)
        {
            if (tinggi[j] > height.top())
            {
                height.push(tinggi[j]);
                temp ^= tinggi[j];
            }
        }
        
        if (temp > stamina)
        {
            stamina = temp;
        }
    }
    
    cout << stamina << endl;
    
    return 0;
}
