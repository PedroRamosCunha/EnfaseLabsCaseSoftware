#include <stdio.h>
#include <stdlib.h>



typedef struct
{
	char casas[3][3];
}tabuleiro;

void input_jogo_anterior(tabuleiro *p)
{
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j <3 ; ++j)
		{
			scanf("%c", &((p->casas)[i][j]));
			fflush(stdin);
		}
	}
	return;
}
/**
* Essa função recebe o tabuleiro
*
*
*/
void print_tabuleiro(tabuleiro *p)
{
	char a;
	system("cls");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			a=(p->casas)[i][j];
			printf("%c", a);
		}
	printf("\n");
	}
	return;
}

/**
* Essa função diz quem é o próximo se houver um.
*
*
*/

void newMovment(tabuleiro *p)
{
	unsigned countX=0;
	unsigned count0=0;
	int auxx=0;
	int auxy=0;
	int flag=1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((p->casas[i][j])=='X')
			{
				countX++;
			}
			if ((p->casas[i][j])=='0')
			{
				count0++;
			}
		}
	}
	if (countX>count0)
	{	
		while(flag)
		{
			printf("Segundo\n");
			/*scanf("%d", &auxx );
			fflush(stdin);
			scanf("%d", &auxy );
			fflush(stdin);
			if ((((p->casas[auxx-1][auxy-1])=='X')||((p->casas[auxx-1][auxy-1])=='0'))&&(((auxx-1)<3)&&((auxy-1)<3)))
			{
				printf("Casa já ocupada, tente novamente\n");
			}
			else
			{
				flag=0;
				p->casas[auxx-1][auxy-1]='X';
			}*/ flag=0;
		}
	}
	else
	{	
		while(flag)
		{
			printf("Primeirp\n");/*
			scanf("%d", &auxx );
			fflush(stdin);
			scanf("%d", &auxy );
			fflush(stdin);
			if ((((p->casas[auxx-1][auxy-1])=='X')||((p->casas[auxx-1][auxy-1])=='0'))&&(((auxx-1)<3)&&((auxy-1)<3)))
			{
				printf("Casa já ocupada, tente novamente\n");
			}
			else
			{
				flag=0;
				p->casas[auxx-1][auxy-1]='0';
			}*/ flag=0;
		}
	}
}

/**
* Essa função checa checa se há vencedor, perdedor ou empate
*
*
*/

int check_for_winner(tabuleiro *p)
{
	int aux_win[8][2];
	int aux[2];
	aux[0]=0;
	aux[1]=0;
	for (int i = 0; i < 7; ++i)
		{
			aux_win[i][0]=0;
			aux_win[i][1]=0;
		}	

	for (int l = 0; l < 3; ++l)
	{
		for (int m = 0; m < 3; ++m)
		{
			//Conferindo o número de casas por coluna, linha e diagonal de X
			if ((p->casas[l][m])=='X')
			{
				aux[0]++;
				aux_win[m][0]++;
				aux_win[m+3][0]++;
				if (m==l)
				{
					aux_win[6][0]++;
				}
				if ((2-m)==(l))
				{
					aux_win[7][0]++;
				}
			}
			//Conferindo o número de casas por coluna, linha e diagonal de 0
			if ((p->casas[l][m])=='0')
			{
				aux[1]++;
				aux_win[m][1]++;
				aux_win[m+3][1]++;
				if (m==l)
				{
					aux_win[6][1]++;
				}
				if ((2-m)==(l))
				{
					aux_win[7][1]++;
				}
			}
		}
	}

	//Verifica se houve vitória;
	for (int j = 0; j < 8; ++j)
	{
		if(aux_win[j][0]==3)
		{
			printf("O primeiro jogador venceu\n");
			return 0;
		}
		if(aux_win[j][1]==3)
		{
			printf("O segundo jogador venceu\n");
			return 0;
		}
	}

	//Verifica se houve empate
	if ((aux[0]+aux[1])==9)
	{
		printf("Empate\n");
		return 0;
	}

	return 1;
}

/**
* Essa função checa a validade do tabuleiro inicial
* Casos que eu considerei são quando há um número maior
* de peças de um em relação ao outro ou que há uma entra-
*da inválida.
*/
int check_for_invalid_form(tabuleiro *p)
{
	int auxx = 0;
	int auxy = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (((p->casas[i][j])!='X')&&((p->casas[i][j])!='0')&&((p->casas[i][j])!='.'))
			{
				printf("Invalido\n");
				return 0;
			}
			if (p->casas[i][j]=='X')
			{
				auxx++;
			}
			if (p->casas[i][j]=='0')
			{
				auxy++;
			}
		}
	}
	if ((auxx==auxy-1)||(auxx==auxy)||(auxx-1==auxy))
	{
		return 1;
	}
	else
	{
		printf("Invalido\n");
		return 0;
	}
}

