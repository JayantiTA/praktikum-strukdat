#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int, 
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> AVL; 

int main()
{
    unsigned int testcase, X, Y, Zi;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        AVL jalur;
        cin >> X >> Y;
        for (int j = 0; j < X; j++)
        {
            cin >> Zi;
            if (Zi != 0)
            {
                jalur.insert(Zi);
            }
            else
            {
                unsigned int ans = *jalur.find_by_order(Y - 1);
                if (Zi < Y)
                {
                    if (ans > 0)
                        cout << ans << endl;    
                    else
                        cout << "-1" << endl;
                }
                else
                    cout << "-1" << endl;
            }
        }
        
        jalur.clear();
    }
}