class Solution {
public:
    int firstUniqChar(string s) {
        map<char,pair<int,int>> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]={i,1};
            }
            else
            {
                mp[s[i]].second++;
            }
        }
        
        for(auto it: mp)
        {
            cout<<it.first<<": "<<it.second.first<<" "<<it.second.second<<endl;
        }
        int minindx=s.size();
        for(auto it: mp)
        {
            if(it.second.second==1)
            {
                //cout<<it.second.first;
                if(it.second.first<minindx)
                {
                    minindx=it.second.first;
                }
            }
        }
        if(minindx==s.size()) return -1;
        return minindx;
    }
};