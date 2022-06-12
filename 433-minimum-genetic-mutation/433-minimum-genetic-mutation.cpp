class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.compare(endWord)==0)
            return 0;
        if(wordList.size()==0)
            return -1;
         unordered_set<string>s;
        bool pres=false;
        for(auto it:wordList)
        {
            if(it==endWord)
                pres=true;
            s.insert(it);
        }
        if(pres==false)
            return -1;
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        string ss="ACGT";
        while(!q.empty())
        {
            int lsize=q.size();  //process level by level and icrease the depth at each level
            depth++;
            while(lsize--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;
                    for(auto c:ss)
                    {
                        temp[i]=c;
                        if(curr.compare(temp)==0)
                            continue;          //skip if its the same curr word
                        if(temp.compare(endWord)==0)   //we always check if the new word formed is the 
                            return depth;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);              //erase coz can form a word more than once
                        } 
                    }
                }
            }
        }
        return -1;
        
    }
};