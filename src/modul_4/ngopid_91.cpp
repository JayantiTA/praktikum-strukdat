#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int A, B;
    array<int, 100005> cov;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        A--, B--;
        cov.at(A)++ , cov.at(B)++;
    }
    int days = N - 1;
    for (int i = 0; i < N; i++)
    {
        if (cov.at(i) > 0 || i == 0)
        {
            int people = cov.at(i);
            int harinya = 0;
            int ppl_infected = 1;
            
            while (ppl_infected < people)
            {
                harinya++;
                ppl_infected *= 2;
            }

            days += harinya;
        }
    }

    cout << days << endl;
    
    return 0;
}
