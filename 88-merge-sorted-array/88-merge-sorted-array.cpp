class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //dsa sheet , smart approach to start from back
        //take advantage of the fact that both are sorted and use 3 pointors
        int first=m-1,sec=n-1,orig=m+n-1;
        while(sec>=0)
        {
            nums1[orig--]=first>=0 and nums1[first]>=nums2[sec]?nums1[first--]:nums2[sec--];
        }
        
      
        
    }
};