void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*

Objetivo: A função ft_lstadd_front adiciona um novo nó (new) no início (head) da
          linked list (lst).
          Ou seja, em vez de adicionar o novo node ao fim (como ft_lstadd_back), este 
		  insere o novo node no topo da lista, fazendo com que ele se torne o novo primeiro
		  elemento (head).

Parâmetros:
 
- lst: É um ponteiro para o ponteiro que aponta para o início da lista.
       Ou seja, lst é um ponteiro para o head da lista.
       Permite-nos modificar o ponteiro original do head na função.

- *lst: É o head da lista: ou seja, o primeiro node atual da lista.

- new: É o novo node que queremos adicionar ao início da lista.

1 - Ligação do novo node ao antigo íncio da lista

    new->next = *lst;

	new->next refere-se ao ponteiro que indica o node seguinte ao novo node.
	Significa: "o próximo node depois de new é o antigo head da lista (*lst)".
	Ou seja, o node seguinte ao novo node (new) será o antigo head da lista (*lst).

    Aqui estamos a ligar o novo node ao antigo início da lista.
    Isto é: queremos que o novo node venha antes de tudo o que já existia na lista.

    Se *lst for NULL (ou seja, lista vazia), então new->next também será NULL — o que
	é perfeito, porque o novo node será o único elemento da lista.

    Se a lista já tiver elementos, então *lst aponta para o primeiro node atual da lista,
	e com esta linha fazemos: novo_node -> antigo_head

    Ou seja, estamos a colocar o new no ínicio da nova lista, sem perder a ligação com os
	nodes que já lá estavam e, assim, o novo node passa a apontar para o antigo primeiro 
	node da lista.

	Se não fizéssemos new->next = *lst;, o novo node "A" não apontaria para nada. Ou seja, 
	ele desligaria os nodes antigos da lista.

    Exemplo se não ligássemos:

    new → [ "A" ] → NULL   (isolado)
   *lst → [ "B" ] → [ "C" ] → NULL

    A seguir faríamos *lst = new, e então perderíamos o resto da lista:

    *lst → [ "A" ] → NULL   (B e C ficaram inacessíveis!)


2 - Atualização do head da lista

    *lst = new;

	Aqui estamos a atualizar o ponteiro do head da lista (*lst) para que ele passe a apontar
	para o novo node (new).
	Ou seja, agora o novo node é o primeiro node da lista.

	Se a lista estava vazia, agora ela tem um elemento (o novo node).
	Se a lista já tinha elementos, agora o novo node é o primeiro e os outros nodes continuam a 
	existir na lista.

	
Exemplo:

Vamos criar uma lista e adicionar elementos com ft_lstadd_front.

Situação inicial: t_list *lista = NULL;
                  Lista vazia: lista → NULL

Adicionamos o primeiro elemento

t_list *n1 = ft_lstnew("C");
ft_lstadd_front(&lista, n1);

Agora: new = n1
       *lst (ou seja, o head) era NULL
        new->next = *lst → new->next = NULL
       *lst = new → lista = n1

Resultado: lista → [ "C" ] → NULL

Adicionamos outro nó à frente

t_list *n2 = ft_lstnew("B");
ft_lstadd_front(&lista, n2);

Neste momento: new = n2
              *lst = n1 (aponta para "C")
               new->next = *lst → "B" aponta para "C"
              *lst = new → lista = n2

Resultado: lista → [ "B" ] → [ "C" ] → NULL

Adicionamos mais um nó

t_list *n3 = ft_lstnew("A");
ft_lstadd_front(&lista, n3);

Agora: "A" aponta para "B"
       *lst = n3

Resultado final: lista → [ "A" ] → [ "B" ] → [ "C" ] → NULL















*/