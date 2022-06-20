class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string>s(words.begin(),words.end());
        
        for(string i:words)
        {
            for(int j=1;j<i.size();j++)
            {
                s.erase(i.substr(j));
            }
        }
        
        int ans=0;
        for(string i:s)
        {
            ans+=1+i.size();
        }
        return ans;
    }
};