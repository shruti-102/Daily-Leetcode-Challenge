class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> trusted(n+1,0);
        vector<int> truston(n+1,0);
        
        for(int i=0;i<trust.size();i++){
            truston[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(trusted[i]==n-1 && truston[i]==0) return i;
        }
        return -1;
    }
};