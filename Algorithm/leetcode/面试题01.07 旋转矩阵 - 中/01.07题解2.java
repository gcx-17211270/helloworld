Class Solution{
    public void rotate(int[][] matrix) {
        int topX = 0,topY = 0;
        int buttomX = matrix.length-1,buttomY = matrix[0].length-1;
        //从对角的两个点开始
        while(topX < buttomX){//如果没有在对角线相遇
             //循环调换
            for(int i = 0;i<buttomX-topX;i++){
                int temp = matrix[topX][topY+i];
                matrix[topX][topY+i] = matrix[buttomX-i][topY];
                matrix[buttomX-i][topY] = matrix[buttomX][buttomY-i];
                matrix[buttomX][buttomY-i] = matrix[topX+i][buttomY];
                matrix[topX+i][buttomY] = temp;
            }
            //进入下个内环
            topX++;
            topY++;
            buttomX--;
            buttomY--;
        }
    }
}