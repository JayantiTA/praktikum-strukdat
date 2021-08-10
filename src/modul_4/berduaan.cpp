#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

bool cek(vector<int> A, int size, unsigned int cek)
{
    unsigned int sum;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            sum = 0;
            sum = A[i] + A[j];
            if (sum == cek)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return true;
            }   
        }
    }
    return false;
}

int main() {
    unsigned int u, N, T, k;
    cin >> N;
    
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        cin >> u;
        A.push_back(u);
    }
    
    cin >> T;
    for (auto i = 0; i < T; i++)
    {
        cin >> k;
        cout << "Case " << i + 1 << ": ";
        if (!cek(A, N, k))
            cout << k << " not found" << endl;
    }
    return 0;
}