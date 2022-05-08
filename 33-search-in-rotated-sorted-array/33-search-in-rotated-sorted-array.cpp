class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,hi=nums.size()-1;
        
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            if(nums[mid]==target)
                return mid;
            //check if left part is sorted
            if(nums[low]<=nums[mid])
            {
                //check if target lies in left part and then eliminate one part
                if(nums[low]<=target and nums[mid]>=target)
                    hi=mid-1;
                else
                    low=mid+1;
            }
            //check if right part is sorted
            if(nums[hi]>nums[mid])
            {
                
                if(nums[hi]>=target and nums[mid]<=target)
                    low=mid+1;
                else
                    hi=mid-1;
            }
        }
        return -1;
    }
};