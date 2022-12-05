class Solution {
public:
    static bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second > b.second;
}
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<char, int> > A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : mp) {
        A.push_back(it);
    }
        sort(A.begin(),A.end(),cmp);
        string ans="";
        for(auto it:A){
            for(int j=0;j<it.second;j++){
                ans+=it.first;
            }
        }
        return ans;
    }
};