class Solution {
public:
    
    void dfs(vector<vector<int>>& graphs,int node,vector<bool>&vis)
    {
        vis[node]=true;
        for(auto i:graphs[node])
        {
            if(!vis[i])
            dfs(graphs,i,vis);
    }}
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++)
            if(vis[i]==false)
                return false;
        
        return true;
    }
};