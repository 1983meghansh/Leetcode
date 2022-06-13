class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        ans[0][0]=triangle[0][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                    ans[i][j]=triangle[i][j]+ans[i-1][j];
                else if(j==triangle[i].size()-1)
                    ans[i][j]=triangle[i][j]+ans[i-1][j-1];
                else
                    ans[i][j]=triangle[i][j]+min(ans[i-1][j],ans[i-1][j-1]);
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++) // ans is in last row
        {
            res=min(res,ans[n-1][i]);
        }
        return res;
    }
};