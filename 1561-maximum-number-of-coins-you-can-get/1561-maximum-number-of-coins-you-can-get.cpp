class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sz=piles.size();
        sort(piles.begin(),piles.end());
        int n=sz/3;
        int res=0;
        int i=sz-2;
        while(n>0)
        {
            n--;
            res+=piles[i];
            i=i-2;
        }
        return res;
    }
};