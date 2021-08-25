#include "No.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

template <typename TipoElemento>
class ListaGenerica
{
private:
	int tamanho;

public:
	NO<TipoElemento>* inicio;
	NO<TipoElemento>* fim;
	NO<TipoElemento>* proximo;
	ListaGenerica();
	~ListaGenerica();

	int TamanhoLista();
	void InsereElementoFinal(TipoElemento elemento);
	void RemoveElementoInicio();
	bool ConsultaElemento(TipoElemento elemento);
	bool ListaVazia();
	TipoElemento PegaElementoAleatorio();
};

template <typename TipoElemento>
ListaGenerica<TipoElemento>::ListaGenerica()
{
	this->inicio = NULL;
	this->fim = NULL;
	this->tamanho = 0;
}

template <typename TipoElemento>
ListaGenerica<TipoElemento>::~ListaGenerica()
{
	delete this->inicio;
}

template <typename TipoElemento>
bool ListaGenerica<TipoElemento>::ListaVazia()
{
	if (this->inicio == NULL)
		return true;

	return false;
}

template <typename TipoElemento>
void ListaGenerica<TipoElemento>::InsereElementoFinal(TipoElemento elemento)
{
	NO<TipoElemento>* novo_no = new NO<TipoElemento>();
	novo_no->elemento = elemento;
	if (this->ListaVazia())
	{
		this->inicio = novo_no;
		this->fim = novo_no;
	}
	else
	{
		this->fim->proximo = novo_no;
		this->fim = novo_no;
	}

	this->tamanho++;
}

template <typename TipoElemento>
void ListaGenerica<TipoElemento>::RemoveElementoInicio()
{
}

template <typename TipoElemento>
int ListaGenerica<TipoElemento>::TamanhoLista()
{
	return this->tamanho;
}

template <typename TipoElemento>
bool ListaGenerica<TipoElemento>::ConsultaElemento(TipoElemento elemento)
{
	if (this->ListaVazia())
		return false;

	NO<TipoElemento>* atual = this->inicio;

	while (atual != NULL)
	{
		if (atual->elemento == elemento)
			return true;

		atual = atual->proximo;
	}

	return false;
}

template <typename TipoElemento>
TipoElemento ListaGenerica<TipoElemento>::PegaElementoAleatorio()
{
	std::srand(std::time(NULL));

	int posicao = std::rand() % this->tamanho;

	TipoElemento el_aleatorio = this->inicio->elemento;

	NO<TipoElemento>* atual = this->inicio;

	while (posicao > 0)
	{
		el_aleatorio = atual->elemento;
		atual = atual->proximo;
		posicao--;
	}


	return el_aleatorio;
}