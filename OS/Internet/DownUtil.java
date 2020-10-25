package Internet;
/**
 * @ param     :    URL、URLConnection和URLPermission
 * @ return    :    工具类
 * @ Description:   URL(Uniform Resource Locator)对象代表统一资源定位器，它是指向互联网资源的指针。
 *              URL类提供了多个构造器用来创建URL对象，一旦获得URL对象之后，就可以调用方法来访问该
 *              URL对应的资源。
 * @ Date       :2020/10/2 13:37
 * @ author     :32353
*/
import java.io.RandomAccessFile;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class DownUtil {
    //定义下载资源的路径
    private String path;
    //指定所下载的文件的保存位置
    private String targetFile;
    //定义需要使用多少线程
    private int threadNum;
    //定义下载的线程对象
    private DownThread[] threads;
    //定义下载的文件的总大小
    private int fileSize;

    public DownUtil(String path, String targetFile, int threadNum)
    {
        this.path = path;
        this.threadNum = threadNum;
        //初始化threads数组
        threads = new DownThread[threadNum];
        this.targetFile = targetFile;
    }

/**
 *  通常创建一个和URL的链接，并发送请求、读取次URL引用的资源需要如下几个步骤
 *      1.通过调用URL对象的openConnetcion()方法来创建URLConnection对象。
 *      2.设置URLConnection的参数和普通请求属性
 *      3.如果只是发送GET方式请求，则使用connect()方法建立和远程资源之间的实际连接即可；
 *  如果需要发送POST方式的请求，则需要获取URLConnection实例对应的输出流来读取远程资源的
 *  数据。
 *      4.远程资源变为可用，程序可以访问远程资源的头字段或通过输入流读取远程资源的数据。
 * */

    public void download() throws Exception
    {
        var url = new URL(path);
        var conn = (HttpURLConnection)url.openConnection();
        conn.setConnectTimeout(5 * 1000);
        conn.setRequestMethod("GET");
        conn.setRequestProperty(
                "Accept",
                "image/gif, image/jpeg, image/pjpeg, image/pjpeg, "
                + "application/x-shockwave-flash, application/xaml + xml, "
                + "application/vnd.ms-xpsdocument, application/x-ms-xbap, "
                + "application/x-ms-application, application/vnd.ms-excel"
                + "application/vnd.ms-powerpoint, application/msword, */*");
        conn.setRequestProperty("Accept-Language", "zh-CN");
        conn.setRequestProperty("Charset", "UTF-8");
        conn.setRequestProperty("Connection", "Keep-Alive");
        //得到文件大小
        fileSize = conn.getResponseCode();
        conn.disconnect();
        int currentPartSize = fileSize / threadNum + 1;
        var file = new RandomAccessFile(targetFile, "rw");
        //设置本地文件的大小
        file.setLength(fileSize);
        file.close();
        for (var i = 0; i < threadNum; i++)
        {
            //计算每个线程下载的开始位置
            var startPos = i * currentPartSize;
            //每个线程使用一个RandomAccessFile进行下载
            var currentPart = new RandomAccessFile(targetFile, "rw");
            //定位该线程的下载位置
            currentPart.seek(startPos);
            //创建下载线程
            threads[i] = new DownThread(startPos, currentPartSize, currentPart);
            //启动下载线程
            threads[i].start();
        }
    }

    //获取下载的完成百分比
    public double getCompleteRate()
    {
        //统计多个线程已经下载的总大小
        var sumSize = 0;
        for (var i = 0; i < threadNum; i++)
        {
            sumSize += threads[i].length;
        }
        //返回已经完成的百分比
        return sumSize * 1.0 / fileSize;
    }

    private class DownThread extends Thread {
        //当前线程的下载位置
        private int startPos;
        //定义当前线程负责下载的文件大小
        private int currentPartSize;
        //当前线程需要下载的文件快
        private RandomAccessFile currentPart;
        //定义该线程已下载的字节数
        public int length;

        public DownThread(int startPos, int currentPartSize,
                          RandomAccessFile currentPart) {
            this.startPos = startPos;
            this.currentPartSize = currentPartSize;
            this.currentPart = currentPart;
        }

        public void run()
        {
            try
            {
                var url = new URL(path);
                var conn = (HttpURLConnection)url.openConnection();
                conn.setConnectTimeout(5 * 1000);
                conn.setRequestMethod("GET");
                conn.setRequestProperty(
                        "Accept",
                        "image/gif, image/jpeg, image/pjpeg, image/pjpeg, "
                                + "application/x-shockwave-flash, application/xaml + xml, "
                                + "application/vnd.ms-xpsdocument, application/x-ms-xbap, "
                                + "application/x-ms-application, application/vnd.ms-excel"
                                + "application/vnd.ms-powerpoint, application/msword, */*");
                conn.setRequestProperty("Accept-Language", "zh-CN");
                conn.setRequestProperty("Charset", "UTF-8");

                InputStream inStream = conn.getInputStream();
                //跳过startPos个字节，表明该线程只下载自己负责的那部分文件
                inStream.skip(this.startPos);
                var buffer = new byte[1024];
                var hasRead = 0;
                //读取网络数据，并写入本地文件
                while( length < currentPartSize
                        && (hasRead = inStream.read(buffer)) != -1)
                {
                    currentPart.write(buffer, 0, hasRead);
                    //累计该线程的下载总大小
                    length += hasRead;
                }
                currentPart.close();
                inStream.close();
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args)
    {
        //初始化DownUtil对象
        final var downUtil = new DownUtil ("https://ss0.bdstatic.com/94oJfD_bAAcT8t7mm9GUKT-xh_/timg?image&quality=100&size=b4000_4000&sec=1601661112&di=414f92533bd450e28f46dfefd38ded05&src=http://a3.att.hudong.com/14/75/01300000164186121366756803686.jpg",
                "ios.jpg", 4);
        //开始下载
        try
        {
            downUtil.download();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        new Thread(
                ()->{
                    while(downUtil.getCompleteRate() < 1)
                    {
                        //每隔0.1秒查询一次任务的完成进度
                        //GUI程序中可根据该进度来绘制进度条
                        System.out.println("已完成：" + downUtil.getCompleteRate());
                        try
                        {
                            Thread.sleep(100);
                        }
                        catch (Exception ex) {}
                    }
                }
        ).start();
    }
}

