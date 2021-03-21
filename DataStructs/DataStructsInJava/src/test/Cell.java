package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月9日 上午10:25:21
*/

class Cell1{
	int x = 0;	 	//单元所在行
	int y = 0;		//单元所在列
	boolean visited = false;	//是否访问过
	char c = ' ';
	public Cell1(int x, int y, char c, boolean visited) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
		this.c = c;
		this.visited = visited;
	}

}
