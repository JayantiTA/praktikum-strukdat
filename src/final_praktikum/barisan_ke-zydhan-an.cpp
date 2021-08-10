#include <vector>
#include <array>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t, x;
    
    array<int, 1000005> baris;
    
    baris.fill(0);
    
    baris[0] = 11;
    baris[1] = 15;
    
    for (int i = 2; i < 11; i++)
    {
        baris[i] = (baris[i - 1] + baris[i - 2]) % 1000000007;
    }
    
    for (int i = 11; i < 15; i++)
    {
        baris[i] = (baris[i - 2] + baris[i - 11]) % 1000000007;
    }
    
    for (int i = 15; i < 1000000; i++)
    {
        baris[i] = (baris[i - 11] + baris[i - 15]) % 1000000007;
    }
    
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> x;
        cout << baris[x] << "\n";
    }
    
    return 0;
}
