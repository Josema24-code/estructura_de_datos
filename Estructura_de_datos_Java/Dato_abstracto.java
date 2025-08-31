public class Dato_abstracto {
    // Clase Persona (tipo de dato definido por el usuario)
    static class Persona {
        String nombre;
        String apellido;
        int edad;

        // Constructor
        public Persona(String n, String a, int e) {
            nombre = n;
            apellido = a;
            edad = e;
        }
    }

    public static void main(String[] args) {
        // Crear un arreglo de 3 personas
        Persona[] personas = new Persona[3];

        // Asignar valores a cada posición del arreglo
        personas[0] = new Persona("Jose", "Aguallo", 30);
        personas[1] = new Persona("Sheila", "Valdez", 25);
        personas[2] = new Persona("Luis", "Ramírez", 40);

        // Recorrer el arreglo y mostrar los datos
        for (int i = 0; i < personas.length; i++) {
            System.out.println("Persona " + (i+1));
            System.out.println("Nombre: " + personas[i].nombre);
            System.out.println("Apellido: " + personas[i].apellido);
            System.out.println("Edad: " + personas[i].edad);
            System.out.println("--------------------");
        }
    }
}


