#include <bits/stdc++.h>
using namespace std;

vector <long long int > height;
vector <int > width;

long long int Histogram(vector<long long int > &height)
{
    width.clear();
    height.push_back(0);

    long long int sum = 0;
    int i = 0;
    
    while(i < height.size())
    {
        if(width.empty() || height[i] > height[width.back()])
        {
            width.push_back(i);
            i++;
        }
        else
        {
            int index = width.back();
            width.pop_back();
            
            if (width.empty())
            {
                sum = max(sum, height[index] * i);
            }
            else
            {
                sum = max(sum, height[index] * (i - width.back() - 1));

            }
        }
    }

    return sum;
}

int main(void)
{
    int n, x;
    
    while (cin >> n)
    {
        height.assign(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            height.push_back(x);
        }
        
        cout << Histogram(height) << endl;
    }
    
    return 0;
}
