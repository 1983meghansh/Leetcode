// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>stk;
        for(int i=0;i<M.size();i++)
        stk.push(i);
        
        while(stk.size()>=2)
        {
            int first=stk.top();
            stk.pop();
            int sec=stk.top();
            stk.pop();
            if(M[first][sec]==1)
            stk.push(sec);
            else
            stk.push(first);
        }
        int pot=stk.top();
        stk.pop();
        for(int i=0;i<M.size();i++)
        {
            if(i!=pot)
            {
                if(M[i][pot]==0 or M[pot][i]==1)
                return -1;
            }
        }
        return pot;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends