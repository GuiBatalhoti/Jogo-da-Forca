#include "./Estruturas_de_Dados/Lista.h"

class Jogador
{
private:
public:
	Jogador();
	~Jogador();

	ListaGenerica<char>* lista_acertos;
	ListaGenerica<char>* lista_erros;

	char tentativa;
};