class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
       int n=matrix.size();
               int m=matrix[0].size();

        int vis[n+3];
        
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            for(int j=0;j<m;j++)
            {
                if(vis[matrix[i][j]]==1)
                    return false;
                vis[matrix[i][j]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            for(int j=0;j<m;j++)
            {
                if(vis[matrix[j][i]]==1)
                    return false;
                vis[matrix[j][i]]++;
            }
        }
        return true;
    }
};