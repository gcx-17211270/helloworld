/**
 * 
 */
package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��7�� ����3:54:26
*/

public interface List {
	public int getSize();
	public boolean isEmpty();
	public boolean contains(Object e);
	public int indexOf(Object e);
	public void insert(int i, Object e)throws OutOfBoundaryException;
	public boolean insertBefore(Object obj, Object e);
	//������Ԫ��e ���뵽Ԫ��obj ֮��
	public boolean insertAfter(Object obj, Object e);
	//ɾ�����Ա������Ϊi ��Ԫ��,������֮
	public Object remove(int i) throws OutOfBoundaryException;
	//ɾ�����Ա��е�һ����e ��ͬ��Ԫ��
	public boolean remove(Object e);
	//�滻���Ա������Ϊi ������Ԫ��Ϊe������ԭ����Ԫ��
	public Object replace(int i, Object e) throws OutOfBoundaryException;
	//�������Ա������Ϊi ������Ԫ��
	public Object get(int i) throws OutOfBoundaryException;
}
