class MyCalendarThree {
    map<int, int> y2p; // <year, population>
public:
    MyCalendarThree() {
    }

    //O(n) time
    int book(int start, int end) {
        y2p[start]++;
        y2p[end]--;

        int prefixsum = 0;
        int maxpop = 0;
        // <= 2n times
        // O(n) time
        for(auto& keyval : y2p) {
            prefixsum += keyval.second;
            maxpop = max(maxpop, prefixsum);
        }
        return maxpop;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */