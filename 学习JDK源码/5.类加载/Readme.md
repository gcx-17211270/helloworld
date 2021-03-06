<!--
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-19 16:38:43
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-21 10:31:53
-->

# 类加载机制与反射

Module java.base
Package java.lang.reflect
Provides classes and interfaces for obtaining reflective information about classes and objects. Reflection allows programmatic access to information about the fields, methods and constructors of loaded classes, and the use of reflected fields, methods, and constructors to operate on their underlying counterparts, within encapsulation and security restrictions.
AccessibleObject allows suppression of access checks if the necessary ReflectPermission is available.

Array provides static methods to dynamically create and access arrays.

Classes in this package, along with java.lang.Class accommodate applications such as debuggers, interpreters, object inspectors, class browsers, and services such as Object Serialization and JavaBeans that need access to either the public members of a target object (based on its runtime class) or the members declared by a given class.

Since:
1.1

类加载：加载(ClassLoader)、连接、初始化，在刷面试题的时候，关于类静态初始化块（类初始化执行，只执行一次）、实例初始化块（在对象创建时候执行）相关的顺序是常考的内容。

初始化一个类包括以下步骤：1)假如这个类还没有被加载和连接，则程序先加载并连接这个类；2)假如该类的直接父类还没有被初始化则先初始化这些类(递归进行)；3)假如类中有初始化语句，则系统依次执行这些初始化语句。

类加载的来源：1.从本地文件系统来加载class文件；2.从JAR包中加载class文件；3.从网络加载class文件；4.把一个Java源文件动态编译，并执行加载。

类初始化的时机：1.创建类的实例。(包括使用new、反射、反序列化创造的类的实例).2.调用某个类方法(静态方法) 3.访问某个类或接口的类变量，或为该类变量赋值。3.使用反射方式创建某个类或接口的java.lang.Class对象。5.初始化某个类的子类。6.直接使用java.exe来运行某个主类，运行的时候程序会先初始化该主类。

## 类加载器

类加载器负责将.class文件加载到内存中，并为止生成对应的java.lang.class对象。一个载入JVM中的类由全限定名（包括包名和类名）和其类加载器作为唯一标识。可以通过继承ClassLoader类来编写自己的类加载器。
