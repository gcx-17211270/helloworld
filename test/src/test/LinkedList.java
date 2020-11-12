package test;

/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��7�� ����3:33:48
*/

public interface LinkedList {
	//��ѯ���ӱ�ǰ�Ĺ�ģ
	public int getSize();
	//�ж��б��Ƿ�Ϊ��
	public boolean isEmpty();
	//���ص�һ�����
	public Node first() throws OutOfBoundaryException;
	//�������һ�����
	public Node last() throws OutOfBoundaryException;
	//����p֮��Ľ��
	public Node getNext(Node p) throws InvalidNodeException, OutOfBoundaryException;
	//����p֮ǰ�Ľ��
	public Node getPre(Node p) throws InvalidNodeException, OutOfBoundaryException;
	//��e��Ϊ��һ��Ԫ�ز������ӱ�������e���ڽ��
	public Node insertFirst(Object e);
	//��e��Ϊ���һ��Ԫ�ز������ӱ�������e���ڽ��
	public Node inserLast(Object e);
	//��e������p֮���λ�ã�������e���ڽ��
	public Node insertAfter(Node p, Object e) throws InvalidNodeException;
	//��e������p֮ǰ��λ�ã�������e���ڽ��
	public Node insertBefore(Node p, Object e) throws InvalidNodeException;
	//ɾ������λ�ô���Ԫ�أ�������֮
	public Object remove(Node p) throws InvalidNodeException;
	//ɾ����Ԫ�أ�������֮
	public Object removeFirst() throws OutOfBoundaryException;
	//ɾ��ĩԪ�أ�������֮
	public Object removeLast() throws OutOfBoundaryException;
	//�����ڸ���λ�õ�Ԫ���滻Ϊ��Ԫ�أ������ر��滻��Ԫ��
	public Object replace(Node p, Object e) throws InvalidNodeException;
	//Ԫ�ص�����
	public Iterator elements();
}
