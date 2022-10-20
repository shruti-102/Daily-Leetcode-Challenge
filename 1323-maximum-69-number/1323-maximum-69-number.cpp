class Solution {
public:
    int maximum69Number (int num) {
        int temp=num,count=0;
        vector<int> v;
        while(num!=0){
            v.push_back(num%10);
            num=num/10;
        }
        reverse(v.begin(),v.end());
        int i;
        for(int i=0;i<v.size();i++){
            if(v[i]==9) count++;
        }
        if(count==v.size()) return temp;
        for(i=0;i<v.size();i++){
            if(v[i]==9) continue;
            else break;
        }
        v[i]=9;
        
        int ans=0;
        for(i=0;i<v.size();i++){
            ans=ans*10+v[i];
        }
        return ans;
    }
};