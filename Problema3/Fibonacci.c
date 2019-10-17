#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

	/**
	* Assumindo que o primeiro termo sempre será o menor
	* sequencia fibonaccica e o menor da sequencia geral
	*/
void find_minor_number(int* p, int tam)
{
	int aux;
	
	for (int i = 0; i < tam; ++i)
	{
		if (p[0]>p[i])
		{
			aux=p[0];
			p[0]=p[i];
			p[i]=aux;
		}
	}
}

	/**
	* Assumindo a arbitrariedade dos dois primeiros termos
	* assumi a lógica dos dois primeiros termos terem a menor
	* diferença possível.
	*/
void set_second_term_by_minimun_diference(int* p, int tam)
{
	int aux;
	
	aux= p[1]-p[0];
	for (int i = 1; i < tam; ++i)
	{
		if (aux>(p[i]-p[0]))
		{
			aux=p[1];
			p[1]=p[i];
			p[i]=aux;
		}
	}
}

void print_all(int *p, int tam)
{
	for (int i = 0; i < tam; ++i)
	{
		printf("%d", p[i]);
	} printf("\n");
}

int order_like_fibonacci(int* p, int tam)
{
	int aux;
	int a=0;
	int counter=2;
	int c,d;
	
	printf("%d \n",a);
	/**
	* Aqui neste for temos a lógica de fibonacci aplicada como condição.
	* caso ele ache um termo da sequencia, ele troca troca para a posição
	* que ele pertence e então acerta reseta a contagem no ultimo termo.
	*/

	for (int i = 2; i < tam; ++i)
	{
		c=p[a];
		d=p[a+1];
		aux=c+d;
		printf("%d \t %d \n",c,d);
		if (aux==p[i])
		{
			printf("passou por aqui\n");
			a++;
			aux=p[a];
			p[a]=p[i];
			p[i]=aux;
			i=a+1;
			counter++;
		}
	}
	return counter;
}



int main(int argc, char const *argv[])
{
 int *f;
 int tam;
 int result=0;

 /**
 * primeiro'lê-se o tamanho e em seguida a sequência. 
 *
 * Em seguida se aloca memória para isso.
 * Prefiro utilizar alocação dinâmica pois facilita a
 * dinamicidade do algoritmo.
 *
 * como não se fala onde está vindo as lista, irei colo-
 * car um método de entrada tipo scanf(int)
 *
 */

 /**
 *métodos de input
 */
 scanf("%d", &tam);
 fflush(stdin);

 	f= (int*)malloc(tam*sizeof(int));

for (int i = 0; i < tam; ++i)
 {
 	scanf("%d", &f[i]);
 	fflush(stdin);
  }

/**
*Essa primeira funcção setta o primeiro termo da sequencia fibonaccica
*
*
*/	print_all(f,tam);
 	find_minor_number(f,tam);
 	print_all(f,tam);
 	set_second_term_by_minimun_diference(f,tam);
    print_all(f,tam);
 	result = order_like_fibonacci(f,tam);
 	print_all(f,tam);
 	printf("%d \n", result);








	
	return 0;
}