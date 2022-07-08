class Solution {
public:
    int dp[100][21][100];
    
    int helper(int i,int lc,int nbr,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        if(nbr>target)
            return INT_MAX/2;
        if(i==m)
        {
            return (nbr==target)?0:INT_MAX/2;
        }
        if(dp[i][lc][nbr]!=-1)
            return dp[i][lc][nbr];
        else{
            int ans=INT_MAX/2;
            if(houses[i]==0)
            {
                for(int j=0;j<n;j++)
                {
                    ans=min(ans,cost[i][j]+helper(i+1,j+1,(lc==j+1)?nbr:nbr+1,houses,cost,m,n,target));
                }
            }
            else{
                ans=min(ans,helper(i+1,houses[i],(houses[i]==lc)?nbr:nbr+1,houses,cost,m,n,target));
            }
            return dp[i][lc][nbr]=ans;
        }
      
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int res=helper(0,0,0,houses,cost,m,n,target);
        if(res==INT_MAX/2)
            return -1;
        return res;
    }
};