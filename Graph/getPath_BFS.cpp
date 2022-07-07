#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> getPathBFS(int **edges,int n,int sv,int ev,bool *visited)
{
    vector<int> ans;
    visited[sv] = true;
    ans.push_back(sv);

    queue<int> q;
    q.push(sv);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        if(front==ev)
        {
            visited[ev] = true;
            ans.push_back(front);
            return;
        }
    }
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
    cin >> sv >> ev;

    if(sv==ev)
    {
        cout << sv;
    }

    else
    {
        bool *visited = new bool[n];

        for(int i=0;i<n;i++)
        {
            visited[i] = false;
        }

        vector<int> path = getPathBFS(edges,n,sv,ev,visited);

        if(path.size()>1)
        {
            for(int i=0;i<path.size();i++)
            {
                cout << path.at(i) << " ";
            }
        }

        delete [] visited;

    }

    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
