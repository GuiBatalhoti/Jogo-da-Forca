#include "Game.h"
#include <cctype>

#define MENU 0
#define FORCA 1
#define PALAVRAINPUT 2
#define GANHADOR 3
#define PERDEDOR 4

#define FACIL 3
#define MEDIO 6
#define DIFICIL 7

//===========================================================================
//Construtores

Game::Game()
{
	/* Construtor, chama as funções inciais do jogo. */

	this->IncializaVariaveis();
	this->IncializaJanela();
	this->InicializaTexturasMenu();
	this->InicializaMenu();
	this->InicializaTexturasForca();
	this->InicializaTextosForca();
	this->InicializaTextosINPUT();
	this->InicializaTexturasINPUT();
}

Game::~Game()
{
	/* Destrutor, apenas descontói para o encerramento. */
	delete this->janela;
}

//===========================================================================
//Inicialização Geral

void Game::IncializaVariaveis()
{
	/* Inicializa as variáveis */
	this->janela = NULL;
	this->Estado = MENU;
	this->texto_entrada_errada = "Por favor, insira um caractere valido!";
	this->texto_acertos.setString("Acertos:");
	this->texto_erros.setString("Erros:");
	this->texto_ganhador.setString("PARABENS VOCE VENCEU!!!");
	this->texto_perdedor.setString("QUE PENA VOCE PERDEU...");
	this->texto_ganhador.setFont(this->fonte);
	this->texto_ganhador.setFillColor(sf::Color::White);
	this->texto_ganhador.setCharacterSize(32);
	this->texto_ganhador.setPosition(100.f, 180.f);
	this->texto_perdedor.setFont(this->fonte);
	this->texto_perdedor.setFillColor(sf::Color::White);
	this->texto_perdedor.setCharacterSize(32);
	this->texto_perdedor.setPosition(100.f, 180.f);
}

//===========================================================================
//Inicialização Menu

void Game::IncializaJanela()
{
	/*
		Coloca as propriedades iniciais da janela:
		-altura;
		-largura;
		-atribui ao ponterio da janela o seu obejto de janela;
	*/

	this->modo_video.height = 480;
	this->modo_video.width = 640;
	this->janela = new sf::RenderWindow(this->modo_video, "Jogo da Forca", sf::Style::Close | sf::Style::Titlebar);
	this->janela->setFramerateLimit(60);
}

void Game::InicializaTexturasMenu()
{
	this->textura_dif_1.loadFromFile("./Menu/Facil.png");
	this->textura_dif_2.loadFromFile("./Menu/Medio.png");
	this->textura_dif_3.loadFromFile("./Menu/Dificil.png");
}

void Game::InicializaMenu()
{
	/* Inicializa as opções do menu de dificuldades. */

	this->btn_nova_palavra = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
	this->btn_nova_palavra.setFillColor(sf::Color::Red);
	this->btn_nova_palavra.setPosition(0.f, 0.f);
	this->dificuldade_1 = sf::RectangleShape(sf::Vector2f(300.f, 90.f));
	this->dificuldade_1.setTexture(&this->textura_dif_1);
	this->dificuldade_1.setPosition(150.f, 85.f);
	this->dificuldade_2 = sf::RectangleShape(sf::Vector2f(300.f, 90.f));
	this->dificuldade_2.setTexture(&this->textura_dif_2);
	this->dificuldade_2.setPosition(150.f, 175.f);
	this->dificuldade_3 = sf::RectangleShape(sf::Vector2f(300.f, 90.f));
	this->dificuldade_3.setTexture(&this->textura_dif_3);
	this->dificuldade_3.setPosition(150.f, 275.f);
}

//===========================================================================
//Inicialização Forca

void Game::InicializaTexturasForca()
{

	this->img_chao.loadFromFile("./ImagensForca/Plano_Chao.png");
	this->img_forca.loadFromFile("./ImagensForca/Forca.png");
	this->img_cabeca.loadFromFile("./ImagensForca/Cabeca.png");
	this->img_corpo.loadFromFile("./ImagensForca/Corpo.png");
	this->img_braco_direito.loadFromFile("./ImagensForca/BracoDireito.png");
	this->img_braco_esquerdo.loadFromFile("./ImagensForca/Bracoesquerdo.png");
	this->img_perna_direita.loadFromFile("./ImagensForca/PernaDireita.png");
	this->img_perna_esquerda.loadFromFile("./ImagensForca/PernaEsquerda.png");
}

