class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        int n=changed.size();
        if(n==1) return ans;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
        
        sort(changed.begin(),changed.end());
        
        for(int i=0;i<n;i++)
        {
           auto [n, cnt] = *mp.begin();
            if (n == 0) {
                if (cnt % 2) return {}; // count of `0` is odd.
                for (int j = 0; j < cnt / 2; ++j) ans.push_back(0);
                mp.erase(0);
            }
            int val=changed[i]*2;
            if(mp[changed[i]]>0){
                if(mp.find(val) != mp.end()) 
                {
                    if(mp[val]>0)
                    {
                        ans.push_back(changed[i]);
                        mp[val]--;
                        mp[changed[i]]--;
                    }
                    else
                    {
                        return {};
                    }
                }
                else
                    return {};
            }
        }
        return ans;
    }
};