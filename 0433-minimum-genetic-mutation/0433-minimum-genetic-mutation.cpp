class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(),bank.end()};
        if(!st.count(end)) return -1;
        queue<string> q;
        q.push(start);
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string cur=q.front();
                q.pop();
                if(cur==end) return steps;
                st.erase(cur);
                
                for(int i=0;i<8;i++){
                   string  t=cur;
				t[i]='A';
				if(st.count(t)) q.push(t);
				t[i]='C';
				if(st.count(t)) q.push(t);
				t[i]='G';
				if(st.count(t)) q.push(t);
				t[i]='T';
				if(st.count(t)) q.push(t);
                }
            }
             steps++;
        }
        cout<<"&&";
        return -1;
    }
};