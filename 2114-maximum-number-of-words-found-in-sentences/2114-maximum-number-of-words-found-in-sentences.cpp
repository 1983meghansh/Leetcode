class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int n=s.size();
        int spaces=1;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            
            int sz=s[i].size();
            spaces=1;
            for(int j=0;j<sz;j++)
            {
                if(s[i][j]==' ')
                    spaces++;
            }
            ans=max(ans,spaces);
        }
        return ans;
    }
};