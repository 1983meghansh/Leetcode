class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,hi=arr.size()-1;
        while(hi-low>=k)
        {
            if(abs(arr[low]-x)>abs(arr[hi]-x))
                low++;
            else
                hi--;
        }
        vector<int>ans;
        for(int i=low;i<=hi;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};