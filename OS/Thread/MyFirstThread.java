public class MyFirstThread extends Thread{
    private int i;
    public void run()
    {
        for (  ; i < 100; i++)
		{
            System.out.print(getName() + " " + i + "\t");
			if (i % 5 == 0)
				System.out.println();
		}
    }
    public static void main(String[] args)
    {
       for(var i =0; i < 100; i++)
       {
           System.out.println(Thread.currentThread().getName() + " " + i);
           if (i == 20)
           {
               new MyFirstThread().start();
               new MyFirstThread().start();
           }
       }
    }
}