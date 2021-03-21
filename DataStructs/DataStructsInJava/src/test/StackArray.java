package test;
//����4-3 Stack��˳��洢ʵ��
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��9�� ����12:17:35
*/

public class StackArray implements Stack {
	private final int LEN = 8;	//�����Ĭ�ϴ�С
	private Object[] elements;	//����Ԫ������
	private int top;			//ջ��ָ��
	public StackArray() {
		// TODO Auto-generated constructor stub
		top = -1;
		elements = new Object[LEN];
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return top + 1;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return top < 0;
	}

	@Override
	public void push(Object e) {
		// TODO Auto-generated method stub
		if (getSize() > elements.length) expandSpace();
		elements[++top] = e;
	}
	private void expandSpace()
	{
		Object[] a = new Object[elements.length * 2];
		for (int i = 0; i < elements.length; i++)
			a[i] = elements[i];
		elements = a;
	}

	@Override
	public Object pop() throws StackEmptyException {
		// TODO Auto-generated method stub
		if (getSize() < 1)
			throw new StackEmptyException("���󣬶�ջΪ��");
		Object obj = elements[top];
		elements[top--] = null;
		return obj;
	}

	@Override
	public Object peek() throws StackEmptyException {
		// TODO Auto-generated method stub
		if (getSize() < 1)
			throw new StackEmptyException("���󣬶�ջΪ��");
		return elements[top];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack stack = new StackArray();
		System.out.println(stack.isEmpty());
	}

}
