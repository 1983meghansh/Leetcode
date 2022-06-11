class Solution {
public:
    //approach-> we assign fake edges to make graph bidirectional
    //edges are assigned weights, original edge assigned weight 1 and fake edge assigned weight 2
    //now we do dfs , and check if we reached next node then if we reached that node through original edge
    //if yes then increment ans;
    
    vector<pair<int,int>>adjlist[50006];
    int ans;
    
    void dfs(int curr,int parent)
    {
        for(auto i:adjlist[curr])
        {
            if(i.first==parent)continue;
            else if(i.second==1)
                ans++;
            dfs(i.first,curr);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        for(auto i:connections)
        {
            adjlist[i[0]].push_back({i[1],1});   //assigning original edge as 1
            adjlist[i[1]].push_back({i[0],0});
        }
        ans=0;
        dfs(0,0);
        return ans;
    }
};