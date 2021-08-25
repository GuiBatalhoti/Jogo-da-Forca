template <typename TipoElemento>
class NO
{
private:

public:
	NO<TipoElemento>* proximo;
	TipoElemento elemento;
	NO();
	~NO();
};

template <typename TipoElemento>
NO<TipoElemento>::NO()
{
	this->proximo = NULL;
}

template <typename TipoElemento>
NO<TipoElemento>::~NO()
{

}