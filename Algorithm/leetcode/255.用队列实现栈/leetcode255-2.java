class MyStack
{
	Queue<Integer> list;
	
	/** Initialize your data structure here */
	public MyStack()
	{
		list = new LinkedList<>();
	}
	
	/** Push element x onto stack */
	public void push(int x)
	{
		list.add(x);
	}
	
	/** Removes the element on top of the stack an returns that element. */
	public int pop()
	{
		for(int i = 0; i < list.size() - 1; i++)
			list.add(list.poll());
		int res = list.poll();
		list.add(res);
		return res;
	}
	
	/** Get the top element. **/
	public int top()
	{
		for (int i = 0; i < list.size()-1; i++)
			list.add(list.poll());
		int res = list.poll();
		list.add(res);
		return res;
	}
	
	/** Returns whether the stack is empty. */
	public boolean empty()
	{
		return list.peek() == null ? false : true;
	}
}