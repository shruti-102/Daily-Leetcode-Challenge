class StockSpanner {
public:
    vector<int>v;
    stack<pair<int, int>>st;
    int x;
    StockSpanner() { 
    }
    
    int next(int price) {
        x = 1;
        while(!st.empty() && st.top().first<=price){
            x+=st.top().second;
            st.pop();
        }
        st.push({price, x});
        return x;
    }
};