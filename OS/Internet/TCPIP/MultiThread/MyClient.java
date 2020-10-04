package Internet.TCPIP.MultiThread;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * 类的作用:        客户端主程序
 * Description:     读取用户键盘输入的线程
 * @param
 * @return:
 * @Date:       2020/10/3 0:20
 * @author:     32353
*/

public class MyClient {
    public static void main(String[] args) throws Exception
    {
        var s = new Socket("127.0.0.1", 30000);
        //客户端启动ClientThread线程不断地读取来自服务器的数据
        new Thread(new ClientThread(s)).start();
        //获取该Socket对应的输出流
        var ps = new PrintStream(s.getOutputStream());
        String line = null;
        //不断地读取键盘输入
        var br = new BufferedReader(
                new InputStreamReader(System.in));
        while ((line = br.readLine()) != null)
        {
            //将用户的键盘输入内容写入Socket对应的输出流
            ps.println(line);
        }
    }
}
