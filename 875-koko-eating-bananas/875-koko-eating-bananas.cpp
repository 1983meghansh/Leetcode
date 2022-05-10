class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       // int low=*min_element(piles.begin(),piles.end());
        int low=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            if(possible(piles,h,mid)==true)
            {
                ans=mid;
                hi=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    bool possible(vector<int>& piles, int h,int limit)
    {
        int hrs=0;
        for(int i=0;i<piles.size();i++)
        {
            int div=piles[i]/limit;
            hrs+=div;
            if(piles[i]%limit!=0)
                hrs++;
       }
        if(hrs<=h)
            return true;
        else
            return false;
    }
};