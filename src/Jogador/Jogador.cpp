#include "Jogador.h"

Jogador::Jogador()
{
	this->lista_acertos = new ListaGenerica<char>();
	this->lista_erros = new ListaGenerica<char>();
}

Jogador::~Jogador()
{
	delete &this->lista_acertos;
	delete &this->lista_erros;
}