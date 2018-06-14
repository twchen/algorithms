/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

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
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList)
        : it(nullptr), flag(false), val(0), i(0), nestedList(nestedList), n(nestedList.size()) {

    }
    
    ~NestedIterator(){
        delete it;
    }

    int next() {
        if(!flag){
            flag = hasNext();
            if(!flag)
                throw out_of_range("No next element");
        }
        flag = false;
        return val;
    }

    bool hasNext() {
        if(flag) return true;
        if(it && it->hasNext()){
            flag = true;
            val = it->next();
            return true;
        }
        if(i == n) return false;
        if(nestedList[i].isInteger()){
            flag = true;
            val = nestedList[i].getInteger();
        }else{
            delete it;
            it = new NestedIterator(nestedList[i].getList());
        }
        ++i;
        return hasNext();
    }

private:
    vector<NestedInteger> &nestedList;
    NestedIterator *it;
    int i;
    int n;
    bool flag;
    int val;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// credit: https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80146/Real-iterator-in-Python-Java-C++
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while(!begins.empty()){
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }else{
                auto it = begins.top();
                if(it->isInteger())
                    return true;
                ++begins.top();
                begins.push(it->getList().begin());
                ends.push(it->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::const_iterator> begins;
    stack<vector<NestedInteger>::const_iterator> ends;
};
