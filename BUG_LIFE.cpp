#include <bits/stdc++.h>
using namespace std;
//Bipartite graph test

bool dfs(int start, vector<int> adj[], bool visit[], int color[], int count)
{
	visit[start]=1;
	color[start]=count;
	for(auto it: adj[start])
	{
		if(!visit[it])
		{
			if(dfs(it,adj,visit,color,count^1)==false)
			{
				return false;
			}
		}
		else
		{
			if(color[start]==color[it])
				return false;
		}
	}
	return true;
}

int main() {
	int test, cnt=0;
	cin>>test;
	while(test>0)
	{
		cnt++;
		int bugs, interaction;
		cin>>bugs>>interaction;
		vector<int> adj[bugs+1];
		for(int i=0;i<interaction;i++)
		{
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool visited[bugs+1];
		int color[bugs+1];
        int flag=0;
        for(int i=1;i<=bugs;i++)
        {
            if(!visited[i])
            {
                bool ans = dfs(i, adj, visited, color, 0);
                if(ans==false)
                {
                    flag=1;
                }
            }        
        }
        if(!flag)
		{
			cout<<"Scenario #"<<cnt<<":\n";
			cout<<"No suspicious bugs found!\n";
		}
		else
		{
			cout<<"Scenario #"<<cnt<<":\n";
			cout<<"Suspicious bugs found!\n";
		}
        test--;
	}
}
