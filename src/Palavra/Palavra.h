#include <fstream>
#include <string>

class Palavra
{
private:
	int dificuldade;

	std::ofstream saida_arquivo_palavras_faceis, saida_arquivo_dicas_faceis, saida_arquivo_palavras_medias, saida_arquivo_dicas_medias, saida_arquivo_palavras_dificeis, saida_arquivo_dicas_dificeis; //saida para o arquivo, ou seja, gravação
	std::ifstream entrada_arquivo_palavras, entrada_arquivo_dicas; //entrada do arquivo, ou seja, leitura

	void InicializaArquivo(int num_letras);
	void FechaArquivo();
	void EscondePalavra();

public:
	Palavra();
	~Palavra();

	std::string linha;
	std::string palavra_principal;
	std::string dica;
	std::string palavra_escondida;

	void InicializaPalavra(int num_letras);
	void GravaPalavraArquivo(std::string string);
	bool VerificaPalvraEscondidaDescoberta();
};