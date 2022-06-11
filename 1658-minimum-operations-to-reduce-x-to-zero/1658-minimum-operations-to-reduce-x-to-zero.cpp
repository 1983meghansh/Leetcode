class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        for(auto it:nums)
            tot+=it;
        int des_sum=tot-x;
        if(des_sum==0)
            return nums.size();
        
        int i=0,j;
        int sum1=0,res=0;
        for(int j=0;j<nums.size();j++)
        {
            sum1+=nums[j];
            while(sum1>des_sum and i<nums.size())
                sum1-=nums[i++];
            
            if(sum1==des_sum)
                res=max(res,j-i+1);
        
        }
        if(res==0)
            return -1;
        return nums.size()-res;
    }
};