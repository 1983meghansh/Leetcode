class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        //JUST FIND NO OF COMPONENTS IN A GRAPH
        int n=M.size(),ans=0;
        
        vector<bool>vis(n,false);  //a visited array
        for(int i=0;i<n;i++)   //check if not visited then mark as visited and explore all neighbours
        {
            if(!vis[i])
            {
                ans++;
                dfs(M,vis,i);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& M,vector<bool>&vis,int i)
    {
        vis[i]=true;
        for(int j=0;j<M.size();j++)
        if(M[i][j]==1 and !vis[j])
            dfs(M,vis,j);
    }
};