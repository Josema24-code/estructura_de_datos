public class valor_Maximo {
    public static void main(String[] args){
        int [][] array = 
        {
            {9,4,2,1,8,4},
            {6,7,12,54,44,23},
            {32,56,76,34, 54,23},
            {44,78,88,56,99,22,},
            {43,65,2,1,0,3},
            {65,33,22,11,33,43},
        };
        int maximo = array[0][0];
        for (int i = 0; i < array.length; i++){
            for (int j = 0; j < array.length; j++){
                if ((array[i][j])> maximo){
                    maximo = (array[i][j]);
                }
            }
        }
        System.out.println("El numero maximo es: "+ maximo);
    }
}
