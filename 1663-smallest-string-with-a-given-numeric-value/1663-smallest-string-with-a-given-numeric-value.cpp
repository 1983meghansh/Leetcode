class Solution {
public:
    string getSmallestString(int n, int k) {
        //build a string of all 'a' of length n.then traverse the string from end and increment string until its value doesnt reach target
        string ans(n,'a');
        int i=n-1;
        k=k-n;
        while(k>0)
        {
            int temp=min(k,25);
            ans[i]+=temp;
            k-=temp;
            i--;
        }
        return ans;
    }
};