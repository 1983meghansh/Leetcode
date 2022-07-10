class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX;
        int tracker[1000001]={};
        for(int i=0;i<cards.size();i++)
        {
            if(tracker[cards[i]])
                ans=min(ans,i-tracker[cards[i]]+2);
            tracker[cards[i]]=i+1;
        }
        return ans==INT_MAX?-1:ans;
    }
};