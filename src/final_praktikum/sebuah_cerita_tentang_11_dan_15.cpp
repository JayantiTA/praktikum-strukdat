#include <iostream>
#include <algorithm>
using namespace std;

void cerita(int n)
{
    if (n % 11 == 0 || n % 15 == 0 || n > 139)
    {
        cout << "YES\n";
        return;
    }
    
    int j = 0;
    while (j * 15 <= n)
    {
        if ((n - j * 15) % 11 == 0)
        {
            cout << "YES\n";
            return;
        }
        j++;
    }
    
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cerita(n);
    }
    return 0;
}
