<!--
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-15 17:35:15
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-16 14:51:06
-->

# Object、Objects类

## Object

Object类是所有类、数组、枚举类的父类，也就是说，Java允许把任何类型的对象赋给Object类型的变量。当一个类没有显式指定extends类时，它默认继承自Object父类。Object类有registerNatives()、getClass()、hashcode()、equals()、clone()、toString()、notify()、notifyAll()、wait()、finalize()这些方法，finalize()方法在java 9之后被废弃。

Class<?> getClass()获得该对象的运行时类，finalize()垃圾回收器调用此方法来清理对象资源，其余常用的方法不过多介绍。其中clone()方法是一种十分高效的复制方法，但同时它对于引用类型只有克隆引用不会克隆对象，指向的还是同一个对象，因而如果需要对对象进行克隆，就需要开发者改变策略。

## Objects

Objects类不是Java的lang包下的默认存在的类，使用时需要手动导入位于java.uitl.Objects类，这个类与Objects的区别在于，这是操作对象的工具类，并且它对于对象为空时提供了判断，并可以抛出空指针异常。

其中比较常见的类如requieNonNull()用于要求对象不为空，compar()可以定义两个对象比较时的策略，等等。
