#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "gamefuncs.h"





int main(int argc, char const *argv[])
{
	tabuleiro t[1];
	/**
	* 	Primeiro declara-se a struct do tabuleiro (pode-se usar
	* mais de um se alterar uma outra entrada de parâmetro na
	* biblioteca). 
	*
	* Escolhi a struct tabuleiro pois era mais simples para 
	* trabalhar com ponteiro em relação a ponteiros de arrays
	* de dimensão 2.
	*/

	/**
	* Em seguida o usuário dá a entrada nas casas do tabuleiro
	* caso haja um tabuleiro anterior. Como não ficou muito cla-
	* se isso era sempre obrigatório eu assumi que era. Porém
	* pode ser alterado com um breve menu
	*
	*/
	input_jogo_anterior(t);

	if (check_for_invalid_form(t))
	{
	/**
	* Depois a função print limpa o a tela e printa o que está 
	* no tabuleiro.
	*/
		print_tabuleiro(t);

	/**
	* A função check_for_winner() retorna 0 se houver algum ganha
	*dor, e  se não tiver retorna zero.
	*
	*
	*/		
		if(check_for_winner(t))
		{
			newMovment(t);
		}
	}	
	return 0;
}