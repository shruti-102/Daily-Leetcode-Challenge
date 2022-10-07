class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,set<int>> mp;
        mp[1+stones[0]]={1};
        int n=stones.size();
        for(int i=1;i<n;i++){
            int stone=stones[i];
            
            for(auto it: mp[stone]){
                mp[stone+it].insert(it);
                mp[stone+it-1].insert(it-1);
                mp[stone+it+1].insert(it+1);
            }
        }
        if(mp[stones[n-1]].size()>0) return true;
        return false;
    }
};