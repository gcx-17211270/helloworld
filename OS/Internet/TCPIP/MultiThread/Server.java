package Internet.TCPIP.MultiThread;

import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;

/**
 * 类的作用:        服务器端程序
 * Description:     不同于之前只是建立ServerSocket来监听客户端Socket的连接请求，本程序增加了一些异常处理
 *              看起来会比上一个服务器端程序复杂一些。
 * @param
 * @return:
 * @Date:       2020/10/3 10:48
 * @author:     32353
*/

public class Server {
    private static final int SERVER_PORT = 30000;
    //通过CrazyitMap对象来保存每个客户名字和对应输出流之间的对应关系
    public static CrazyitMap<String, PrintStream> clients = new CrazyitMap<>();
    public void init()
    {
        try(
                //奖励监听的ServerSocket
                /****************************关键代码start0***************************/
                var ss = new ServerSocket(SERVER_PORT))
                /****************************关键代码end0***************************/
        {
            //采用死循环来不断地接收来自客户端的请求
            while(true)
            {
                /****************************关键代码start1***************************/
                var socket = ss.accept();
                new ServerThread2(socket).start();
                /****************************关键代码end1***************************/
            }
        }
        //如果抛出异常
        catch (IOException ex)
        {
           System.out.println("服务器启动失败，是否端口" + SERVER_PORT + "已被占用？");
        }
    }

    public static void main(String[] args)
    {
        var server = new Server();
        server.init();
    }
}
