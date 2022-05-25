class Solution {
public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         //this problem becomes similar to LIS just that u need
//         //to sort envelope in increasing order and then at each 
//         //step check if the width and height of current envelope
//         //is strictly greater than the previous , rest all steps are same as LIS
        
//         int n=envelopes.size();
//         sort(envelopes.begin(),envelopes.end());//sorts envelopes vector in increasing order of width and height
        
//         if(n==0)
//             return 0;
//         vector<int>dp(n+1,1);
//         int ans=1;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(envelopes[i][0]>envelopes[j][0] and envelopes[i][1]>envelopes[j][1])
//                 {
//                     dp[i]=max(dp[i],1+dp[j]);
//                 }
//                 ans=max(ans,dp[i]);
//             }
//         }
//         return ans;
        
//     }
    //the TC of above solution is O(n^2) and so TLE
    //do the binary search approach to solve LIS
    //refer below 
    //https://leetcode.com/problems/russian-doll-envelopes/discuss/2071459/C%2B%2B-or-O(NlogN)-approach-or-LIS-or-Explaination-with-Comments
    static bool comparator(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
     int maxEnvelopes(vector<vector<int>>& envelopes)
     {
         
         //sorting width and if the width is same , then by descending order of height
         sort(envelopes.begin(),envelopes.end(),comparator);
         //  // e.g. -> env => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
        // sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)
        
        // Now, we only need to care about width
        // So, as of now we only need to look upon v[i][1]
        // [ 6, 1, 8, 5, 7, 3, 8 ]
         vector<int>temp;
         int n=envelopes.size();
         temp.push_back(envelopes[0][1]);
         int ans=1;
         for(int i=1;i<n;i++)
         {
             if(envelopes[i][1]>temp.back())
             {
                 temp.push_back(envelopes[i][1]);
                 ans++;
             }
             else{
                 int ind=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                 temp[ind]=envelopes[i][1];
             }
         }
         return ans;
     }
};