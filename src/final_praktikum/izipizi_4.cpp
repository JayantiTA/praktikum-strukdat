#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Edge
{
    int row, column, value;
    
    bool operator>(const Edge &edge) const
    {
        return this->value > edge.value;
    }
};

int main()
{    
    int Q, N, M;

    cin >> Q;
    
    for (int i = 0; i < Q; i++)
    {
        cin >> N >> M;
        
        vector<vector<int > > way(N, vector<int>(M));

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> way[j][k];
            }
        }
        priority_queue<Edge, vector<Edge>, greater<Edge>> p_queue;
        vector<vector<int > > value(N, vector<int >(M, -1));        
        
        Edge edge;

        edge.row = 0;
        edge.column = 0;
        edge.value = way[0][0];

        p_queue.push(edge);
        
        value[0][0] = edge.value;
        
        while (!p_queue.empty())
        {
            Edge temp = p_queue.top();
            p_queue.pop(); 
            
            for (int i = 0; i < 4; ++i)
            {
                int row = temp.row + dx[i];
                int col = temp.column + dy[i];
                
                if (row < 0 || row >= N || col < 0 || col >= M)
                {
                    continue;
                }
                if (value[row][col] == -1 || value[temp.row][temp.column] + way[row][col] < value[row][col])
                {
                    value[row][col] = value[temp.row][temp.column] + way[row][col];
                    edge.row = row;
                    edge.column = col;
                    edge.value = value[row][col];
                    
                    p_queue.push(edge);
                }
            }
        }
        cout << value[N - 1][M - 1] << endl;
    }
    return 0;
}
