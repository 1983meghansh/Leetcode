class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2)
            return "";
        unordered_set<char>st;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
        }
        for(int i=0;i<s.length();i++)
        {
            if(st.count(tolower(s[i]))==true and st.count(toupper(s[i]))==true)
                continue;
            string s1=longestNiceSubstring(s.substr(0,i));
            string s2=longestNiceSubstring(s.substr(i+1));
            return s1.size()>=s2.size()?s1:s2;
        }
        return s;
        
    }
};