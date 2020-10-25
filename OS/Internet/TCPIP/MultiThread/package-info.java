package Internet.TCPIP.MultiThread;

/**
 * 类的作用:        一个命令行界面的C/S聊天室应用
 * Description:     服务器端应该包含多个线程，每个Socket对应一个线程，该线程负责读取Socket对应输出流发送一次
 *              （将一个客户端发送的数据），并将读到的数据向每个Socket输出流发送一次（将一个客户端发送的数据
 *              广播给其他客户端），因此要在服务器端使用List来保存所有的Socket.
 * @param
 * @return:
 * @Date:       2020/10/2 23:13
 * @author:     32353
*/
