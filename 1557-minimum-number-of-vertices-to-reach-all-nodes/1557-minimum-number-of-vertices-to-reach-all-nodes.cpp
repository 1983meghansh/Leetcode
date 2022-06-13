class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>res,indeg(n);
        for(auto i:edges)
        {
            indeg[i[1]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                res.push_back(i);
        }
        return res;
        
    }
};