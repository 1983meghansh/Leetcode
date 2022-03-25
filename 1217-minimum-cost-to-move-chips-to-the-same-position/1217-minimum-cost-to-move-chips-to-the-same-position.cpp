class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        //simple observation ->answer is the minimum of no of chips lying at even and odd positions
        int co=0,ce=0;
        int ans=0;
        for(int i=0;i<position.size();i++)
        {
            if(position[i]%2==0)
                ce++;
            else
                co++;
        }
        ans=min(co,ce);
        return ans;
    }
};