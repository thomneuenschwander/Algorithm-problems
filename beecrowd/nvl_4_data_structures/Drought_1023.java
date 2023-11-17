import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Residency {
    private int population;
    private int consumption;

    public Residency(int population, int consumption) {
        this.population = population;
        this.consumption = consumption;
    }

    public int getPopulation() {
        return population;
    }

    public void setPopulation(int population) {
        this.population = population;
    }

    public int getConsumption() {
        return consumption;
    }

    public void setConsumption(int consumption) {
        this.consumption = consumption;
    }

 // ---------------- CONSUMPTION PER PERSON -----------------------------
    public int consumptionPerPerson(){
        return consumption/population;
    }
}

class City {
    private Residency[] residences;

    public City(Residency[] residences){
        this.residences = residences;
    }

    public Residency[] getResidences() {
        return residences;
    }

    public void setResidences(Residency[] residences) {
        this.residences = residences;
    }

  // -------------------- AVERAGE CONSUMPTION -------------------------
    public Double averageConsumption() {
        int numPeople = 0;
        int consumption = 0;
        for(Residency res : residences){
            numPeople += res.getPopulation();
            consumption += res.getConsumption();
        }
        return (double) consumption/numPeople;
    }

  // -------------------- SORT IN ASCENDING ORDER OF CONSUMPTION ----------------
    private void insertionSort() {
        int tam = residences.length;
        for(int i = 1; i < tam; i++){
            Residency piv = residences[i];
            int j = i-1;
            while((j >= 0) && piv.consumptionPerPerson() < residences[j].consumptionPerPerson()){
                residences[j+1] = residences[j];
                j--;
            }
            residences[j+1] = piv;
        }
    }

  // -------------------- LIST CONSUMPTION SORTED -------------------------
    public void showConsumption(){
        insertionSort();
        for(Residency res : residences){
            System.out.print(res.getPopulation()+"-"+res.consumptionPerPerson()+" ");
        }
        System.out.println();
    }
    
}


class Drought_1023 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<City> cities = new ArrayList<>();

        int n = sc.nextInt();
        while (n != 0) 
        {
            Residency[] residences = new Residency[n];

            for(int i = 0; i < n; i++) {
                residences[i] = new Residency(sc.nextInt(), sc.nextInt());
            }

            cities.add(new City(residences));

            n = sc.nextInt();
        }

        int cityNumber = 1;
        for(City city: cities){
            System.out.println("Cidade# "+cityNumber+":");
            city.showConsumption();
            System.out.println("Consumo medio: "+ city.averageConsumption()+" m3.");
        }

        sc.close();
    }
}