#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//#include "./Estruturas_de_Dados/ListaSimplesEncadeada.h"
#include "./Jogador/Jogador.h"
#include "./Palavra/Palavra.h"

/* Classe principal do jogo. */

class Game
{
private:
	//variáveis

	//Outras Classes
	Palavra palavra;
	Jogador jogador;

	//Janela
	sf::RenderWindow* janela; //ponteiro para a tela, para ser dinâmica
	sf::VideoMode modo_video; //contém as propriedades da tela

	//Eventos
	sf::Event acontecimento; //verifica os eventos

	//Fontes
	sf::Font fonte; //armazena o arquivo de fontes de letras

	//Menu
	sf::RectangleShape dificuldade_1, dificuldade_2, dificuldade_3; //formatos dos desenhos do menu
	sf::Texture textura_dif_1, textura_dif_2, textura_dif_3;		//texturas do menu
	sf::Vector2i posicao_mouse;										//armazena a posiçaõ do mouse com relação à tela
	sf::Vector2f coordenadas_mouse;									//armazena as coordenadas do mouse com relação à função de captura
	sf::RectangleShape btn_nova_palavra;

	//texto
	std::string texto_entrada_errada; //entrada errada
	sf::Text tentativa_jogador;		  //variável que armazena o texto
	sf::Text texto_ganhador, texto_perdedor;

	//input de novas palavras
	sf::Text texto_padrao_INPUT, texto_entrada_INPUT;
	sf::RectangleShape btn_voltar;
	std::ostringstream input;
	sf::Texture textura_INPUT;

	//Fase
	sf::RectangleShape forca, chao, cabeca, corpo, perna_esq, perna_dir, braco_esq, braco_dir;						 //formatos dos desnhos da forca
	sf::Texture img_forca, img_chao;																				 //texturas de ambiente
	sf::Texture img_cabeca, img_corpo, img_perna_esquerda, img_perna_direita, img_braco_esquerdo, img_braco_direito; //texturas do personagem
	sf::Text texto_acertos, texto_acerto_letras, texto_erro_letras, texto_erros, texto_dica, texto_palavra_escondida;

	//temporizador
	sf::Time lim_tempo, temporizador_segundos;
	sf::Clock temporizador;

	//Funções de Incialização de variáveis
	void IncializaVariaveis();		//geral
	void IncializaJanela();			//apenas cria a janela
	void InicializaTextosForca();	//propriedades do texto
	void InicializaMenu();			//menu
	void InicializaTexturasMenu();	//texturas menu
	void InicializaTexturasForca(); //texturas forca
	void InicializaTextosINPUT();	//textos do campo de input de novas palavras
	void InicializaTexturasINPUT();

	//Funções de checagem de Eventos
	void ChecaEventosFase();	   //checagem de eventos de entrada da forca
	void ChecaEntradaTexto();	   //checagem da entrada de texto dentro da forca
	void ChecaEventoMenu();		   //checagem de eventos de entrada no menu
	bool ChecaBotaoMouse();		   //checa se hove botão pressionado
	void ChecaEventosINPUT();	   //checa os eventos na tela de input de palavras
	void ChecaEntradaTextoINPUT(); //checagem de eventos de texto na tela de input de palavras
	bool ContinuaJogo();

	//Renderização
	void RenderizaPersonagem();
	void RenderizaLetras();

	//funções de verificação de entrada de tentativas
	void TesteTentativa();
	void ModificaPalavraEscondida(char tentativa);
	void AlteraTextoAcertos();
	void AlteraTextoErros();

public:
	int Estado; //variável que armazena o estado do jogo, ou seja, "Menu" ou "Forca" ou "Tela de Ganhador" ou "Tela de Perdedor"

	//Construtores e Destrutores
	Game();
	~Game();

	//Funções
	void AtualizaJanela();		  //chama a função de entrada de eventos
	void AtualizaModoJogo();		  //atualiza o modo de jogo
	void InicializaForca();		  //inicializa as funções do estado "forca"
	void RenderizaJanelaIncial(); //rederiza o estado menu
	void RenderizaForca();		  //renderiza o estado forca
	void RenderizaNovaPalavra();
	void RenderizaTelaGanhador();
	void RenderizaTelaPerdedor();

	bool ChecaWindowIsOpen();
};
