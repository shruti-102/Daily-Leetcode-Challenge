class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int prefixsum=0;
        for(int i=0;i<k;i++){
            prefixsum+=card[i];
        }
        int n=card.size();
        int s=k,e=n-1;
        int maxscore=prefixsum;
        while(s>0 && s<n){
            prefixsum-=card[s-1];
            prefixsum+=card[e];
            s--;
            e--;
            maxscore=max(maxscore,prefixsum);
        }
        return maxscore;
    }
};