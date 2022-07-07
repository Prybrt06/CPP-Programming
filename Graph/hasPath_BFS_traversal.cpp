#include <iostream>
#include <queue>
using namespace std;

bool BFScheck(int **edges, int n, int sv, int ev, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                continue;
            }

            if(edges[top][i])
            {
                if(i == ev)
                {
                    return true;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
    return false;
}

int main()
{
    int n,e;
    cin >> n >> e;

    int **edges = new int*[n];

    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int sv,ev;
    cin>>sv>>ev;
    
    bool *visited = new bool[n];

    if(BFScheck(edges,n,sv,ev,visited))
    {
        cout << "true\n";
    }
    
    else
    {
        cout << "false\n";
    }

    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;

    return 0;
}
