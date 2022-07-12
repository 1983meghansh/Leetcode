class Solution {
public:
    vector<int>sides={0,0,0,0};
    bool solve(int ind,vector<int>&v,int x){
        
        if(ind==v.size()){
            return 1;
        }
        
        for(int k=0;k<4;k++){
            if(sides[k]+v[ind]<=x){
                sides[k]+=v[ind];
                if(solve(ind+1,v,x)) return 1;
                sides[k]-=v[ind];
            }
        }
        return 0;    
    }
    bool makesquare(vector<int>& mat) {
        int sum=0;
        for(int i=0;i<mat.size();i++){
            sum+=mat[i];
        }
        
        if(sum%4!=0) return 0;
        sort(mat.begin(),mat.end(),greater<>());
        
        return solve(0,mat,sum/4);
        
        
    }
};