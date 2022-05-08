class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,hi=nums.size()-1;
        
        while(low<hi)
        {
            int mid=(low+hi)/2;
            if(nums[mid]>nums[mid+1])
                hi=mid;
            else
                low=mid+1;
        }
        return low;
    }
    
};