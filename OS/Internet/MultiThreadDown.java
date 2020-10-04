package Internet;
/**
 * @ param     :    使用DownUtil类，在主程序中执行下载
 * @ return    :
 * @ Description:   为什么下载的很奇怪，不是图片原来的模样
 * @ Date       :2020/10/2 15:42
 * @ author     :32353
*/


public class MultiThreadDown {
    public static void main(String[] args) throws Exception
    {
        //初始化DownUtil对象
        final var downUtil = new DownUtil ("https://imgsa.baidu.com/forum/w%3D580/sign=a310db5cf7dcd100cd9cf829428a47be/0e1f82b7d0a20cf4a97a8f8e79094b36adaf9912.jpg",
               // + "data/attachment/forum/month_1403/1403202355ff6cc9a4fbf6f14a.png",
                "D:/ios.jpg", 4);
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
                        catch (Exception ex) {
                            ex.printStackTrace();
                        }
                    }
                }
        ).start();
    }
}
