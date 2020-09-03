 #include <iostream>
 using namespace std;

 //Aluno: Arilson Martins dos santos
 // uttilizado o algoritimo de ordena��o MergeSort , que e um tipo de algoritimo de divis�o e conquista

 void imprime(int * X, int tam ,string a){
     // fun��o a qual ira percorrer e imprimir os valores do vetor
     cout<<a<<"  ";
      for (int i = 0; i < tam; ++i)
      {
           cout << " ["<< X[i] << "] ";
      }
      cout <<endl;
      cout <<endl;
      cout <<endl;
 }
 void intercala(int X[], int inicio, int fim, int meio){
      int posLivre,inicio_vetor1, inicio_vetor2, i;
      int aux[15];
      inicio_vetor1 = inicio;
      inicio_vetor2 = meio+1;
      posLivre = inicio;
      while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){
           if (X[inicio_vetor1] <= X[inicio_vetor2])
           {
                aux[posLivre] = X[inicio_vetor1];
                inicio_vetor1++;
           }
           else{
                aux[posLivre] = X[inicio_vetor2];
                inicio_vetor2++;
           }
           posLivre++;
      }

      for (int i = inicio_vetor1; i <= meio; ++i)
      {
           aux[posLivre] = X[i];
           posLivre++;
      }

      for (int i = inicio_vetor2; i <= fim; ++i)
      {
           aux[posLivre] = X[i];
           posLivre++;
      }
      for (int i = inicio; i <=fim; ++i)
      {
           X[i] = aux[i];
      }
 }
 void merge (int X[], int inicio, int fim){
         // fun��o recursiva
      int meio;
        if (inicio < fim)
      {
           meio = (inicio+fim)/2;
           merge (X,inicio, meio);
           merge (X,meio+1, fim);
           //chama a fun��o intercalar no qual ira ordenar cada parte do vetor que foi dividido
           intercala(X,inicio, fim, meio);

      }
 }
 int main()
 {
      int X [] = {9 , 10 , -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};
      // decalra��o do vetor

      // procedimento pra imprimir o vetor desordenado
    imprime(X,15,"Vetor desordenado");

      merge (X, 0 ,14);
      // chama a fun��o merge
      // passa o vetor , o �ndice  de inicio e o �ndice  de fim

        //imprimir o vetor ordenado
     imprime(X,15,"Vetor ordenado   ");


      return 0;
 }
