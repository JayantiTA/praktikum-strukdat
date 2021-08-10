#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int longest_path[], bool visited[])
{
    visited[node] = true;

    for (long unsigned int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            dfs(adj[node][i], adj, longest_path, visited);

        longest_path[node] = max(longest_path[node], 1 + longest_path[adj[node][i]]);
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int findLongestPath(vector<int> adj[], int edge)
{
    int longest_path[edge + 1];
    memset(longest_path, 0, sizeof longest_path);

    bool visited[edge + 1];
    memset(visited, false, sizeof visited);

    for (int i = 1; i <= edge; i++)
    {
        if (!visited[i])
        dfs(i, adj, longest_path, visited);
    }

    int ans = 0;

    for (int i = 1; i <= edge; i++)
    {
        ans = max(ans, longest_path[i]);
    }
    
    return ans;
}

int main()
{
    int T;
    cin >> T;

    vector<int> adj[T + 1];
    int vertex1, vertex2;
    for(int i = 0; i< T - 1; i++)
    {
        cin >> vertex1 >> vertex2;
        addEdge(adj, vertex1, vertex2);
    }
    cout << findLongestPath(adj, T);
    
    return 0;
}
