class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n,vector<int>(n));
        vector<int>deg(n,0);
        
        for(int i=0;i<roads.size();i++)
        {
            int a=roads[i][0];
            int b=roads[i][1];
            deg[a]++;
            deg[b]++;
            adj[a][b]++;
            adj[b][a]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j){
                int res=deg[i]+deg[j]-adj[i][j];
                ans=max(res,ans);
            }}
        }
        return ans;
    }
};