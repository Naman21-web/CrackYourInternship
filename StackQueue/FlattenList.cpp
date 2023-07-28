class NestedIterator {
public:
    
    vector<int> res;
    int idx=0;
    void flattenlist(vector<NestedInteger> &nestedList){
        for(auto x:nestedList){
            if(x.isInteger()){
                res.push_back(x.getInteger());
            }
            else{
                flattenlist(x.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenlist(nestedList);
    }
    
    int next() {
        idx++;
        return res[idx-1];
    }
    
    bool hasNext() {
        if(idx==res.size()) return false;
        return true; 
    }
};