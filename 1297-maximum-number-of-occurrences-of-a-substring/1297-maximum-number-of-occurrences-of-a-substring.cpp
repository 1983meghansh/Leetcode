class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res=0;
        unordered_map<char,int>m1;
        unordered_map<string ,int>m2;
        
        int j=0,i=0;
        while(j<s.size())
        {
            m1[s[j]]++;
             if(j-i+1>minSize or m1.size()>maxLetters)
            {
                m1[s[i]]--;
                if(m1[s[i]]==0)
                    m1.erase(s[i]);
                i++;
            }
            if(j-i+1==minSize and m1.size()<=maxLetters)
            {
                
                res=max(res,++m2[s.substr(i,minSize)]);
            }
           
            j++;
        }
        return res;
    }
};