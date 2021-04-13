/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-12 09:04:30
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-12 09:04:32
 */

class LFUCache {
    private int capacity;
    private int length = 0;
    private LFU[] lfuArray = null;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        if (capacity != 0) {
            lfuArray = new LFU[capacity];
            for (int i = 0; i < capacity; i++) {
                lfuArray[i] = new LFU();
            }
        }
    }
    
    public int get(int key) {
        if (lfuArray != null) {
            for (int i = 0; i < length; i++) {
                if (lfuArray[i].key == key) {
                    lfuArray[i].cnt++;
                    lfuArray[i].time = 0;
                    update(i);
                    return lfuArray[i].value;
                }
            }
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if (lfuArray != null) {
            int i = contains(key);
            if (i != -1) {
                lfuArray[i].value = value;
                lfuArray[i].cnt++;
            }
            else {
                if (length < capacity) {
                    insert(length++, key, value);
                }
                else {
                    //根据cnt与time，进行替换
                    i = lfu();
                    insert(i, key, value);
                }
            }
        }
    }

    private int contains(int key) {
        for (int i = 0; i < length; i++) {
            if (lfuArray[i].key == key) {
                return i;
            }
        }
        return -1;
    }

    private int lfu() {
        int num = 0, cnt = lfuArray[0].cnt, time = lfuArray[0].time;
        for (int i = 1; i < length; i++) {
            if (cnt > lfuArray[i].cnt || (cnt == lfuArray[i].cnt && time < lfuArray[i].time)) {
                num = i;
                cnt = lfuArray[i].cnt;
                time = lfuArray[i].time;
            }
        }
        return num;
    }

    private void insert(int location, int key, int value) {
        lfuArray[location].key = key;
        lfuArray[location].value = value;
        lfuArray[location].cnt = 1;
        lfuArray[location].time = 0;
        update(location);
    }

    private void update(int location) {
        // System.out.println("UPDATE " + location + " " + length);
        for (int i = 0; i < length; i++) {
            if (i == location) {
                // System.out.println(lfuArray[i].toString());
                continue;
            }
            else {
                lfuArray[i].time++;
            }
            // System.out.println(lfuArray[i].toString());
        }
    }
}
class LFU {
    public int key;
    public int value;
    public int cnt;
    public int time;
    public String toString() {
        return key + " " + value + " " + cnt + " " + time;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */