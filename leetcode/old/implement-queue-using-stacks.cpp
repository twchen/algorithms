/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

// solution 2: simpler solution
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(rev.size()){
            s.push(rev.top());
            rev.pop();
        }
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(s.size()){
            rev.push(s.top());
            s.pop();
        }
        rev.pop();
    }

    // Get the front element.
    int peek(void) {
        while(s.size()){
            rev.push(s.top());
            s.pop();
        }
        return rev.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty() && rev.empty();
    }
    
private:
    stack<int> s;
    stack<int> rev;
};

// solution 1
class Queue {
public:
    Queue(){
        size = 0;
    }
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
        ++size;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        --size;
    }

    // Get the front element.
    int peek(void) {
        auto temp = stack<int>();
        while(size--){
            temp.push(s.top());
            s.pop();
        }
        int ret = temp.top();
        s = stack<int>();
        size = temp.size();
        while(temp.size()){
            s.push(temp.top());
            temp.pop();
        }
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return size == 0;
    }
    stack<int> s;
    int size;
};