void Game::InicializaForca()
{
	this->forca = sf::RectangleShape(sf::Vector2f(600.f, 300.f));
	this->forca.setTexture(&this->img_forca);
	this->forca.setPosition(-155.f, 100.f);
	this->chao = sf::RectangleShape(sf::Vector2f(640.f, 90.f));
	this->chao.setTexture(&this->img_chao);
	this->chao.setPosition(0.f, 390.f);
	this->corpo = sf::RectangleShape(sf::Vector2f(80.f, 80.f));
	this->corpo.setTexture(&this->img_corpo);
	this->corpo.setPosition(200.f, 210.f);
	this->cabeca = sf::RectangleShape(sf::Vector2f(80.f, 80.f));
	this->cabeca.setTexture(&this->img_cabeca);
	this->cabeca.setPosition(200.f, 165.f);
	this->braco_dir = sf::RectangleShape(sf::Vector2f(80.f, 80.f));
	this->braco_dir.setTexture(&this->img_braco_direito);
	this->braco_dir.setPosition(210.f, 215.f);
	this->braco_esq = sf::RectangleShape(sf::Vector2f(80.f, 80.f));
	this->braco_esq.setTexture(&this->img_braco_esquerdo);
	this->braco_esq.setPosition(188.f, 215.f);
	this->perna_dir = sf::RectangleShape(sf::Vector2f(80.f, 80.f));
	this->perna_dir.setTexture(&this->img_perna_direita);
	this->perna_dir.setPosition(208.f, 248.f);
	this->perna_esq = sf::RectangleShape(sf::Vector2f(80.f, 80.f));
	this->perna_esq.setTexture(&this->img_perna_esquerda);
	this->perna_esq.setPosition(186.f, 248.f);
}

void Game::InicializaTextosForca()
{
	this->fonte.loadFromFile("./Fontes/Helvetica.ttf");
	this->tentativa_jogador.setFont(this->fonte);
	this->tentativa_jogador.setFillColor(sf::Color::Black);
	this->tentativa_jogador.setCharacterSize(24);
	this->tentativa_jogador.setPosition(150.f, 350.f);
	this->tentativa_jogador.setStyle(sf::Text::Underlined);

	this->texto_acertos.setFont(this->fonte);
	this->texto_acertos.setFillColor(sf::Color::Black);
	this->texto_acertos.setCharacterSize(24);
	this->texto_acertos.setPosition(400.f, 70.f);
	this->texto_erros.setFont(this->fonte);
	this->texto_erros.setFillColor(sf::Color::Black);
	this->texto_erros.setCharacterSize(24);
	this->texto_erros.setPosition(400.f, 130.f);

	this->texto_dica.setFont(this->fonte);
	this->texto_dica.setFillColor(sf::Color::Black);
	this->texto_dica.setCharacterSize(22);
	this->texto_dica.setPosition(5.f, 30.f);
	this->texto_dica.setString(palavra.dica);

	this->texto_palavra_escondida.setFont(this->fonte);
	this->texto_palavra_escondida.setFillColor(sf::Color::Black);
	this->texto_palavra_escondida.setCharacterSize(24);
	this->texto_palavra_escondida.setPosition(350.f, 350.f);

	this->texto_acerto_letras.setFont(this->fonte);
	this->texto_acerto_letras.setFillColor(sf::Color::Black);
	this->texto_acerto_letras.setCharacterSize(24);
	this->texto_acerto_letras.setPosition(500.f, 70.f);

	this->texto_erro_letras.setFont(this->fonte);
	this->texto_erro_letras.setFillColor(sf::Color::Black);
	this->texto_erro_letras.setCharacterSize(24);
	this->texto_erro_letras.setPosition(470.f, 130.f);
}

//===========================================================================
//Inicialização Campo de INPUT

