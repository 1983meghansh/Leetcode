class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                //downhill
                c++;
                if(i>=2 and nums[i-2]>nums[i])
                    nums[i]=nums[i-1];
              
                
            }
        }
        return c<=1;
    }
};