class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>m;
        int n=s.length();
        int j=0;
        int l=0;
        
        int res=0;
        while(j<n)
        {
            m[s[j]]++;
            
            while(m['a'] and m['b'] and m['c'])
            {
                res+=n-j;
                m[s[l++]]--;
            }
            j++;
        }
        return res;
    }
};