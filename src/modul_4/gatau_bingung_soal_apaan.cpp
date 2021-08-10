#include<bits/stdc++.h> 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
  
typedef struct element 
{ 
    int count, index, value; 
}ele; 
  
bool compare(ele a, ele b)
{ 
    return (a.value < b.value); 
} 
  
bool compare2(ele a, ele b) { 
    if (a.count != b.count)
        return (a.count < b.count); 
    else
        return a.index > b.index; 
} 
  
void sortByFrequency(array<int, 10000> arr, int n) 
{ 
    ele element[n]; 
    for (int i = 0; i < n; i++) 
    { 
        element[i].index = i;    
        element[i].count = 0;    
        element[i].value = arr[i]; 
    } 
  
    stable_sort(element, element + n, compare); 
  
    element[0].count = 1; 
  
    for (int i = 1; i < n; i++) 
    { 
        if (element[i].value == element[i - 1].value) 
        { 
            element[i].count += element[i - 1].count+1; 
  
            element[i-1].count = -1; 
  
            element[i].index = element[i - 1].index; 
        } 
  
        else element[i].count = 1; 
    } 
  
    stable_sort(element, element + n, compare2); 
    for (int i = n - 1, index = 0; i >= 0; i--)
    {
        if (element[i].count != -1) 
        {
           for (int j = 0; j < element[i].count; j++)
           {
               arr[index++] = element[i].value;  
           }
        }
    }
    
    for (int i = 0; i < n; i++) 
       cout << arr[i] << " ";
} 
  
int main() 
{ 
    int n; 
    cin >> n;
    
    array<int, 10000> arr;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
  
    sortByFrequency(arr, n); 
 
    return 0; 
} 
