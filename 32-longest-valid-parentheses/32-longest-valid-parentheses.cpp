class Solution {
public:
    int longestValidParentheses(string s) {
        //typical greedy algo , not very intuitive , revise
        stack<int>st;
        st.push(-1);
        int ans=0;
        
        int len=0;
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]=='(')
            {
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    len=i-st.top();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};