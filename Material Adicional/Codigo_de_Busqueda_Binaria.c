#include<stdio.h>

int main() { 
	int A[20]={21,32,43,54,65,76,87,98,109,110,211,212,313,314,415,416,417,518,519,620}; 
	int inf,sup,mit,dato,n=20, cont = 0; 
	printf("Ingrese el dato a buscar: "); 
	scanf("%d",&dato); 
	inf=0; 
	sup=n;
	
	while ((inf <= sup) && (cont < n)) { 
		mit = (inf + sup)/2; 
		if (A[mit] == dato) { 
		printf("Dato %d encontrado posicion %d \n",dato,mit); 
		break; 
		} 
		if (A[mit] > dato) { 
			sup = mit; 
			mit = (inf + sup)/2; 
		} 
		if (A[mit] < dato) { 
			inf = mit; 
			mit = (inf + sup)/2; 
		}
		cont = cont + 1;
	}
	if (cont == n) {
		printf ("Dato no encontrado.\n");
	}
	return 0; 
} 