void Game::InicializaTextosINPUT()
{
	this->texto_padrao_INPUT.setString("Modo de entrada de novas palavas: 'NOVA_PALAVRA, Dica...'");
	this->texto_padrao_INPUT.setFont(this->fonte);
	this->texto_padrao_INPUT.setFillColor(sf::Color::Black);
	this->texto_padrao_INPUT.setCharacterSize(18);
	this->texto_padrao_INPUT.setPosition(5.f, 100.f);
	this->texto_padrao_INPUT.setStyle(sf::Text::Underlined);

	this->texto_entrada_INPUT.setFont(this->fonte);
	this->texto_entrada_INPUT.setFillColor(sf::Color::Black);
	this->texto_entrada_INPUT.setCharacterSize(18);
	this->texto_entrada_INPUT.setPosition(10.f, 120.f);
}

void Game::InicializaTexturasINPUT()
{
	this->textura_INPUT.loadFromFile("./JanelaINPUT/Seta.png");
	this->btn_voltar = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	this->btn_voltar.setTexture(&this->textura_INPUT);
}

//===========================================================================
//Funções Auxiliares e de Checagem de Eventos

bool Game::ChecaBotaoMouse()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Game::ChecaWindowIsOpen()
{
	return this->janela->isOpen(); //matém a tela aberta
}

void Game::ChecaEventoMenu()
{
	/*
		Verifica os eventos da tela:
		-mantém um auditor de eventos;
		-caso haja um evento, executa uma ação;
	*/

	while (this->janela->pollEvent(this->acontecimento)) //loop de eventos da tela
	{
		switch (this->acontecimento.type)
		{
			case sf::Event::Closed: //fechamento da tela
				this->janela->close();
				break;

			case sf::Event::MouseButtonPressed:
				this->posicao_mouse = sf::Mouse::getPosition(*this->janela);
				this->coordenadas_mouse = this->janela->mapPixelToCoords(this->posicao_mouse);
				this->AtualizaModoJogo();
				break;
			default:
				break;
		}
	}
}

void Game::ChecaEventosFase()
{
	while (this->janela->pollEvent(this->acontecimento)) //loop de eventos da tela
	{
		switch (this->acontecimento.type)
		{
			case sf::Event::Closed: //fechamento da tela
				this->janela->close();
				break;

			case sf::Event::TextEntered:
				this->ChecaEntradaTexto();
				break;
			default:
				break;
		}
	}
}

void Game::ChecaEntradaTexto()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->TesteTentativa();
	}
	else
	{
		if (this->acontecimento.text.unicode >= 65 && this->acontecimento.text.unicode <= 90) //Maiúsculas
		{
			jogador.tentativa = static_cast<char>(this->acontecimento.text.unicode);
			this->tentativa_jogador.setString(jogador.tentativa);
		}
		else if (this->acontecimento.text.unicode >= 97 && this->acontecimento.text.unicode <= 122) //minúsculas
		{
			jogador.tentativa = static_cast<char>(this->acontecimento.text.unicode);
			this->tentativa_jogador.setString(jogador.tentativa);
		}
		else
		{
			this->tentativa_jogador.setString(this->texto_entrada_errada);
		}
	}
}

void Game::ChecaEventosINPUT()
{
	while (this->janela->pollEvent(this->acontecimento)) //loop de eventos da tela
	{
		switch (this->acontecimento.type)
		{
			case sf::Event::Closed: //fechamento da tela
				this->janela->close();
				break;

			case sf::Event::TextEntered:
				this->ChecaEntradaTextoINPUT();
				break;

			case sf::Event::MouseButtonPressed:
				this->posicao_mouse = sf::Mouse::getPosition(*this->janela);
				this->coordenadas_mouse = this->janela->mapPixelToCoords(this->posicao_mouse);
				if (this->btn_voltar.getGlobalBounds().contains(this->coordenadas_mouse))
					this->Estado = MENU;
				break;

			default:
				break;
		}
	}
}

void Game::ChecaEntradaTextoINPUT()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		palavra.GravaPalavraArquivo(this->input.str());
		this->Estado = MENU;
	}
	else
	{
		this->input << static_cast<char>(this->acontecimento.text.unicode);
		this->texto_entrada_INPUT.setString(this->input.str());
	}
}

