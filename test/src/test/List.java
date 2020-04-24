/**
 * 
 */
package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 上午3:54:26
*/

public interface List {
	public int getSize();
	public boolean isEmpty();
	public boolean contains(Object e);
	public int indexOf(Object e);
	public void insert(int i, Object e)throws OutOfBoundaryException;
	public boolean insertBefore(Object obj, Object e);
	//将数据元素e 插入到元素obj 之后
	public boolean insertAfter(Object obj, Object e);
	//删除线性表中序号为i 的元素,并返回之
	public Object remove(int i) throws OutOfBoundaryException;
	//删除线性表中第一个与e 相同的元素
	public boolean remove(Object e);
	//替换线性表中序号为i 的数据元素为e，返回原数据元素
	public Object replace(int i, Object e) throws OutOfBoundaryException;
	//返回线性表中序号为i 的数据元素
	public Object get(int i) throws OutOfBoundaryException;
}
