class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=i+2;
        int ans=0;
        while(j<s.length())
        {
            if(s[i]!=s[j])
            {
                if(s[i]!=s[i+1] and s[i+1]!=s[j])
                    ans++;
            }
            i++;
            j++;
        }
        return ans;
    }
};