package Internet;
/**
 * @ param     :    URLDecoder和URLEncoder用于完成普通字符串和application/x-www-form-urlencoded MIME字符串的相互转换
 * @ return    :
 * @ Description:   将application/x-www-form-urlencoded字符串转化成普通字符串
 *                  将普通字符串转换为application/x-www-form-urlencoded字符串
 * @ Date       :2020/10/2 13:26
 * @ author     :32353
*/
import java.net.URLDecoder;
import java.net.URLEncoder;

public class URLDecoderTest {
    public static void main(String[] args) throws Exception
    {
        //将application/x-www-form-urlencoded字符串转化成普通字符串
        //其中的字符串直接从浏览器窗口中复制过来
        String keyWord = URLDecoder.decode(
            "%E7%96%AF%E7%8B%82java", "utf-8"
        );
        System.out.println(keyWord);

        //将普通字符串转换为application/x-www-form-urlencoded字符串
        String urlStr = URLEncoder.encode(
                "北京交通大学","GBK"
        );
        System.out.println(urlStr);
    }
}
