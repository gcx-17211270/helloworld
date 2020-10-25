package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 下午4:05:01
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
	//辅助方法，判断结点p是否合法，如合法转换为DLNode
	protected DLNode checkPosition(Node p) throws InvalidNodeException
	{
		if (p == null)
			throw new InvalidNodeException("错误：p为空");
		if (p == head)
			throw new InvalidNodeException("错误：p指向头节点，非法");
		if (p == tail)
			throw new InvalidNodeException("错误：p指向尾节点，非法");
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
			throw new OutOfBoundaryException("错误，链接表为空");
		return head.getNext();
	}

	@Override
	public Node last() throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (isEmpty())
			throw new OutOfBoundaryException("错误。链接表为空");
		return tail.getPre();
	}

	@Override
	public Node getNext(Node p) throws InvalidNodeException, OutOfBoundaryException {
		// TODO Auto-generated method stub
		DLNode node = checkPosition(p);
		node = node.getNext();
		if (node == tail)
			throw new OutOfBoundaryException("错误，已经是链接表尾端。");
		return node;
	}

	@Override
	public Node getPre(Node p) throws InvalidNodeException, OutOfBoundaryException {
		// TODO Auto-generated method stub
		DLNode node = checkPosition(p);
		node = node.getPre();
		if (node == head)
			throw new OutOfBoundaryException("错误，已经是链接表前端");
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
	//元素迭代器
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
