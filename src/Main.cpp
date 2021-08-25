#include "Game/Game.h"
#include "Platform/Platform.hpp"

#define MENU 0
#define FORCA 1
#define PALAVRAINPUT 2
#define GANHADOR 3
#define PERDEDOR 4

int main()
{
	//Inicializando o jogo

	Game game;

	//loop principal
	while (game.ChecaWindowIsOpen())
	{
		switch (game.Estado)
		{
			case MENU:
				game.AtualizaJanela();
				game.RenderizaJanelaIncial(); //MENU
				break;

			case FORCA:
				game.RenderizaForca(); //FORCA
				break;

			case PALAVRAINPUT:
				game.RenderizaNovaPalavra(); //input de palavras em arquivo
				break;

			case GANHADOR:
				game.RenderizaTelaGanhador();
				break;

			case PERDEDOR:
				game.RenderizaTelaPerdedor();
				break;

			default:

				break;
		}
	}

	//fim da aplicacao
	return 0;
}
