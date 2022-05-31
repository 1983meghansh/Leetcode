class Solution {
public:
 int rob(vector<int>& nums) {
        //similar to house robber problem except that here 1st and last element are adjacent , so we cannot select both of them together , so 1st we use same logic and calculate dp[n-1] by excluding 1st element and then do same by excluding last element , and the maximum of 2 is our answer.
        int n=nums.size();
        if(n==1)
            return nums[0];
        int dpstart[n+2];
        int dpend[n+2];
        dpstart[0]=nums[0];
        dpstart[1]=max(nums[0],nums[1]);
        //including first element and excluding last element
        for(int i=2;i<n-1;i++)
        {
            dpstart[i]=max(dpstart[i-1],dpstart[i-2]+nums[i]);
        }
        //including last element and excluding first element
        
        dpend[0]=0;
        dpend[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            dpend[i]=max(dpend[i-1],dpend[i-2]+nums[i]);
        }
        return max(dpstart[n-2],dpend[n-1]);
    }
};