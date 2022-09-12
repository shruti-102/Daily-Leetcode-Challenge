class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       sort(tokens.begin(),tokens.end());
        int score=0,maxscore=0;
        
        int l=0,h=tokens.size()-1;
        
        while(l<=h && (power>=tokens[l] || score>=1))
        {
            while(l<=h && power>=tokens[l])
            {
                power-=tokens[l];
                score+=1;
                l++;
            }
            
            maxscore=max(maxscore,score);
            if(l<=h && score>=1)
            {
                score-=1;
                power+=tokens[h];
                h--;
            }
        }
        
        return maxscore;
    }
};