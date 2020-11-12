package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��9�� ����12:33:45
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
		if (size < 1) throw new StackEmptyException("���󣬶�ջΪ��");
		Object obj = top.getData();
		top = top.getNext();
		size--;
		return obj;
	}

	@Override
	public Object peek() throws StackEmptyException {
		// TODO Auto-generated method stub
		if (size < 1)
			throw new StackEmptyException("���󣬶�ջΪ��");
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
	int x = 0;	 	//��Ԫ������
	int y = 0;		//��Ԫ������
	boolean visited = false;	//�Ƿ���ʹ�
	char c = ' ';
	public Cell(int x, int y, char c, boolean visited) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
		this.c = c;
		this.visited = visited;
	}

}