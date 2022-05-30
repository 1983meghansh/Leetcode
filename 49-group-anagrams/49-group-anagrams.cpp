class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>anagrams;
        for(auto st:strs)
        {
            string temp=st;
            sort(temp.begin(),temp.end());
            anagrams[temp].push_back(st);
        }
        vector<vector<string>>ans;
        for(auto it:anagrams)
            ans.push_back(it.second);
        
        return ans;
    }
};