//Mauricio Salazar Cervantes
/*Programa que ordena un vector de enteros usando el m?todo heap*/
/*Algoritmo extra?do del libro Estructuras de Datos de Cair?-Guardati*/
/*Este programa fue creado usando el IDE de Borland Turbo C++ 3.0 para DOS*/

#include <conio.h>
#include <stdio.h>

/*Las siguientes funciones son el coraz?n del programa. La primera inserta
los elementos de un array de tal modo que queden como un mont?culo. La
segunda elimina sucesivamente la ra?z del mont?culo, que ser? el elemento
m?s pesado*/
void insertamonticulo(int *, int N);
void eliminamonticulo(int *, int N);

void main()
{
	clrscr();
	int *array; /*Un vector din?mico*/
	int N;
	printf("Introduce el n?mero de datos enteros a ordenar: ");
	scanf("%d",&N);
	array = new int[N+1]; /*El N+1 es por comodidad. Con eso de que en C++
	todos los arreglos empiezan desde 0 y el heapsort presupone que em-
	piezan desde 1, pues ignoro el elemento 0 del array y le aumento un
	elemento para dar cabida a un ?ndice igual al n?mero de elementos*/
	int i;
	array[0]=-1; /*Una l?nea que puede omitirse. Se?alo con una banderita
	al elemento "apestado"*/

	/*El siguiente ciclo pide al usuario los n?meros de 1 a N*/
	for(i=1;i<=N;i++)
	{
		cout<<"Introduce el valor "<<i<<": ";
		cin>>array[i];
	}

	/*Imprimo los n?meros en el orden que dio el usuario*/
	printf("\nAntes de la funcion:\n");
	for(i=1;i<=N;i++)
	{
		cout<<array[i]<<"\n";
	}
	getch();

	/*A continuaci?n llamo a la funci?n que acomoda los n?meros de tal
	manera que se respeten las condiciones de un mont?culo lineal*/
	insertamonticulo(array, N);

	/*Imprimo el resultado que se manifest? en el vector luego de llamar a
	la funci?n anterior.*/
	printf("\nDespues de la funcion que inserta en el monticulo:\n");
	for(i=1;i<=N;i++)
	{
		cout<<array[i]<<"\n";
	}
	getch();

	/*Y finalmente, se acomodan los n?meros luego de quit?rseles sucesivamente la raiz del
	mont?culo*/
	eliminamonticulo(array, N);

	printf("\nDespues de la funci?n que elimina el monticulo:\n");
	for(i=1;i<=N;i++)
	{
		cout<<array[i]<<"\n";
	}
	getch();
}

void insertamonticulo(int *A, int N)
{
 /*Esta funci?n inserta los elementos en un mont?culo representado como
 arreglo.*/
 int i, k, aux, band; /*?sta ?ltima variable es una bandera que se considera
 de tipo booleano*/
 for (i=2; i<=N; i++)
 {
  k=i;
  band=1; /*1 se considera como verdadero*/
  while (k>1 && band==1)
  {
   band=0;
   if (A[k]>A[k/2])
   {
    aux=A[k/2];
    A[k/2]=A[k];
    A[k]=aux;
    k=k/2; /*El propio lenguaje se encarga de adaptar la parte entera de este
    tipo de divisiones entre enteros*/
    band=1;
   }
  }
 }
}

void eliminamonticulo(int *A, int N)
{
 /*Esta funci?n elimina la ra?z del mont?culo en forma repetida.*/
 int i, aux, izq, der, k, ap, bool, mayor;
 for (i=N; i>1; i--)
 {
  aux=A[i];
  A[i]=A[1];
  izq=2;
  der=3;
  k=1;
  bool=1; /*bool es 1, o sea verdadero*/
  while (izq<i && bool==1)
  {
   mayor=A[izq];
   ap=izq;
   if (mayor<A[der] && der!=i)
   {
    mayor=A[der];
    ap=der;
   }
   if (aux<mayor)
   {
    A[k]=A[ap];
    k=ap;
   }
   else
    bool=0;
   izq=k*2;
   der=izq+1;
  }
  A[k]=aux;
 }
}

