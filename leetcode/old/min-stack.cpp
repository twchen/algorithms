/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        if(mins.empty() || x <= mins.top()){
            mins.push(x);
        }
        s.push(x);
    }

    void pop() {
        if(s.top() == mins.top()){
            mins.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }

private:
    stack<int> s;
    stack<int> mins;
};
