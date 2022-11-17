class RandomizedSet {
public:
    vector<int> v;
    int indx=0;
     unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()) {
            v.push_back(val);
            mp[val]=v.size()-1;
           // indx++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            int last=v.back();  // back() fetches last element of the array vector
            v[mp[val]]=v.back(); // m[val] locates the index of val in the array vector.
				                // Then we copy array last element value to the val location in the array
            v.pop_back();	    // Delete the last element of the array 
            mp[last]=mp[val];	    // In hashmap, assign index of val in array to the index of the last element   
            mp.erase(val);	    // Delete the val entry from map
            return true;
        }
        return false;
    }
    
    int getRandom() {
       return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */