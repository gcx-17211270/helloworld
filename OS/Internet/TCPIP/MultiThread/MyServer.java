package Internet.TCPIP.MultiThread;
/**
 * 类的作用:        服务器端的实现代码
 * Description:     程序为服务器端提供了两个类，一个是创建ServerSocket监听的主类，一个是负责处理
 *              每个Socket通信的线程类。
 *                  本类实现了服务器端只负责接收客户端Socket的连接请求，每当客户端Socket连接到该
 *              ServerSocket之后，程序将对应Socket加入socketList集合中保存，并为该Socket启动一个
 *              线程，该线程负责处理Socket所有的通信任务。
 * @param
 * @return:
 * @Date:       2020/10/2 23:30
 * @author:     32353
*/

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MyServer {
    //定义保存所有Socket的ArrayList，并将其包装为线程安全的
    public static List<Socket> socketList = Collections.synchronizedList(new ArrayList<>());
    public static void main(String[] args) throws IOException
    {
        var ss = new ServerSocket(30000);
        while(true)
        {
            //此行代码会阻塞，将一直都等待别人的连接
            Socket s = ss.accept();
            socketList.add(s);
            //每当客户端连接后启动一个ServerThread线程为该客户端服务
            new Thread(new ServerThread(s)).start();
        }
    }
}
