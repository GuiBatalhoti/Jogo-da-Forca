#include "Palavra.h"
#include "./Estruturas_de_Dados/Lista.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//===========================================================================
//Construtores

Palavra::Palavra()
{
}

Palavra::~Palavra()
{
	this->FechaArquivo();
}

//===========================================================================
//Inicialização Geral

void Palavra::InicializaArquivo(int num_letras)
{
	this->saida_arquivo_palavras_faceis.open("./ArquivoaPalavras/PalavrasFaceis.txt", std::ios::app);
	this->saida_arquivo_dicas_faceis.open("./ArquivoPalavras/DicasFaceis.txt", std::ios::app);
	this->saida_arquivo_palavras_medias.open("./ArquivoPalavras/PalavrasMedias.txt", std::ios::app);
	this->saida_arquivo_dicas_medias.open("./ArquivoPalavras/DicasMedias.txt", std::ios::app);
	this->saida_arquivo_palavras_dificeis.open("./ArquivoPalavas/PalavrasDiciceis.txt", std::ios::app);
	this->saida_arquivo_dicas_dificeis.open("./ArquivoPalavras/DicasDificeis.txt", std::ios::app);

	if (num_letras == 3)
	{
		this->entrada_arquivo_palavras.open("./ArquivoPalavras/PalavrasFaceis.txt");
		this->entrada_arquivo_dicas.open("./ArquivoPalavras/DicasFaceis.txt");
	}
	if (num_letras == 6)
	{
		this->entrada_arquivo_palavras.open("./ArquivoPalavras/PalavrasMedias.txt");
		this->entrada_arquivo_dicas.open("./ArquivoPalavras/DicasMedias.txt");
	}
	if (num_letras == 7)
	{
		this->entrada_arquivo_palavras.open("./ArquivoPalavras/PalavrasDificeis.txt");
		this->entrada_arquivo_dicas.open("./ArquivoPalavras/DicasDificeis.txt");
	}
}

void Palavra::FechaArquivo()
{
	this->entrada_arquivo_palavras.close();
	this->entrada_arquivo_dicas.close();

	this->saida_arquivo_palavras_faceis.close();
	this->saida_arquivo_dicas_faceis.close();
	this->saida_arquivo_palavras_medias.close();
	this->saida_arquivo_dicas_medias.close();
	this->saida_arquivo_palavras_dificeis.close();
	this->saida_arquivo_dicas_dificeis.close();
}

//===========================================================================
//Inicialização da Palavra da forca

void Palavra::InicializaPalavra(int num_letras)
{
	std::srand(std::time(NULL));
	ListaGenerica<std::string> lista_palavras;
	std::string aux;

	this->InicializaArquivo(num_letras);

	while (std::getline(this->entrada_arquivo_palavras, this->palavra_principal))
	{
		lista_palavras.InsereElementoFinal(this->palavra_principal);
	}

	this->palavra_principal = lista_palavras.PegaElementoAleatorio();

	this->FechaArquivo();
	this->InicializaArquivo(num_letras);

	while (std::getline(this->entrada_arquivo_palavras, aux))
	{
		std::getline(this->entrada_arquivo_dicas, this->dica);
		if (aux == this->palavra_principal)
			break;
	}

	this->EscondePalavra();

	std::cout << this->palavra_principal << std::endl;
}

void Palavra::EscondePalavra()
{
	for (int i = 0; i < (int)this->palavra_principal.length(); i++)
	{
		this->palavra_escondida += '_';
	}
	std::cout << this->palavra_escondida << std::endl;
}

//===========================================================================
//Gravação no arquivo

void Palavra::GravaPalavraArquivo(std::string string)
{
	int i = 0;
	std::string string_palavra, string_dica;
	while (string[i] != ',')
	{
		string_palavra[i] = string[i];
		i++;
	}

	i += 2;

	for (int j = 0; j < (int)string.size(); j++)
	{
		string_dica[j] = string[i];
	}

	if ((int)string_palavra.length() == 3)
	{
		this->saida_arquivo_palavras_faceis << string_palavra << "\n";
		this->saida_arquivo_dicas_faceis << string_dica << "\n";
	}
	else if ((int)string_palavra.length() > 3 && (int)string_palavra.length() <= 6)
	{
		this->saida_arquivo_palavras_medias << string_palavra << "\n";
		this->saida_arquivo_dicas_medias << string_dica << "\n";
	}
	else if ((int)string_palavra.length() > 6)
	{
		this->saida_arquivo_palavras_dificeis << string_palavra << "\n";
		this->saida_arquivo_dicas_dificeis << string_dica << "\n";
	}
}

//===========================================================================
//Busca de caracteres

bool Palavra::VerificaPalvraEscondidaDescoberta()
{
	for (int i = 0; i < (int)this->palavra_escondida.length(); i++)
	{
		if (this->palavra_escondida[i] == '_')
		return false;
	}

	return true;

}