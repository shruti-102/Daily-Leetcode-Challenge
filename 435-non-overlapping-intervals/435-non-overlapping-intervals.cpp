class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int count=0,n=inter.size();
        sort(inter.begin(),inter.end());
        
        for(int i=0;i<n;i++){
            cout<<inter[i][0]<<","<<inter[i][1]<<" ";
        }cout<<endl;
        int e=inter[0][1];
        for(int i=1;i<n;i++){
            if(e>inter[i][0] ){  //overlpping
                count++;
                e=min(e,inter[i][1]);
            }
            else e=inter[i][1];
        }
        return count;
    }
};