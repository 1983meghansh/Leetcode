class Solution {
public:
    int minDeletions(string s) {
         vector<int> freq(26, 0);
        for(char c: s) freq[c-'a']++;       
        int count = 0;
        sort(begin(freq), end(freq), greater<int>());        
        for(int i=1; i<26; i++){
            while(freq[i] != 0 and freq[i-1] <= freq[i]) {  
                freq[i]--, ++count;
            }
        }
        return count;
    }
    
};