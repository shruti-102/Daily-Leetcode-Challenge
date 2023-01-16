class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),compare);
       /* for(int i=0;i<intervals.size();i++)
        {
            for(int j=0;j<intervals[i].size();j++)
                cout<<intervals[i][j]<<" ";
        }
        */
        stack<pair<int,int>>st,ans;
        //cout<<intervals.size()<<endl;
        for(int i=intervals.size()-1;i>=0;i--){
            st.push(make_pair(intervals[i][0],intervals[i][1]));
        }
        
        while(st.size()>1){
            pair<int,int> p1=st.top();st.pop();
            pair<int,int> p2=st.top();st.pop();
            if(p1.second<p2.first){
                ans.push(p1);
                st.push(p2);
            }
            else if(p1.first==p2.first&&p1.second==p2.second){
                st.push(p2);
            }else if(p1.first==p2.first&&p1.second<p2.second){
                st.push(p2);
            }else if(p1.first==p2.first&&p1.second>p2.second){
                st.push(p1);
            }
            else if(p1.first<p2.first&&p1.second==p2.second){
                st.push(p1);
            }else if(p1.first<p2.first&&p1.second<p2.second){
                st.push(make_pair(p1.first,p2.second));
            }else if(p1.first<p2.first&&p1.second>p2.second){
                st.push(p1);
            }
        }
        ans.push(st.top());
        st.pop();
        vector<vector<int>>a;
        while(ans.size()>0){
            vector<int> v1;
            v1.push_back(ans.top().first);
            v1.push_back(ans.top().second);
            a.push_back(v1);
            ans.pop();
        }
        reverse(a.begin(),a.end());
        return a;
        
        
        
    }
};