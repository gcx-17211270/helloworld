package Internet.TCPIP;

import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * 类的作用:        服务器端程序。
 * Description:     建立ServerSocket监听，使用Socket获取输出能力。
 * @param
 * @return:
 * @Date:       2020/10/2 22:42
 * @author:     32353
*/

public class Server {
    public static void main(String[] args) throws IOException
    {
        //创建一个ServerSocket，用于监听客户端Socket的连接请求
        var ss = new ServerSocket(3000);
        ss.setSoTimeout(10000);
        //采用循环不断地接受来自客户端的请求
        while (true)
        {
            //每当接收到客户端Socket的请求时，服务器端也对应产生一个Socket
            Socket s = ss.accept();
            //将Socket对应的输出流包装成PrintStream
            var ps = new PrintStream(s.getOutputStream());
            //进行普通IO操作
            ps.println("您好，您收到了服务器的新年祝福");
            //关闭输出流，关闭Socket
            ps.close();
            s.close();
        }
    }
}
