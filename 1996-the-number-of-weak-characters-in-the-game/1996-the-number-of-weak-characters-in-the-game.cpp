class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end()); //O(n logn)
        
        // O(n) for the rest of the algo
        int weakCount = 0;
        int maxDefenseSoFar = properties.back()[1];
        int i = n-2;
        while(i >= 0 && properties[i][0] == properties[n-1][0]) {
            maxDefenseSoFar = max(maxDefenseSoFar, properties.back()[1]);
            i--;
        }
        while(i >= 0) {
            int maxDefense = properties[i][1], maxAttack = properties[i][0];
            while(i >= 0 && properties[i][0] == maxAttack) {
                maxDefense = max(maxDefense, properties[i][1]);
                if(properties[i][1] < maxDefenseSoFar) weakCount++;
                i--;
            }
            maxDefenseSoFar = max(maxDefenseSoFar, maxDefense);
        }
        return weakCount;
    }
};
