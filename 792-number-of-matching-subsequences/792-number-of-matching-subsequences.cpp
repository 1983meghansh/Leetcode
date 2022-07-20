class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        //map all occurences of each character in s (store all the indices of all character in s)
        map<char,vector<int>>m;
        int i=0;
        for(auto it:s)
            m[it].push_back(i++);
        int cnt=0;
        //now for each word in words,check if each character of the words is present in the map (i.e. string s) in order
        for(int i=0;i<words.size();i++)
        {
            int last=-1;  //storing the index of last character because the index of next char has to be greater than that
            string curr=words[i];
            for(int j=0;j<curr.size();j++)  //iterating for each char in word
            {
                auto it=upper_bound(m[curr[j]].begin(),m[curr[j]].end(),last); //from that vector of indexes of each char , we find the character greater than the last
                if(it==m[curr[j]].end())  //if not fround then break
                    break;
                last=*it;    
                if(j==curr.size()-1)cnt++;  //if all character of word matches , then increment count
            }
        }
        return cnt;
    }
};