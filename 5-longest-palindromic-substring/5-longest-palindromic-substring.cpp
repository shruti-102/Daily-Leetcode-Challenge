class Solution {
    pair<int, int> isPalin(const string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
                
        return {l, r};
    }

    
public:
    string longestPalindrome(string s) {
        pair<int, int> result;
        
        for (int i = 0, j = 0; i < s.size();) {
            auto [l, r] = isPalin(s, i, j);
            if (r - l > result.second - result.first){
                result.first = l;
                result.second = r;
            }
            
            if (i == j)
                ++j;
            else
                ++i;
            
        }
        
        return s.substr(result.first + 1, result.second - result.first - 1);
    }
};
