class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> v[N+1];
        for(int i=0;i<paths.size();i++)
        {
            v[paths[i][0]].push_back(paths[i][1]);
            v[paths[i][1]].push_back(paths[i][0]);
        }
        int visited[N+1];//to store color of flower in each garden
        for(int j=1;j<N+1;j++)
        {
            visited[j]=0;
        }
        queue<int> q;
        for(int i=1;i<N+1;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
            while(!q.empty())
            {
                bool flower[5]={false};// to check for colors in neighbouring gardens
                int top= q.front();
                flower[visited[top]]=true;
                q.pop();
                for(auto it:v[top])
                {
                    if(!visited[it])
                    {
                        q.push(it);
                        for(int k=1;k<5;k++)
                        {
                            if(flower[k]==false)
                            {
                                visited[it]=k;
                                flower[k]=true;
                                break;
                            }
                        }
                    }
                    else
                    {
                        flower[visited[it]]=true;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=1;i<N+1;i++)
        {
            ans.push_back(visited[i]);
        }
        return ans;
    }
};
