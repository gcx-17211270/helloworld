package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 下午4:25:32
*/

public interface Iterator {
	public void first();
	public void next();
	public boolean isDone();
	public Object currentItem();
}
