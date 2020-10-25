
package test;

import java.io.FileWriter;
import java.io.IOException;

/**
*@author 作者 高成鑫
*@Version 创建时间:2020年2月27日 上午8:59:48
*/

public class test {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileWriter fw = new FileWriter("1.txt");
		fw.write(100);
		fw.close();
		int a_length = hailstone(1379);
		System.out.println();
		System.out.println(a_length);
}

	private static int hailstone(int n) {
		// TODO Auto-generated method stub
		int length = 1;
		while (1 < n)
		{
			//(n % 2)  ?  n = 3 * n + 1 : n / = 2; 
			if( n % 2 != 0) n = 3 * n + 1;
			else n /= 2;
			System.out.printf("%d ", n);
			length ++;
		}
		return length;
	}
}