bool Game::ContinuaJogo()
{
	if (jogador.lista_erros->TamanhoLista() < 6 && !palavra.VerificaPalvraEscondidaDescoberta())
		return true;

	return false;
}

//===========================================================================
//Atualização de telas

void Game::AtualizaJanela()
{
	this->ChecaEventoMenu();
}

void Game::AtualizaModoJogo()
{
	this->Estado = FORCA;
	if (this->dificuldade_1.getGlobalBounds().contains(this->coordenadas_mouse))
		palavra.InicializaPalavra(FACIL); //manda a dificuldade como parâmetro para puxar o número de palavras e letras
	else if (this->dificuldade_2.getGlobalBounds().contains(this->coordenadas_mouse))
		palavra.InicializaPalavra(MEDIO); //manda a dificuldade como parâmetro para puxar o número de palavras e letras
	else if (this->dificuldade_3.getGlobalBounds().contains(this->coordenadas_mouse))
		palavra.InicializaPalavra(DIFICIL); //manda a dificuldade como parâmetro para puxar o número de palavras e letras
	else if (this->btn_nova_palavra.getGlobalBounds().contains(this->coordenadas_mouse))
		this->Estado = PALAVRAINPUT;

	this->texto_dica.setString(palavra.dica);
	this->texto_palavra_escondida.setString(palavra.palavra_escondida);
}

//===========================================================================
//Rederizaçção ou Desenhos

void Game::RenderizaJanelaIncial()
{
	/*
		Renderiza os abjetos do jogo:
		-limpa a tela antiga;
		-cria os novos objetos;
		-coloca a nova tela na janela;
	*/

	this->janela->clear(sf::Color::White); //cor de fundo

	this->janela->draw(this->dificuldade_1);
	this->janela->draw(this->dificuldade_2);
	this->janela->draw(this->dificuldade_3);
	this->janela->draw(this->btn_nova_palavra);
	this->janela->display(); //desenha o que foi escrito
}

void Game::RenderizaForca()
{
	if (this->ContinuaJogo())
	{
		this->InicializaForca();			  //incializa as texturas da Forca
		this->janela->clear(sf::Color::Cyan); //fundo
		this->janela->draw(this->chao);		  //chão
		this->janela->draw(this->forca);	  //desenho da forca
		if (this->tentativa_jogador.getString() != "")
		{
			this->janela->draw(this->tentativa_jogador);
		}
		this->RenderizaPersonagem();
		this->janela->draw(this->texto_acertos);
		this->janela->draw(this->texto_erros);
		this->janela->draw(this->texto_dica);
		this->janela->draw(this->texto_palavra_escondida);
		if (jogador.lista_acertos->inicio != NULL)
		{
			this->janela->draw(this->texto_acerto_letras);
		}
		if (this->texto_erro_letras.getString() != "")
		{
			this->janela->draw(this->texto_erro_letras);
		}

		this->janela->display(); //lança em tela
		this->ChecaEventosFase();
	}
	else if (jogador.lista_erros->TamanhoLista() == 6)
		this->Estado = PERDEDOR;
	else
		this->Estado = GANHADOR;
}

void Game::RenderizaNovaPalavra()
{
	this->janela->clear(sf::Color::Cyan);
	this->janela->draw(this->texto_padrao_INPUT);
	this->janela->draw(this->texto_entrada_INPUT);
	this->janela->draw(this->btn_voltar);
	this->janela->display();

	this->ChecaEventosINPUT();
}

void Game::RenderizaPersonagem()
{
	switch (jogador.lista_erros->TamanhoLista())
	{
		case 1:
			this->janela->draw(this->cabeca);
			break;

		case 2:
			this->janela->draw(this->cabeca);
			this->janela->draw(this->corpo);
			break;

		case 3:
			this->janela->draw(this->cabeca);
			this->janela->draw(this->corpo);
			this->janela->draw(this->perna_dir);
			break;

		case 4:
			this->janela->draw(this->cabeca);
			this->janela->draw(this->corpo);
			this->janela->draw(this->perna_dir);
			this->janela->draw(this->perna_esq);
			break;

		case 5:
			this->janela->draw(this->cabeca);
			this->janela->draw(this->corpo);
			this->janela->draw(this->perna_dir);
			this->janela->draw(this->perna_esq);
			this->janela->draw(this->braco_dir);
			break;

		case 6:
			this->janela->draw(this->cabeca);
			this->janela->draw(this->corpo);
			this->janela->draw(this->perna_dir);
			this->janela->draw(this->perna_esq);
			this->janela->draw(this->braco_dir);
			this->janela->draw(this->braco_esq);
			break;

		default:
			break;
	}
}

