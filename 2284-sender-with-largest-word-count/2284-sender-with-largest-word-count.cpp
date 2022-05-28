class Solution {
public:
   int countwords(string s)
   {
       int n=s.size();
       int words=1;
       for(int i=0;i<n;i++)
       {
           if(isspace(s[i]))
               words++;      
       }
       return words;
   }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>mp;
        
        
        for(int i=0;i<senders.size();i++)
        {
           
            int cnt=countwords(messages[i]);
            if(mp.find(senders[i])==mp.end())
                mp.insert(make_pair(senders[i],cnt));
            else
                mp[senders[i]]+=cnt;
        }
        int maxi=0;
        string ans="";
        for(auto &it:mp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
            }
        }
        for(auto &it:mp){
            if(it.second==maxi)
                ans=max(ans,it.first);
        }
        return ans;
    }
};