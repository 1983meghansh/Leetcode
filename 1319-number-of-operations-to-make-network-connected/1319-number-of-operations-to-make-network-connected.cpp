class Solution {
public:
    
    void dfs(vector<int>list[],int node, vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:list[node])
        {
            if(!vis[it])
            {
                dfs(list,it,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //again , focus on number of components
        int m=connections.size();
        if(m<n-1)
            return -1;
        vector<int>list[n];
        
        for(int i=0;i<m;i++)
        {
            list[connections[i][0]].push_back(connections[i][1]);
            list[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(list,i,vis);
            }
        }
        return cnt-1;
        
    }
};