class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //Algorithm:

// Create a sliding window: [nums[l], nums[l + 1], ..., num].
// For each number in the nums array, we check if this num is already present in the window. We can use a set to lookup in O(1).
// If the number is present in the window, we keep shrinking the window from the left until there's no repetition.
// We update the set by adding num and repeat the above process.
// Example:

// nums = [4,2,1,2,6]
// 1. Window: [4]; set = {4}; curr_sum = 4; max_sum = 4
// 2. Window: [4, 2]; set = {4, 2}; curr_sum = 6; max_sum = 6
// 3. Window: [4, 2, 1]; set = {4, 2, 1}; curr_sum = 7; max_sum = 7
// 4(a). Window: [2, 1, 2]; set = {2, 1}; curr_sum = 5; max_sum = 7
// 4(b). Window: [1, 2]; set = {1, 2}; curr_sum = 3; max_sum = 7
// 5. Window: [1, 2, 6]; set = {1, 2, 6}; curr_sum = 9; max_sum = 9
        unordered_set<int>s;
        int curr_sum=0,ans=0;
        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            while(s.find(nums[i])!=s.end())      //shrinking the window as we got duplicates 
            {
                curr_sum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            curr_sum+=nums[i];           //expanding the window
            s.insert(nums[i]);
            ans=max(ans,curr_sum);
        }
        return ans;
    }
};