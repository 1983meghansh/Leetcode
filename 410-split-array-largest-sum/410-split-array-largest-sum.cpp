class Solution {
public:
    int noofsubarrays(vector<int>&nums,int m,int limit)
    {
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>limit)
                return false;
            if(nums[i]+sum>limit)
            {
                cnt++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return cnt<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++)
            high+=nums[i];
        
        int ans=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(noofsubarrays(nums,m,mid)==false)
                low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};