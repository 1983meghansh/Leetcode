class Solution {
public:
    
     int findsumafterdiv(vector<int>&nums,int n)
    {
         int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]/n);
            //just for ciel condition
            if(nums[i]%n!=0)
                sum+=1;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,hi=*max_element(nums.begin(),nums.end());
        int ans=hi;//if a possible ans exists then it can be the highest elemnt in worst case as the highest element will give least sum after division
        while(low<=hi)
        {
            int mid=(low+hi)/2;
            //mid is giving <=thresh but am looking for even smaller,hence do a search on left
            if(findsumafterdiv(nums,mid)<=threshold)
            {
                ans=mid;
                hi=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};