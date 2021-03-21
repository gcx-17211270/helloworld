<!--
 * @Descripttion: 文件夹基本信息
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-16 10:19:28
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-19 16:31:12
-->

# Java® Platform, Standard Edition & Java Development Kit. Version 11 API Specification

Java®平台，标准版(Java SE)和Java开发套件(jdk)。版本11 API规范。

Module java.base
Package java.lang

- Provides classes that are fundamental to the design of the Java programming language. The most important classes are Object, which is the root of the class hierarchy, and Class, instances of which represent classes at run time.

- Frequently it is necessary to represent a value of primitive type as if it were an object. The wrapper classes Boolean, Character, Integer, Long, Float, and Double serve this purpose. An object of type Double, for example, contains a field whose type is double, representing that value in such a way that a reference to it can be stored in a variable of reference type. These classes also provide a number of methods for converting among primitive values, as well as supporting such standard methods as equals and hashCode. The Void class is a non-instantiable class that holds a reference to a Class object representing the type void.

- The class Math provides commonly used mathematical functions such as sine, cosine, and square root. 

- The classes String, StringBuffer, and StringBuilder similarly provide commonly used operations on character strings.

- Classes ClassLoader, Process, ProcessBuilder, Runtime, SecurityManager, and System provide "system operations" that manage the dynamic loading of classes, creation of external processes, host environment inquiries such as the time of day, and enforcement of security policies.

- Class Throwable encompasses objects that may be thrown by the throw statement. Subclasses of Throwable represent errors and exceptions.

- Character Encodings The specification of the java.nio.charset.Charset class describes the naming conventions for character encodings as well as the set of standard encodings that must be supported by every implementation of the Java platform.

以上的描述来自于官方文档，在上面的描述中介绍了java.lang包中的一些基本类，比如基础的Object类，基本类型的包装类Boolean，Character, Integer, Long, Float, Double，包含数学运算的Math类，字符操作的String, StringBuffer, StringBuilder类，运行时类ClassLoader, Process, ProcessBuilder, Runtime, SecrityManager, System类，包含各类抛出异常的Throwable类，以及对字符编码的类。java.lang包是java世界的基础，在最近的学习中，我将从一些常用类的定义、API入手，对文档中涉及的源码进行学习。

在这个篇章中，我们主要学习了基础的Object类的各类方法、System类、Runtime类下获得操作系统与运行时环境的一些方法，对String相关的三个类进行了解，并且最后了解了位于java.util.regex与正则表达式有关的两个类，将他们放到这儿是因为正则表达式常用并且在String类中也提供了关于支持正则表达式的方法。
