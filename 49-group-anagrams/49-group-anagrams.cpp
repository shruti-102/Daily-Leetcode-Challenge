class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            string temp=s;
            sort(temp.begin(),temp.end());
            
            if(mp.find(temp) != mp.end())
            {
                mp[temp].push_back(s);
            }
            else
            {
                mp[temp].push_back(s);
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};