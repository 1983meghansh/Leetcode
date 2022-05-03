class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // vector<int>prefsum;
        // vector<int>suffsum;
        // int n=nums.size();
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(i==0)
        //         prefsum[i]=0;
        //     else
        //    prefsum[i]=nums[i-1]+prefsum[i-1];
        // }
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(i==n-1)
        //         suffsum[i]=0;
        //     else
        //         suffsum[i]=nums[i+1]+suffsum[i+1];
        // }
        // int leftsum=0,rightsum=0;
        // int ans=-1;
        //  for(int i=0;i<nums.size();i++)
        //  {
        //      leftsum=prefsum[i];
        //      rightsum=suffsum[i];
        //      if(leftsum==rightsum)
        //      {
        //          ans=i;
        //          break;
        //      }
        //  }
        // return ans;
        
        int rightsum=accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            rightsum-=nums[i];
            if(rightsum==leftsum)
            {
                ans=i;
                break;
            }
            leftsum+=nums[i];
        }
        return ans;
        
    }
};