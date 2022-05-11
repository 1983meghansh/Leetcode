class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long tot=0;
        for(long long i=0;i<candies.size();i++)
            tot+=candies[i];
        if(tot<k)
            return 0;
        long long low=1;
        long long hi=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=hi)
        {
            long long mid=(low+hi)/2;
            if(ispossible(candies,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
    bool ispossible(vector<int>& candies,long long k,long long candy)
    {
        long long tot=0;
        
         for(long long i=0;i<candies.size();i++)
         {
             long long temp=candies[i]/candy;
             tot+=temp;
         }
        if(tot>=k)
            return true;
        else
            return false;
    }
};