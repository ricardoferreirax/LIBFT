
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}



/*

Uma lista encadeada é uma estrutura de dados dinâmica composta por nodes (chamados de
t_list), onde:

    Cada node aponta para o próximo.
    O primeiro node tem o nome de head.
    O último node aponta para NULL, o que indica o fim da lista.

Exemplo: [head] → [node1] → [node2] → [node3] → NULL

Estrutura típica do node t_list:

typedef struct s_list         // define uma esturura chamada s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

    content: guarda o dado (pode ser qualquer coisa: string, int, struct, etc.)
    next: é o ponteiro para o próximo node da lista. Se for o último node, ele aponta
	para NULL.

Esta estrutura representa um node da lista, ou seja, uma célula que armazena dados
e aponta para o próximo node.

typedef permite que, em vez de escrever struct s_list em todo o lado, possamos usar apenas t_list.

ft_lstadd_back: adiciona um novo node (new) no fim da linked list (lst).

	lst: é o ponteiro para o ponteiro que aponta para o ínicio da lista (o head da lista).
	     Ou seja, aponta para o head da lista.
	*lst: é o ponteiro que aponta para o primeiro node da lista.
	     Ou seja, é o próprio head da lista (é o primeiro node da lista).
	new: é o novo node que queremos adicionar à lista.

1 - Verificamos if (*lst == NULL) para ver se a lista está vazia, ou seja, se ainda não tem nenhum
    node.
	Se estiver vazia, atribuímos o novo node (new) ao ponteiro da lista (*lst): 

	*lst = new;

	Aqui, estamos a dizer que o novo node (new) torna-se o primeiro node da lista.
	Assim, o head da lista (*lst) agora aponta para o novo node (new).
	Ou seja, o novo node torna-se o primeiro e o único node da lista.

	Por outras palavras, atualizamos o ínicio da lista (o head) para apontar para o novo node.
	Se a lista estiver vazia, *lst (ou seja, o head da lista) é NULL.
	Então dizemos: " a lista agora começa com o novo node (new)".

	return ; -> saímos da função, pois já adicionámos o novo node. Não precisamos de fazer mais nada.
	A função termina aqui.

	Por que verificamos *lst == NULL?

    Porque, se a lista estiver vazia, não há “último node” onde ligar o new.
    Neste caso, o new é o primeiro e o último node da lista.

    Se não estivesse vazia, teríamos de percorrer a lista até ao último node e
	ligar esse último node ao new.

	Exemplo:

	t_list *lista = NULL;
	t_list *novo = ft_lstnew("42");

	ft_lstadd_back(&lista, novo);

	Antes da chamada:  lista → NULL

	Depois da chamada:  lista → [ "42" ] -> [ NULL ]

2 - Se a lista não estiver vazia, temos de percorrer a lista até ao último node.

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;

	tmp = *lst; - aqui vamos criar uma variável temporária que vamos utilizar para percorrer
				  a lista até ao fim sem alterar o ponteiro original da lista (*lst).
	              Assim, atribuímos o ponteiro tmp ao head da lista, pelo o que tmp
				  começa por apontar para o primeiro node da lista (*lst).

                  Porquê que não usamos diretamente *lst? 
				  
				  Pois não queremos alterar o ponteiro original da lista (*lst).
				  O ponteiro *lst aponta para o ínicio da lista. Ele é essencial porque:

				  1. Ele é a referência principal que usamos para saber onde começa a lista.
				  2. Se alterássemos *lst diretamente durante o percure, perderíamos o acesso
				     ao ínicio da lista.
				  
				  Assim, podemos usar tmp para percorrer a lista até ao fim sem perder o acesso
				  ao ínicio.

	while (tmp->next != NULL) - este while vai percorer os nodes da lista até encontrar o último (NULL).
	                            É como se perguntasse: "O tmp atual tem um próximo node na lista?"
								
    A condição tmp->next != NULL verifica se ainda não chegámos ao fim da lista.
	Significa: "Enquanto existir o próximo node, continuamos a andar para a frente."
	Ou seja, enquanto tmp->next apontar para o outro node, continuamos a avançar.
    Assim, se a lista tiver vários nodes, o tmp vai avançar até chegar ao último (aquele cujo next
	é NULL).

    tmp = tmp->next; - aqui movemos o ponteiro next para o próximo node, ou seja, estamos a avançar tmp para
	                   o próximo node da lista. Dizemos: "anda um passo para a frente na lista".
	                   Assim, tmp vai percorrer todos os nodes da lista até chegar ao último node (NULL).
                       Quando tmp->next for NULL, significa que tmp está a apontar para o último node da lista.

	Vamos imaginar uma lista com três elementos:

    tmp --> [nó1] -> [nó2] -> [nó3] -> NULL

    Passo a passo do while:

    1ª iteração: tmp está no [nó1]
                 tmp->next (o próximo) é [nó2], que não é NULL
                 Então tmp = tmp->next; → tmp agora aponta para [nó2]

    2ª iteração: tmp está no [nó2]
                 tmp->next (o próximo) é [nó3], que ainda não é NULL
                 Então tmp = tmp->next; → tmp agora aponta para [nó3]

    3ª iteração: tmp está no [nó3]
                 tmp->next (o próximo) é NULL → fim da lista!
                 O while termina.

    Agora tmp está no último nó da lista — e é exatamente aqui que queremos adicionar o novo nó
	com tmp->next = new;


	tmp->next = new -  aqui estamos a adicionar o novo node (new) ao final da lista, fazendo com que
	                   o ponteiro next do último node (tmp) aponte para o novo node (new).
					   Assim, o novo node passa a ser o novo último node da lista.

	                   Vejamos: O último node da lista (o que tmp está a apontar) agora aponta para o
					            novo node (new).
					            Ou seja, o ponteiro next do antigo último node aponta para o novo node (new).
					            Assim, o novo node (new) torna-se o último node da lista.
					            Logo, ligamos o último node da lista ao novo node (new).

	Porque usamos isso?

	Sem esta linha, o novo node new ficaria isolado na memória, sem ligação com a lista — ou seja, a lista 
	original não teria crescido. Esta ligação é essencial para manter a estrutura da linked list.

    Porque as linked lists não têm índice.
    Para encontrar o fim, é preciso de caminharmos node a node.
	

	Vamos supor que temos esta lista inicialmente:

    *lst → [ "A" ] → [ "B" ] → [ "C" ] -> [ NULL ]

    E queremos adicionar o "D" no fim.

	Etapas:

    tmp = *lst;
    → tmp aponta para "A"

    tmp->next != NULL → verdadeiro (B existe)
    tmp = tmp->next; → agora aponta para "B"

    tmp->next != NULL → verdadeiro (C existe)
    tmp = tmp->next; → agora aponta para "C"

    tmp->next != NULL → falso (C é o último)
    Sai do while

    tmp->next = new;
    → Ligamos "C" ao novo nó "D"

    Resultado final: *lst → [ "A" ] → [ "B" ] → [ "C" ] → [ "D" ] -> [ NULL ]




*/