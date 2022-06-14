class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=accumulate(arr.begin(),arr.begin()+k,0);
     
        threshold*=k;
        int res=(sum>=threshold);
        for(int i=k;i<arr.size();i++)
        {
            sum+=arr[i];
            sum-=arr[i-k];
            res+=(sum>=threshold);
        }
        return res;
        
    }
};