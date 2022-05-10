class Solution {
public:
    bool can_we_ship(vector<int>& weights,int maxdays,int capacity)
    {
        
        int sum=0,days=1;
        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i]>capacity)
            {
                sum=weights[i];
                days++;
            }
            else{
                sum+=weights[i];
            }
        }
        if(days<=maxdays)
            return true;
        else
            return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        //talk about the range of binary search
        //low=
        int low=*max_element(weights.begin(),weights.end());
        //if days =maximum then min no of days should be the min
        //min package weight
        int hi=0;
        for(int i=0;i<weights.size();i++)
            hi+=weights[i];   //if days=1 then 
        //weight should be summation of all packages
        
        int ans=-1;
        while(low<=hi)
        {
             int mid=(low+hi)/2;
             //check if capacity of ship=mid then can we ship all
            //packages within d days
            if(can_we_ship(weights,days,mid)==true)
            {
                //store it as a possible ans and reduce the search space
                ans=mid;
                hi=mid-1;
            }
            else
            {
                //we would need more weight
                low=mid+1;
            }

        }
        return ans;
    }
};