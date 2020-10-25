package tree;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月15日 下午10:22:33
*/

public interface Strategy {
	public boolean equal(Object obj1, Object obj2);
	public int compare(Object obj1, Object obj2);
}
