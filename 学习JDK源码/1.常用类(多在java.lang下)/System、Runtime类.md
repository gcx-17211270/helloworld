<!--
 * @Descripttion: 对这两个类的学习
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-15 17:35:00
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-16 14:38:23
-->

# System类与Runtime类

## System

System类代表当前Java程序运行的平台，由于隐藏了构造器，程序不能创建System类的对象，但定义了一些静态的类变量与类方法可以直接访问。类中最重要的是定义了三个标准输入，标准输出以及错误输出的常量，定义形式如下

```Java
public static final InputStream in = null;
public static final PrintStream out = null;
public static final PrintStream err = null;
```

他们是已经打开并且能够完成对应的输入输出功能的标准输入流、标准输出流、标准错误流。

另一类静态方法是与当前系统相关的属性，以getProperties()、getenv()方法为代表，getProperties()将会返回Properties类型的变量，返回所有当前系统属性。而getenv()会返回Map<String, String>，以键值对形式返回所有的环境变量。

System类中的gc()方法通知系统进行垃圾回收。runFinalization()方法通知系统进行资源清理。exit(int status)方法退出。load()加载文件。loadLibrary()方法加载动态链接库文件。

另外两个常用的方法是currentTimeMillis()和nanoTime()他们都返回一个long型整数，表示当前时间与UTC1970年1月1日的时间差，前者以毫秒为单位，后者以纳秒为单位，但这两个返回的时间粒度都取决于底层操作系统，或许根本不支持毫秒、纳秒计时单位。

indentityHashCode(Object x)返回该对象的精确hashCode()值，可以作为对象的唯一标识，因为这个值是根据对象的地址计算得到的。

## Runtime

Runtime类代表Java程序运行时环境，每个Java程序都有一个与之相对应的Runtime实例，应用程序通过该对象与其运行时环境相连。Runtime类同样隐藏了构造器，不允许创造实例，但可以通过getRuntime()方法获得与之相关的Runtime()对象。

可以在System类中看到，在gc()、runFinalization()、exit(int status)、load()、loadLibrary()方法中，System类是使用了Runtime类下同名的方法，因而这几个方法的功能与之前相同。

通过获取Runtime对象，我们可以得到JVM的相关信息，例如在Runtime类下的availableProcessors()返回可用的处理器数量，freeMemory()返回空闲内存数，totalMemory()返回总内存数，maxMemory()返回可用的最大内存数。

exec()系列的方法返回一个进程，通过指定地址信息，可以直接运行该地址的程序。对于返回的进程，我们可以通过它的toHandle()方法来获得ProcessHandle接口，来获得进程ID、父进程、子进程，并且通过ProcessHandle.Info类来获取进程的命令、参数、启动时间、累计运行时间、用户等信息。
