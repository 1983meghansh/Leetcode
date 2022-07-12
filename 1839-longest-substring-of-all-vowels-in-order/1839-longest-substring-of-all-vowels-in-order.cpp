class Solution {
public:
    int longestBeautifulSubstring(string s) {
        if(s.length()<5)
            return 0;
        unordered_map<char,int>mp;
        int j=1;
        int i=0;
        mp[s[0]]++;
        int res=0;
        while(j<s.length())
        {
            if(s[j]<s[j-1])
            {
                if(mp.size()>=5)
                res=max(res,j-i);
                mp.clear();
                i=j;
                
            }
            mp[s[j]]++;
            j++;
        }
        if(mp.size()>=5)
            res=max(res,j-i);
        return res;
    }
};