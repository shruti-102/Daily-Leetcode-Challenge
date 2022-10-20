class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        int temp=num;
        while(num!=0){
            v.push_back(num%10);
            num=num/10;
        }
        sort(v.begin(),v.end());
        int oneway=(v[0]*10+v[3])+(v[1]*10+v[2]);
        int secondway=(v[0]*10+v[2])+(v[1]*10+v[3]);
        return min(oneway,secondway);
    }
};