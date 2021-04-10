<!--
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-08 18:08:36
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-08 18:08:38
-->

# javax.servlet

The javax.servlet package contains a number of classes and interfaces that describe and define the contracts between a servlet class and the runtime environment provided for an instance of such a class by a conforming servlet container.

这个包是在Java EE内容下的，不是Java SE的组成部分

对于一次网络通信，我们都要创建如下的两个对象：request对象和response对象。request对象中填充Servlet请求中的内容，如参数、头、cookie、查询字符串、URI等，一个request对象是javax.servlet.ServletRequest接口或javax.servlet.http.ServletRequest接口的一个实例。response对象用来向Web客户端发送响应，是javax.servlet.ServletResponse或者javax.servlet.http.ServletResponse接口的一个实例。

在网络通信中，在Servlet的service()方法中，将request对象和response对象作为参数传入，Servlet程序就可以读取请求，拆功能键并发送响应。
