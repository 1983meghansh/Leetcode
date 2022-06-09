class Solution {
public:
    //excellent dfs question
    unordered_map<int,vector<int>>adjlist;  
    int maxi=0,ans=0;
    void dfs(int headID,vector<int>& informTime)
    {
        maxi=max(ans,maxi);
        for(auto employee:adjlist[headID])
        {
            ans+=informTime[headID];
            dfs(employee,informTime);
            ans-=informTime[headID];
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         //create an adjacency list
        //adj list looks like = manager->all his employees
        
        for(int i=0;i<n;i++)
        {
            int man=manager[i];
            if(man!=-1)
            adjlist[man].push_back(i);
        }
        
        dfs(headID,informTime);
        return maxi;
    }
};