package Internet.TCPIP.MultiThread;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * 类的作用:        服务器端线程类
 * Description:     负责处理每个线程通信的线程类
 *                  程序使用readFromClient()方法来读取客户端数据，如果读取过程中捕获到IOException异常，
 *              则表明该Socket对应的客户端出现了问题，程序就将Socket从socketList集合中删除。
 * @param
 * @return:
 * @Date:       2020/10/2 23:32
 * @author:     32353
*/

public class ServerThread implements Runnable
{
    //定义当前线程所处理的Socket
    Socket s = null;
    //该线程所处理的Socket对应的输入流
    BufferedReader br = null;
    public ServerThread (Socket s) throws IOException
    {
        this.s = s;
        //初始化该Socket对应的输入流
        br = new BufferedReader (new InputStreamReader(s.getInputStream()));
    }
    @Override
    public void run()
    {
        try
        {
            String content = null;
            //采用循环不断地从Socket中读取客户端发送过来的数据
            while ((content = readFromClient()) != null)
            {
                //遍历socketList中每个Socket
                //将读到的内容向每个Socket发送一次
                for (var s : MyServer.socketList)
                {
                    var ps = new PrintStream(s.getOutputStream());
                    ps.println(content);
                }
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    //定义读取客户端数据的方法
    private String readFromClient() {
        try
        {
            return br.readLine();
        }
        //如果捕获到异常，表明该Socket对应的客户端已经关闭
        catch (IOException e)
        {
            //删除该Socket
            MyServer.socketList.remove(s);
        }
        return null;
    }
}
