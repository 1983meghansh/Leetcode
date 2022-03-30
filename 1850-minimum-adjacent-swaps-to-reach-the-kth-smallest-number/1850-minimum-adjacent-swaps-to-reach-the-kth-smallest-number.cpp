class Solution {
public:
    int getMinSwaps(string num, int k) {
        //wonderful greedy problem , do again
        string target(num);
        for(int i=0;i<k;i++)
        {
            next_permutation(target.begin(),target.end());
        }
        int ans=0;
        int sz=num.size();
        for(int i=0;i<sz;i++)
        {
            if(num[i]!=target[i])
            {
                int j=i+1;
                while(num[j]!=target[i])
                    j++;
                for(;j>i;j--)
                swap(num[j],num[j-1]),ans++;
            }
        }
        return ans;
    }
};