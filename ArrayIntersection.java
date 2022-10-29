import java.util.Scanner;

class ArrayIntersection{

    public static int[] input()
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int x=0 ; x<a.length ; x++)
        {
            a[x] = sc.nextInt();
        }
        return a;
    }
    public static void print(int[] a)
    {
        for(int x=0 ; x<a.length ; x++)
        {
            System.out.print(a[x]+" ");
        }
        
    }
    
   public static void printIntersection(int[] a, int b[])
   {
        for(int x=0 ; x<a.length ; x++)
        {
            
            for(int y=0 ; y<b.length ; y++)
            {
                if(a[x]==b[y])
                {
                System.out.print(a[x]+" ");
                b[y]=0;
                }
            }
        }
        System.out.println();

   }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int x=1 ; x<=t ; x++)
        {
            int a[] = input();
            int b[] = input();
            printIntersection(a,b);
          
            
        }
    }
}

