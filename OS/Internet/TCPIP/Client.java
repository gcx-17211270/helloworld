package Internet.TCPIP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

/**
 * 类的作用:        客户端程序
 * Description:     它使用Socket建立与指定IP地址、指定端口的连接，并使用Socket获取输入流读取数据。
 * @param
 * @return:
 * @Date:       2020/10/2 22:52
 * @author:     32353
*/

public class Client {
    public static void main(String[] args) throws IOException
    {
        var socket = new Socket("127.0.0.1", 3000);;
        socket.setSoTimeout(10000);
        //将Socket对应的输入流包装成BufferedReader
        var br = new BufferedReader(
                new InputStreamReader(socket.getInputStream()));
        //进行普通IO操作
        String line = br.readLine();
        System.out.println("来自服务器的数据：" + line);
        //关闭输入流，关闭Socket
        br.close();
        socket.close();
    }
}
