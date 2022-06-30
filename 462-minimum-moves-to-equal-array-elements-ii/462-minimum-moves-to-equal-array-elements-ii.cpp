class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int idx;
        if(n%2==0)
            idx=n/2-1;
        else
            idx=n/2;
        int el=nums[idx];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i!=idx)
            {
                int diff=abs(el-nums[i]);
                ans+=diff;
            }
        }
        return ans;
        
    }
};