class MyStack {
private:	
	queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
		queue<int> temp;
		int t = 0;
		int length = que.size();
		for(int i = 0; i < length; i++)
		{
			t = que.front();
			que.pop();
			temp.push(t);
		}
		que.push(x);
		//cout << x << " ";
		for(int i = 0; i < length; i++)
		{
			t = temp.front();
			que.push(t);
			temp.pop();
			//cout << t << " ";
		}
		//cout << endl;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		if(que.empty())
			return 0;
		int t = que.front();
		que.pop();
		return t;
    }
    
    /** Get the top element. */
    int top() {
		if(que.empty())
			return 0;
		return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return que.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
