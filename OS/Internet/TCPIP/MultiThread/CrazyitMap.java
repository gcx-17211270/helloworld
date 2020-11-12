package Internet.TCPIP.MultiThread;

import java.util.*;

/**
 * 类的作用:        保留客户端和服务器端使用的协议字符串
 * Description:     可以考虑使用一个Map来保存聊天室所有用户和对应的Socket之间的映射关系——这样服务器就可以
 *              根据用户名来找到对应的Socket。服务器端可以根据Map获取用户名对应的输出流。
 *                  服务器端提供了一个HashMap的子类，该类不允许Value重复，并提供了根据Value获取key，根据Value
 *              删除Key的方法
 * @param
 * @return:
 * @Date:       2020/10/3 10:09
 * @author:     32353
*/
//通过组合HashMap对象来实现CrazyitMap, CrazyitMap要求value不能重复
public class CrazyitMap<K, V> {
    //创建一个线程安全的HashMap
    public Map<K, V> map = Collections.synchronizedMap(new HashMap<K, V>());
    //根据Value来删除指定项
    public synchronized void removeByValue(Object value)
    {
        for (var key : map.keySet())
        {
            if (map.get(key) == value || map.get(key).equals(value))
            {
                map.remove(key);
                break;
            }
        }
    }

    //获取所有value组成的Set集合
    public synchronized Set<V> valueSet()
    {
        Set<V> result = new HashSet<>();
        //将map中的所有value添加到result集合中
        map.forEach((key, value) -> result.add(value));
        return result;
    }

    //根据value查找key
    public synchronized K getKeyByValue(V val)
    {
        //遍历所有key
        for (var key : map.keySet())
        {
            //如果指定Key对应的value与被搜索的value相同，则返回对应的key
            if (map.get(key) == val || map.get(key).equals(val))
            {
                return key;
            }
        }
        return null;
    }

    //实现put()方法，该方法不允许value重复
    public synchronized V put (K key, V value)
    {
        //遍历所有value组成的集合
        for (var val : valueSet())
        {
            //如果某个value与试图放入集合的value相同，则抛出一个RuntimeException异常
            if (val.equals(value) && val.hashCode() == value.hashCode())
            {
                throw new RuntimeException("CrazyitMap实例中不允许出现重复value!");
            }
        }
        return map.put(key, value);
    }
}
