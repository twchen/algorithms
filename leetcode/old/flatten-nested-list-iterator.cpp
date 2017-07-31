/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// recursive
// 32ms
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        currListPtr_ = &nestedList;
        size_ = nestedList.size();
        pos_ = 0;
        subIteratorPtr_ = NULL;
    }

    ~NestedIterator(){
        delete subIteratorPtr_;
        subIteratorPtr_ = NULL;
    }

    int next() {
        if(subIteratorPtr_){
            return subIteratorPtr_->next();
        }else{
            return (*currListPtr_)[pos_++].getInteger();
        }
    }

    bool hasNext() {
        if(subIteratorPtr_){
            if(subIteratorPtr_->hasNext()){
                return true;
            }else{
                delete subIteratorPtr_;
                subIteratorPtr_ = NULL;
                ++pos_;
                return hasNext();
            }
        }else{
            if(pos_ < size_){
                NestedInteger &curr = (*currListPtr_)[pos_];
                if(curr.isInteger()){
                    return true;
                }else{
                    subIteratorPtr_ = new NestedIterator(curr.getList());
                    return hasNext();
                }
            }else{
                return false;
            }
        }
    }

private:
    vector<NestedInteger> *currListPtr_;
    int size_;
    int pos_;
    NestedIterator *subIteratorPtr_;
};

// iterative
// 28ms
class NestedIterator {
public:
    typedef pair<vector<NestedInteger>*, int> Pair;

    NestedIterator(vector<NestedInteger> &nestedList) {
        currListPtr_ = &nestedList;
        pos_ = 0;
    }

    int next() {
        return (*currListPtr_)[pos_++].getInteger();
    }

    bool hasNext() {
        while(pos_ >= currListPtr_->size()){
            if(mystack_.empty()) return false;
            else{
                Pair foo = mystack_.top();
                mystack_.pop();
                currListPtr_ = foo.first;
                pos_ = foo.second;
            }
        }

        while(!(*currListPtr_)[pos_].isInteger()){
            Pair foo(currListPtr_, pos_ + 1);
            mystack_.push(foo);
            currListPtr_ = &((*currListPtr_)[pos_].getList());
            pos_ = 0;

            // the following block can be replaced by
            // return hasNext();
            while(pos_ >= currListPtr_->size()){
                if(mystack_.empty()) return false;
                else{
                    Pair foo = mystack_.top();
                    mystack_.pop();
                    currListPtr_ = foo.first;
                    pos_ = foo.second;
                }
            }
        }

        return true;
    }

private:
    vector<NestedInteger> *currListPtr_;
    int pos_;
    stack<Pair> mystack_;
};
