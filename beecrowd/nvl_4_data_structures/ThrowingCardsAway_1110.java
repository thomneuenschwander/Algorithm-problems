import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ThrowingCardsAway_1110{

    public static void throwCardsAway(List<Integer> deck){

        List<Integer> thrown = new ArrayList<>();

        while(deck.size() > 1)
        {
            int top = deck.size()-1;

            int toThrowAway = deck.remove(top);
            int toMove = deck.remove(top-1);

            thrown.add(toThrowAway);
            deck.add(0, toMove);
        }

        System.out.print("Discarded cards: ");
        for(int card : thrown){
            System.out.print(card+", ");
        }
        System.out.println("\nRemaining card: "+deck.get(0));
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        while(n != 0)
        {
            List<Integer> deck = new ArrayList<>();
            for(int i = n; i >= 1; deck.add(i), i--);

            throwCardsAway(deck);
            
            n = sc.nextInt();
        }


        sc.close();
    }
}