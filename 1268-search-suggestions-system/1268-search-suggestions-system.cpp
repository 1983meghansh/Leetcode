class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string sw) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        int l=0;
        for(int i=1;i<=sw.length();i++)
        {
            string prefix=sw.substr(0,i);
            vector<string>ent;
            int ct=0;
            for(int j=0;j<products.size();j++)
            {
                string temp=products[j];
                string trial=temp.substr(0,i);
                if(trial==prefix and ct<3)
                {
                    ent.push_back(temp);
                    ct++;
                }
            }
           
            ans.push_back(ent);
            
        }
        return ans;
    }
};