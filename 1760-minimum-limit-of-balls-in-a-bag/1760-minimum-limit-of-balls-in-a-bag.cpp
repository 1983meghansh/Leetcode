class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int hi=*max_element(nums.begin(),nums.end());
        
        int ans=0;
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            
            if(allowed(nums,maxOperations,mid)==true)
            {
                ans=mid;
                hi=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    bool allowed(vector<int>&nums,int maxoper,int maxball)
    {
        
        int oper=0;
        for(int i=0;i<nums.size();i++)
        {
            oper+=nums[i]/maxball;
            if(nums[i]%maxball==0)
                oper--;
        }
        if(oper<=maxoper)
            return true;
        else
            return false;
    }
};