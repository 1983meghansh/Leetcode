class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string temp=words[i];
            int l=temp.size();
            for(int j=1;j<=l;j++)
            {
                string p=temp.substr(0,j);  //prefix
                for(int k=0;k<l;k++)
                {
                    string q=temp.substr(k,l);  //suffix
                    mp[p+"#"+q]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+"#"+suffix;
       auto it=mp.find(s);
        if(it==mp.end())
            return -1;
        return mp[s];
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */