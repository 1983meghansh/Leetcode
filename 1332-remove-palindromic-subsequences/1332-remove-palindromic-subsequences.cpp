class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        string s2=s;
        reverse(s2.begin(),s2.end());
        if(s==s2)
            return 1;
        else
            return 2;
    }
};