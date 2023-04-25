class SmallestInfiniteSet {
public:
    set<int> s;

    SmallestInfiniteSet() {
        // WORST CASE 1000 elements would be popping out.
        for(int i=1; i<1005;i++) s.emplace(i);
    }
    
    int popSmallest() {
       const int top = *s.begin(); // * is used to dereference and pass the actual value;
        s.erase(s.begin()); // first element is the smallest in the set
        return top;
    }
    
    void addBack(int num) {
        s.emplace(num);
    }
 
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
