class Solution {
public:
    
    static bool sortfun(vector<int>& a,vector<int>& b)
    {
        if(a[1]>b[1]) return true;
        return false;
    }
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
       int n=boxes.size();
        
        sort(boxes.begin(),boxes.end(),sortfun);
        int res=0;
        for(auto it:boxes)
        {
            int x=min(it[0],truckSize);
            res+=x*it[1];
            truckSize-=x;
            
            if(!truckSize) break;
        }
        return res;
    }
};