#include<bits/stdc++.h>
#define ll long long int
#define inf 100000000
using namespace std;

int tc,num_node,num_edge,source_node;
vector<int>edge[200005];
int vis[200005];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<edge[x].size(); i++)
        {
            int d=edge[x][i];
            if(vis[d]==-1)
            {
                vis[d]=vis[x]+1;
                q.push(d);
            }
        }
    }
}

int main()
{
    int tc,num_node,num_edge,source_node;

    cin>>num_node>>num_edge>>source_node;

    for(int i=0; i<num_edge; i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    memset(vis,-1,sizeof vis);
    bfs(source_node);

    for(int i=1; i<=num_node; i++)
    {
        if(i==source_node)
        {
            cout<<"Source Node is : "<<i<<endl;
        }
        else
        {
            cout<<"From Source Node to "<<i<<" distance is "<<vis[i]<<endl;
        }
    }

    return 0;
}
