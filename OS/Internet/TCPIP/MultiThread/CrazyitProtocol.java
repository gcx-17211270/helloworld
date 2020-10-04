package Internet.TCPIP.MultiThread;
/**
 * 作用:            客户端发送来信息的特殊标识
 * Description:     让服务器端可以判断是公聊信息，还是私聊信息
 *                  为了解决这个问题，可以让客户端在发送不同的信息之前，先对这些信息进行适当处理，比如在
 *              内容前后添加一些特殊字符——这些字符被称为协议字符，本例提供了一个CrazyitProtocol接口，该
 *              接口用来定义协议字符。
 * @param
 * @return:
 * @Date:       2020/10/3 0:39
 * @author:     32353
 */
public interface CrazyitProtocol {
    //定义协议字符串的长度
    int PROTOCOL_LEN = 2;
    //下面是一些协议字符串，服务器端和客户端交换的信息都应该在前、后添加这种特殊字符串
    String MSG_ROUND = "✍γ";
    String USER_ROUND = "ΣΠ";
    String LOGIN_SUCCESS = "1";
    String NAME_REP = "-1";
    String PRIVATE_ROUND = "⭐【";
    String SPLIT_SIGN = "※";
}
