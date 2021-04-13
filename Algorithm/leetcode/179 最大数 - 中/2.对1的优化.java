/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-12 11:09:31
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-12 11:09:32
 */
class Solution {
    public String largestNumber(int[] nums) {
        double[] order = new double[nums.length];
        Map<Node, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            order[i] = nums[i];
            int j = 0;
            while (order[i] >= 1) {
                j++;
                order[i] = order[i] * 1.0 / 10;
            }
            map.put(new Node(order[i], j) , i);
        }
        StringBuffer str = new StringBuffer("");
        while (map != null) {
            Node key = getMax(map);
            if (key.value != Double.MIN_VALUE){
                System.out.println(key + " " + map.get(key));
                str.append(nums[map.get(key)]);
                map.remove(key, map.get(key));
            }
            else {
                break;
            }
        }
        return str.toString();
    }

    private Node getMax(Map<Node, Integer> map) {
        Node node = new Node(Double.MIN_VALUE, 0);
        for (Node key : map.keySet()) {
            if (key.value > node.value ||(key.value == node.value && key.carry < node.carry)) {
                node = key;
            }
        }
        return node;
    }
}

class Node {
    double value;
    int carry;
    public Node(double value, int carry) {
        this.value = value;
        this.carry = carry;
    }
    public String toString() {
        return value + " " + carry;
    }
}