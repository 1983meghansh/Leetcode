class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.length();
        int l=0,r=0;
        int cnt=0;
        int ans1=0;
        //change T to F
        while(r<n)
        {
            if(s[r]=='T')
                cnt++;
            while(cnt>k)
            {
                if(s[l]=='T')
                    cnt--;
                l++;
            }
            ans1=max(r-l+1,ans1);
            r++;
        }
        //now change to F
        int ans2=0;
          l=0,r=0;
         cnt=0;
         while(r<n)
        {
            if(s[r]=='F')
                cnt++;
            while(cnt>k)
            {
                if(s[l]=='F')
                    cnt--;
                l++;
            }
            ans2=max(r-l+1,ans2);
            r++;
        }
        int ans=0;
        ans=max(ans1,ans2);
        return ans;
    }
};