void Game::RenderizaLetras()
{
	NO<char>* atual_acertos = jogador.lista_acertos->inicio;
	NO<char>* atual_erros = jogador.lista_erros->inicio;
	std::string string_aux_erros, string_aux_acertos;

	if (jogador.lista_acertos->inicio != NULL)
	{
		while (atual_acertos->proximo != NULL)
		{
			string_aux_acertos += atual_acertos->elemento;
			atual_acertos = atual_acertos->proximo;
			std::cout << string_aux_acertos << "/" << atual_acertos->elemento << std::endl;
		}
		texto_acerto_letras.setString(string_aux_acertos);
	}

	if (jogador.lista_erros->inicio != NULL)
	{
		while (atual_erros->proximo != NULL)
		{
			string_aux_erros += atual_erros->elemento;
			atual_erros = atual_erros->proximo;
			std::cout << string_aux_erros << "/" << atual_erros->elemento << std::endl;
		}
		texto_erro_letras.setString(string_aux_erros);
	}

}

void Game::RenderizaTelaGanhador()
{
	this->janela->clear(sf::Color::Black);
	this->janela->draw(this->texto_ganhador);
	this->janela->display();

	while (this->janela->pollEvent(this->acontecimento)) //loop de eventos da tela
	{
		if (this->acontecimento.type == sf::Event::Closed)
			janela->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			this->Estado = MENU;
	}

}

void Game::RenderizaTelaPerdedor()
{
	this->janela->clear(sf::Color::Black);
	this->janela->draw(this->texto_perdedor);
	this->janela->display();

	while (this->janela->pollEvent(this->acontecimento)) //loop de eventos da tela
	{
		if (this->acontecimento.type == sf::Event::Closed)
			janela->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			this->Estado = MENU;
	}
}

//===========================================================================
//Teste de tentativa

void Game::TesteTentativa()
{
	std::string str_tentativa = this->tentativa_jogador.getString();
	char tentativa = std::toupper(str_tentativa[0]);
	bool achou = false;

	for (int i = 0; i < (int)palavra.palavra_principal.length(); i++)
	{
		if (palavra.palavra_principal[i] == tentativa)
			achou = true;
	}

	if (achou)
	{
		this->ModificaPalavraEscondida(tentativa);
	}
	else
	{
		if (!jogador.lista_erros->ConsultaElemento(tentativa))
			jogador.lista_erros->InsereElementoFinal(tentativa);
		else
			this->tentativa_jogador.setString("Letra ja utilizada");
		this->AlteraTextoErros();
	}
}

void Game::ModificaPalavraEscondida(char tentativa)
{
	for (int i = 0; i < (int)palavra.palavra_principal.length(); i++)
	{
		if (palavra.palavra_principal[i] == tentativa)
		{
			if (!jogador.lista_acertos->ConsultaElemento(tentativa))
				jogador.lista_acertos->InsereElementoFinal(tentativa);
			palavra.palavra_escondida[i] = tentativa;
			this->AlteraTextoAcertos();
		}
	}
	this->texto_palavra_escondida.setString(palavra.palavra_escondida);
}

void Game::AlteraTextoAcertos()
{
	NO<char>* atual = jogador.lista_acertos->inicio;
	std::string aux = "";

	while (atual != NULL)
	{
		std::cout << atual->elemento;
		aux += atual->elemento;
		atual = atual->proximo;
	}

	this->texto_acerto_letras.setString(aux);
}

void Game::AlteraTextoErros()
{
	NO<char>* atual = jogador.lista_erros->inicio;
	std::string aux = "";

	while (atual != NULL)
	{
		std::cout << atual->elemento;
		aux += atual->elemento;
		atual = atual->proximo;
	}

	this->texto_erro_letras.setString(aux);
}