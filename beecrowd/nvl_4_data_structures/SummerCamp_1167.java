import java.util.Scanner;

class Children{
    public String name;
    public int card;
    public int prev, next;

    public Children(String name, int card){
        this.name = name;
        this.card = card;
        prev = next = 0;
    }
    public Children(String name, int card, int index, int total){
        this.name = name;
        this.card = card;
        int N = total;
        this.prev = ((index - 1) % N + N) % N;
        this.next = (index + 1) % N;
    }
}
public class SummerCamp_1167 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); sc.nextLine();
        while(N != 0)
        {
            Children[] circle = new Children[N];
            for(int i = 0; i < N; i++){
                String input = sc.nextLine();
                String[] split = input.split(" ");

                circle[i] = new Children(split[0], Integer.parseInt(split[1]), i, N);
            }

            int i = 0;
            for(int C = 0; C < N-1; C++)
            {
                int card = circle[i].card;

                if(card % 2 == 0){
                    for(int j = 0; j < card; j++){ i = circle[i].next; }
                }else{
                    for(int j = 0; j < card; j++){ i = circle[i].prev; }
                }
                circle[circle[i].next].prev = circle[i].prev;
                circle[circle[i].prev].next = circle[i].next;
            }
            i = circle[i].next;
            System.out.println("Vencedor (a) : " + circle[i].name);

            N = sc.nextInt(); sc.nextLine();
        }

        sc.close();
    }
}