#include<iostream>
#include<vector>
using namespace std;

vector<int> getPathDFS(int **edges,int n,int sv,int ev,bool *visited)
{
    vector<int> ans;
    visited[sv] = true;
    ans.push_back(sv);

    for(int i=0;i<n;i++)
    {
        if(visited[i])
        {
            continue;
        }

        if(edges[sv][i])
        {
            if(i==ev)
            {
                visited[i] = true;
                ans.push_back(i);
                return ans;
            }

            vector<int> check = getPathDFS(edges,n,i,ev,visited);

            if(check[check.size()-1]==ev)
            {
                for(int i=0;i<check.size();i++)
                {
                    ans.push_back(check.at(i));
                }
            }
        }
    }
    return ans;
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

        vector<int> path = getPathDFS(edges,n,sv,ev,visited);

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