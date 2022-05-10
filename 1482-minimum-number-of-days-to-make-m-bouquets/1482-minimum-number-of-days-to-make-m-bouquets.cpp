class Solution {
public:
    
    bool noofbouq(vector<int>& bloomDay, int m, int k,int limit) //returns true if no of bouquets we can make in limit days is greater than m bouquets
    {
        //check if m bouqets can be made in limit days
        int bouq=0,flowers=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=limit)
            {
                flowers++;
                if(flowers==k)
                {
                     bouq++;
                    flowers=0;
                }
            }
            else
                flowers=0;
        }
        if(bouq>=m)
            return true;
        else
            return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int hi=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            if(noofbouq(bloomDay,m,k,mid)==true)
            {
                hi=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};