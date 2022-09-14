class Solution {
public:
    
   // consider 1 -> player1
   // consider -1 -> player2
    int solve(vector<int>& nums,int s,int e,int player)
    {
        if(s==e) return player*nums[s];
        int choice1=player* nums[s]+ solve(nums,s+1,e,player*-1);
        int choice2=player*nums[e]+solve(nums,s,e-1,player*-1);
        
        if(player<0) return min(choice1,choice2);
        else return max(choice1,choice2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        if(solve(nums,0,nums.size()-1,1)>=0) return true;
        return false;
    }
};