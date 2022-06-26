class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        vector<int>fsum(n+1,0);
        vector<int>esum(n+1,0);
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
             sum=sum+cp[i];
            fsum[i+1]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
             sum=sum+cp[i];
            esum[i]=sum;
        }
        int ans=0;
         // reverse(esum.begin(),esum.end());
        for(int i=0;i<=k;i++)
        {
            ans=max(ans,fsum[i]+esum[n-k+i]);
        }
        return ans;
    }
};