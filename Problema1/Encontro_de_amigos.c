#include <stdio.h>
#include <stdlib.h>

	

/**
* Agora temos a subrotina principal
* Optei por fazer por recursão, isso minimiza o uso de estruturas
* rígidas de 
*
*/
int* minimo_cansaco(int *p)
{
	/**
	* Retorna se estiverem na mesma posição.
	*/	
  if (p[0]==p[1])
  {
  	return p;
  }


	/**
	* Verifica através da cansaço qual é a vez de quem andar
	* no caso se quem anda primeiro é sempre a pessoa 1;
	*/
  if (p[2]==p[3])
  {
  	/**
	* Pessoa 1 anda para direita ou esquerda em busca da 2.
	*/	
  	if (p[0]>p[1])
  	{
  		p[0]--;
  		p[2]++;
  		p[4]=p[4]+p[2];
  		p=minimo_cansaco(p);
  	}
  	else if (p[0]<p[1])
  	{
  		p[0]++;
  		p[2]++;
  		p[4]=p[4]+p[2];
  		p=minimo_cansaco(p);
  	}
  }
  else
  {
  	/**
	* Pessoa 2 anda para direita ou esquerda em busca da 1.
	*/

  	if (p[0]>p[1])
  	{
  		p[1]++;
  		p[3]++;
  		p[4]=p[4]+p[3];
  		p=minimo_cansaco(p);
  	}
  	else if (p[0]<p[1])
  	{
  		p[1]--;
  		p[3]++;
  		p[4]=p[4]+p[3];
  		p=minimo_cansaco(p);
  	}
  }	

  return p;
}








int main(int argc, char const *argv[])
{
	/**
	* Esse vetor trabalha com todos os dados, sendo a posição de
	* cada pessoa como também seu cansaço.
	* Optei por esse método ao invés de uma struct pela facilidade
	* e simplicidade do tema, contudo facilmente o código pode ser
	* convertido para uma struct.
	* Ficam as casas do vetor definidas:
	* -[0]: posição da primeira pessoa
	* -[1]: posição da segunda pessoa
	* -[2]: cansaço da primeira pessoa
	* -[3]: cansaço da segunda pessoa
	* -[4]: cansaço total
	*
	*	Obs: poderia ter sido feito um algorítmo com apenas duas casas
	* dada a lógica, pensando apenas na distância entre ambos e no cansaço
	* somado. Contudo preferi optar por manter cada dado separado para que
	* fosse possível acessar a posição e a posição individual de cada um a
	* qualquer momento.
	*/
	int data[5];
	/**
	*Setando os cansaços para 0 por garantia
	*/
	data[4]=0;
	data[3]=0;
	data[2]=0;
	/** 
	* Entradas das posições pelo usuário através do teclado.
	*/
	scanf("%d", &data[0]);
	fflush(stdin);
	scanf("%d", &data[1]);
	fflush(stdin);

	/**
	* Função do mínimo cansaço.
	*/
	minimo_cansaco(data);
	printf("%d \n", data[4]);


	system("PAUSE");





	return 0;
}