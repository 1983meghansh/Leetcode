class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        //we will use multiset here
        //what we will do is we will sort array nums1 and then for each index in nums2 we check if the just greater element than that in nums1 , if its there then replace the nums2th element with that and delete that element from nums1 multiset , otherwise replace nums2th with the first element of nums1 
        //multiset stoeres elements in sorted order
        multiset<int>s(begin(nums1),end(nums1));
        
        for(int i=0;i<nums2.size();i++)
        {
            auto it=s.upper_bound(nums2[i]);
            if(it==end(s))
                it=begin(s);
            nums2[i]=*it;
            s.erase(it);
        }
        return nums2;
    }
};