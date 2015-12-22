/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/


// simpler solution
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = q.size();
        for(int i=0; i<size-1; ++i){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};


// my solution
class Stack {
public:
    Stack(){
        q = new queue<int>();
        size = 0;
    }
    ~Stack(){
        delete q;
    }
    // Push element x onto stack.
    void push(int x) {
        q->push(x);
        ++size;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(size == 1){
            delete q;
            q = new queue<int>();
        }
        --size;
    }

    // Get the top element.
    int top() {
        auto new_q = new queue<int>();
        for(int i=size; i>1; --i){
            new_q->push(q->front());
            q->pop();
        }
        int ret = q->front();
        q->pop();
        new_q->push(ret);
        delete q;
        q = new_q;
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return size == 0;
    }
    queue<int> *q;
    int size;
};
