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
