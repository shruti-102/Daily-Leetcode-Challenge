class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    int maxScore = 0;
    vector<int> front(k+1), rear(k+1);
    front[0] = rear[0] = 0;

    // calculate prefix sum of the 1st k elements in front and last k elements in rear
    // arr: [1,2,3,4,5,6,1], k=3
    // front: [0,1,3,6], rear: [0,1,7,12]
    for(int i=0;i<k;i++){
        front[i+1] = front[i]+cardPoints[i];
        rear[i+1] = rear[i] + cardPoints[n-1-i];
    }

    // just add relevant prefix sums from front and rear to get the currentScore
    for(int i=0;i<=k; i++){
        int currentScore = front[i] + rear[k-i];
        maxScore = max(maxScore, currentScore);
    }
    return maxScore;
}
};