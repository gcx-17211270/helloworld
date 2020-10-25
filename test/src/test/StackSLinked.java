package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月9日 上午12:33:45
*/

public class StackSLinked implements Stack {
	private SLNode top;
	private int size;
	public StackSLinked() {
		// TODO Auto-generated constructor stub
		top = null;
		size = 0;
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return size;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return size == 0;
	}

	@Override
	public void push(Object e) {
		// TODO Auto-generated method stub
		SLNode q = new SLNode(e,top);
		top = q;
		size++;
	}

	@Override
	public Object pop() throws StackEmptyException {
		// TODO Auto-generated method stub
		if (size < 1) throw new StackEmptyException("错误，堆栈为空");
		Object obj = top.getData();
		top = top.getNext();
		size--;
		return obj;
	}

	@Override
	public Object peek() throws StackEmptyException {
		// TODO Auto-generated method stub
		if (size < 1)
			throw new StackEmptyException("错误，堆栈为空");
		return top.getData();
	}
	public void baseConversion(int i) {
		Stack s = new StackSLinked();
		while (i > 0)
		{
			s.push(i % 8 + "");
			i = i / 8;
		}
		while (!s.isEmpty()) System.out.print((String)s.pop());

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack s = new StackSLinked();
		Cell c = new Cell(234,0,'1',false);
		System.out.println(c.x);
	}
}

class Cell {
	int x = 0;	 	//单元所在行
	int y = 0;		//单元所在列
	boolean visited = false;	//是否访问过
	char c = ' ';
	public Cell(int x, int y, char c, boolean visited) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
		this.c = c;
		this.visited = visited;
	}

}