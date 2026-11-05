/* circulo.h

	TAD Circulo: tipo abstrato de dado para representar um circulo no RxR.
	
	@author Rodrigo Laiola Guimaraes <rlaiola@inf.ufes.br>
	(Adaptado do original)
*/

/************************************
 NAO MODIFIQUE NADA NESTE ARQUIVO.
*************************************/

#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>

/********************************************************************
	TAD: Circulo (centro, raio)
	
	OBS: Nao modifique nada neste arquivo.
********************************************************************/

struct Circulo{
	float raio;
	tPonto *ponto;
};

/* Funcoes exportadas */

/**
 * @brief Cria um circulo com centro nas coordenadas (x,y) e raio r
 * @param x Posição x do centro do círculo
 * @param y Posição y do centro do círculo
 * @param r Raio do Círculo
 * @return Ponteiro para o círculo criado.
 */
tCirculo* Circulo_Cria (float x, float y, float r){
	tCirculo *circulo = malloc(sizeof(struct Circulo));
	circulo->ponto = Pto_Cria(x,y);
	circulo->raio = r;
	return circulo;
}

/**
 * @brief Libera a memória alocada pelo círculo (e do seu centro com sua respectiva funçãos)
 * @param c Círculo que será apagado.
 */
void Circulo_Apaga (tCirculo* c){
	Pto_Apaga(c->ponto);
	free(c);
}

/**
 * @brief Retorna o ponto que representa o centro do circulo
 * @param c Círculo que terá o seu centro retornado
 * @return Variável do tipo ponto que representa o centro de "c"
 */
tPonto* Circulo_Acessa_Centro (tCirculo* c){
	return c->ponto;
}

/**
 * @brief Funcao que acessa o raio do círculo
 * @param c Círculo que terá o seu raio retornado
 * @return o raio do círculo
 */
float Circulo_Acessa_Raio (tCirculo* c){
	return c->raio;
}

/**
 * @brief Funcao que atribui um novo centro para um círculo utilizando as repesctivas funções do ponto.
 * @param c Círculo que terá o seu centro atualizado
 * @param p Ponto com as coordenadas do novo centro do círculo
 */
void Circulo_Atribui_Centro (tCirculo* c, tPonto* p){
	Pto_Atribui_x(c->ponto,Pto_Acessa_x(p));
	Pto_Atribui_y(c->ponto,Pto_Acessa_y(p));
}

/**
 * @brief Funcao que atribui um novo raio para um círculo
 * @param c Círculo que terá o seu raio atualizado
 * @param r Novo raio do círculo
 */
void Circulo_Atribui_Raio (tCirculo* c, float r){
	c->raio = r;
}

/**
 * @brief Funcao que indica se um ponto p está dentro do círculo c (ou sobre a circunferência).
 * @param c Círculo que será acessado e comparado com o ponto
 * @param p Ponto que será testado
 * @return 1 se a distância de p ao centro for menor ou igual ao raio, e 0 caso contrário.
 */
int Circulo_Interior (tCirculo* c, tPonto* p){
	if(Pto_Distancia(c->ponto,p) <= c->raio){
		return 1;
	}
	return 0;
}

/* _CIRCULO */
