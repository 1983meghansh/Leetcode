class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane algo
        //we carry the subarray sum as long as it gives a positive sum
        // we take 2 var , maxi and sum
        //sum is continuous subaaryy sum if +ve and maxi is max so far
        
        int sum=0,maxi=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};