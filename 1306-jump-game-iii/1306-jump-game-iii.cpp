class Solution {
public:
    
    bool dfs(vector<int>& arr,int i,vector<bool>&vis)
    {
        if(i>=arr.size() or i<0 or vis[i])
            return false;
        if(arr[i]==0)
            return true;
        vis[i]=true;
        return dfs(arr,i+arr[i],vis) || dfs(arr,i-arr[i],vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,false);
     return dfs(arr,start,vis);
    }
};