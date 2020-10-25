package Internet;
import java.net.*;
/**
 * @ param     :    使用InetAddress类来表示IP地址
 * @ return    :
 * @ Description:   InetAddress类下面有两个子类Inet4Address和Inet6Address,分别代表了
 *              Internet Protocol version 4 和 Internet Protocol version 6
 *                  Inet类没有构造器，但可以使用getByName(String host)或getByAddress(byte[] addr)
 *              根据主机或IP地址来获取相应的IP地址和主机名。
 * @ Date       :2020/10/2 10:48
 * @ author     :32353
*/

public class InetAddressTest {
    public static void main(String[] args) throws Exception
    {
        //根据主机名来获取对应的InetAddress实例
        InetAddress ip = InetAddress.getByName("www.bjtu.edu.cn");
        //判断是否可达
        System.out.println("crazyit 是否可达：" + ip.isReachable(2000));
        //获取改InetAddress实例的IP字符串
        System.out.println(ip.getHostName());
        System.out.println(ip.getAddress());
        System.out.println(ip.getHostAddress());
        System.out.println(ip.getCanonicalHostName());
        System.out.println();

        //根据原始IP地址来获取对应的InetAddress实例
        InetAddress local = InetAddress.getByAddress(
                new byte[] {127, 0, 0, 1}
        );
        System.out.println("本机是否可达：" + local.isReachable(5000));
        //获取该InetAddress实例对应的全限定域名
        System.out.println(local.getCanonicalHostName());
        System.out.println(local.getHostName());
    }
}
