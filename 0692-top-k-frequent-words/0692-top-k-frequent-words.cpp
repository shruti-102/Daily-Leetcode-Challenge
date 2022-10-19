class Solution {
public:
    static bool cmp(pair<string,int> &a, pair<string,int> &b){
        return a.second>=b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        vector<vector<string>> v(n);
        
        unordered_map<string,int> mp;
        for(auto wrd: words){
            mp[wrd]++;
        }
        
        map<int,vector<string>, greater<int> > mp2;
        
        for(auto it: mp){
            //cout<<it.first<<" ";
            //cout<<it.second<<endl;
            mp2[it.second].push_back(it.first);
        }
        
       
        vector<string> ans;
        int c,sz;
        for(auto it: mp2){
            if(k<=0) break;
            vector<string> temp=it.second;
            sort(temp.begin(),temp.end());
            c=0;
            sz=temp.size();
            while(k>0 && c<sz){
                ans.push_back(temp[c]);
                c++;
                k--;
            }
        }
        return ans;
    }
};