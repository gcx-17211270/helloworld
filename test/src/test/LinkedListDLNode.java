package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��7�� ����4:05:01
*/

public class LinkedListDLNode implements LinkedList {
	private int size;
	private DLNode head;
	private DLNode tail;
	public LinkedListDLNode() {
		// TODO Auto-generated constructor stub
		size = 0;
		head = new DLNode();
		tail = new DLNode();
		head.setNext(tail);
		tail.setPre(head);
	}
	//�����������жϽ��p�Ƿ�Ϸ�����Ϸ�ת��ΪDLNode
	protected DLNode checkPosition(Node p) throws InvalidNodeException
	{
		if (p == null)
			throw new InvalidNodeException("����pΪ��");
		if (p == head)
			throw new InvalidNodeException("����pָ��ͷ�ڵ㣬�Ƿ�");
		if (p == tail)
			throw new InvalidNodeException("����pָ��β�ڵ㣬�Ƿ�");
		DLNode node = (DLNode)p;
		return node;
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
	public Node first() throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (isEmpty())
			throw new OutOfBoundaryException("�������ӱ�Ϊ��");
		return head.getNext();
	}

	@Override
	public Node last() throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (isEmpty())
			throw new OutOfBoundaryException("�������ӱ�Ϊ��");
		return tail.getPre();
	}

	@Override
	public Node getNext(Node p) throws InvalidNodeException, OutOfBoundaryException {
		// TODO Auto-generated method stub
		DLNode node = checkPosition(p);
		node = node.getNext();
		if (node == tail)
			throw new OutOfBoundaryException("�����Ѿ������ӱ�β�ˡ�");
		return node;
	}

	@Override
	public Node getPre(Node p) throws InvalidNodeException, OutOfBoundaryException {
		// TODO Auto-generated method stub
		DLNode node = checkPosition(p);
		node = node.getPre();
		if (node == head)
			throw new OutOfBoundaryException("�����Ѿ������ӱ�ǰ��");
		return node;
	}

	@Override
	public Node insertFirst(Object e) {
		// TODO Auto-generated method stub
		DLNode node = new DLNode(e, head, head.getNext());
		head.getNext().setPre(node);
		head.setNext(node);
		size++;
		return null;
	}

	@Override
	public Node inserLast(Object e) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Node insertAfter(Node p, Object e) throws InvalidNodeException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Node insertBefore(Node p, Object e) throws InvalidNodeException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object remove(Node p) throws InvalidNodeException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object removeFirst() throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object removeLast() throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object replace(Node p, Object e) throws InvalidNodeException {
		// TODO Auto-generated method stub
		return null;
	}
	//Ԫ�ص�����
	public Iterator elements()
	{ 
		return new LinkedListIterator(this);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedListDLNode dl = new LinkedListDLNode();
		dl.insertFirst("Hello world!");
		System.out.println(dl.head.getNext().getData());
	}

}
