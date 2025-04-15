t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*

Objetivo: cria e inicializa um novo node para uma linked list.
Ele aloca memória para um novo node, atribui-lhe um conteúdo (passado como 
paramêtro) e define o ponteiro next desse node como NULL, indicando que ele
ainda não está ligado a nenhum outro node.
Ou seja, ft_lstnew devolve um node individual, pronto para ser ligado a uma
lista (no ínicio, no fim, no meio, etc).

Parâmetro:

    content: É um ponteiro genérico (tipo void *) para o conteúdo que queremos armazenar
	no novo node.
    Como o tipo é void *, o conteúdo pode ser qualquer coisa: um int, uma string, uma struct, 
	etc. Esta flexibilidade é o que torna as linked lists muito úteis e reutilizáveis.

1 - Alocação de memória para o novo node

	new_node = malloc(sizeof(t_list));

	A primeira coisa que fazemos é alocar espaço suficiente na memória para armazenar um novo node
	da linked list e guardar o ponteiro dessa memória na variável new_node.

	t_list é uma estrutura (struct) que representa o formato de um node numa linked list.

	typedef struct s_list
	{
		void			*content;
		struct s_list	*next;
	}	t_list;

    content: É um ponteiro genérico (void *) que armazena o conteúdo do node.
    next: É um ponteiro para o próximo node da lista (ou NULL se for o último node).
    O nome t_list é apenas um apelido (alias) que demos para a struct s_list, com typedef.

	Exemplo simples de como um node da lista pode ser visualizado:

	t_list *node;
	node = ft_lstnew("Olá");

	Neste caso: node->content → aponta para a string "Olá"
                node->next → é NULL, porque é um node isolado

    Visualmente: node → [ "Olá" ] → NULL


	> sizeof(list) calcula quantos bytes são necessários para armazenar uma struct do tipo t_list.

	Se a estrutura for como esta:

	typedef struct s_list
	{
		void			*content; // ponteiro (8 bytes em sistemas de 64 bits)
		struct s_list	*next;    // ponteiro (8 bytes em sistemas de 64 bits)
	}	t_list;

	Então, sizeof(t_list) será 16 bytes (em sistemas de 64 bits), porque temos dois ponteiros de
	8 bytes cada, conforme a arquitetura do sistema.
	
	> malloc(sizeof(t_list)): a função malloc aloca dinamicamente na heap uma quantidade de memória 
	igual a sizeof(t_list).
    Essa memória é não inicializada (os valores lá dentro podem ser "lixo" até os definirmos).
    O malloc devolve um ponteiro genérico (void *) para essa área de memória.
    Como new_node é um ponteiro para t_list, o ponteiro devolvido por malloc é convertido automaticamente
	para t_list *.

	
2 - Atribuição do conteúdo

	new_node->content = content;

	Atribuímos ao content do novo node (new_node) o conteúdo (o valor) que passámos como argumento.
	Ou seja, o ponteiro content do novo node (new_node) agora aponta para o conteúdo que passámos 
	como argumento.
	Significa algo como: "o conteúdo do novo node será igual ao conteúdo que foi passado como argumento
	na função ft_lstnew".
	Estamos a copiar o valor do argumento content para o content do novo node (new_node).

	Se esquecêssemos new_node->content = content;, o campo content do node ficaria com lixo da memória 
	(valor indefinido), e não poderíamos aceder corretamente ao conteúdo da lista.

	Exemplo 1: conteúdo é uma string

	t_list *node;
	char *mensagem = "Olá, 42!";
	node = ft_lstnew(mensagem);

	Neste caso: content = ponteiro para a string "Olá, 42!"
                A função guarda esse ponteiro no node->content
                A lista vai apontar para essa string

    Visualmente: node → [ "Olá, 42!" ] → NULL

3 - Inicialização do ponteiro next
	new_node->next = NULL;

	Aqui definimos que o novo node que acabamos de criar ainda não está ligado a nenhum outro node
	da linked list.
	Por outras palavras, o ponteiro next do novo node vai apontar para NULL, ou seja, não há nenhum 
	node a seguir a ele neste momento.
	
	Isso significa que, neste momento, o novo node não está ligado a nenhum outro node.
	Ou seja, ele é um node isolado, pronto para ser adicionado a uma lista.


*/