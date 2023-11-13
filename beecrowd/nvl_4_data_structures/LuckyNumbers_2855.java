import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class LuckyNumbers_2855 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); sc.nextLine();
        String entrada = sc.nextLine();
        String[] split = entrada.split(" ");
        if(N != split.length) { System.out.println("Entrada invalida"); }

        List<Integer> lista = new ArrayList<>();
        for(String s : split){
            lista.add(Integer.parseInt(s));
        }
        int luckyNumber = sc.nextInt();
        boolean isLuckyNumber = false;
        int k = 2;
        while (lista.contains(luckyNumber)) {
            
            // remover de k e k
            for(int i = k-1; i < lista.size(); i += k-1){
                lista.remove(i);
            }
            
            if(lista.contains(luckyNumber) && lista.indexOf(luckyNumber) < k-1){
                System.out.println("breikou");
                isLuckyNumber = true;
                break;
            }

            k++;
        }
        if(isLuckyNumber){
            System.out.println("Y");
        }else{
            System.out.println("N");
        }

        sc.close();
    }
}