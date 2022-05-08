class Solution {
public:
    int findMin(vector<int>& nums) {
        
        
        int low=0,hi=nums.size()-1;
        
        while(low<hi)
        {
            int mid=(low+hi)/2;
            if(nums[mid]>nums[hi])
            low=mid+1;
            else if(nums[mid]<nums[hi])
                hi=mid;
        
        }
        return nums[low];
    }
};