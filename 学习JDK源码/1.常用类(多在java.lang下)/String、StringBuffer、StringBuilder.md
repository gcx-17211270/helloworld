# String、StringBuffer、StringBuilder类

- String是一个不可变类，自从一个String对象创建后，包含在这个对象中的字符序列是不可改变的，直到这个对象被销毁。（所以我们一直使用的"str1"+"str2"其实一直是错的？在这个过程中发生了隐式类型变换？）

- StringBuffer对象则代表一个字符序列可变的字符串，当一个StringBuffer对象被创建后，通过append(),insert(),reverse(),setLength()等方法可以改变这个字符串对象的字符序列。生成完毕之后就可以使用它的toString()方法来转换成String对象。

- StringBuilder类是jdk1.5新增的类，它也代表可变字符串对象，与StringBuffer基本相似但是构造相似实际上，StringBuilder是线程不安全的，而StringBuffer是线程安全的，所以StringBuilder的性能略高。
