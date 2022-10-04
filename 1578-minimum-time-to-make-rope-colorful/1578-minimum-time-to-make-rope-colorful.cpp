class Solution {
public:
    int minCost(string colors, vector<int>& tym) {
        int n=colors.size();
        vector<int> a(n,0);
        
        int i=0,j;
        while(i<n){
            if(i+1<n && colors[i]==colors[i+1]){
                int maxval=tym[i],indx=i;
                for(j=i;j<n && colors[j]==colors[i];j++){
                    if(maxval<tym[j]){
                        maxval=tym[j];
                        indx=j;
                    }
                }
                a[indx]=1;
                i=j;
            }
            else {
                a[i]=1;
                i++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) ans+=tym[i];
        }
        return ans;
    }
};