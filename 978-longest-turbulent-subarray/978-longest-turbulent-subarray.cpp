class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()<2)
            return arr.size();
        int st=0,end=0;
        int n=arr.size();
        int res=1;
        while(st+1<n)
        {
            if(arr[st]==arr[st+1])
            {
                st++;
                continue;
            }
            end=st+1;
            //check if valley or peak then increment end
            while(end+1<n and isturbulent(arr,end))
            {
                end++;
            }
            res=max(end-st+1,res);
            st=end;
            
        }
        return res;
    }
    bool isturbulent(vector<int>& arr,int idx)
    {
        return (arr[idx+1]>arr[idx] and arr[idx-1]>arr[idx]) or (arr[idx+1]<arr[idx] and arr[idx-1]<arr[idx]);
    }
};