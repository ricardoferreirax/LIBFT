char	*ft_strdup(const char *s)
{
	char	*dest;
	int		idx;

	idx = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[idx] != '\0')
	{
		dest[idx] = s[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

/*

/*
SYNOPSIS
       #include <string.h>

       char *strdup(const char *s);

DESCRIPTION
       A função strdup() aloca memória suficiente para duplicar a string s,
       copia o conteúdo de s para essa nova área de memória e retorna um ponteiro para ela.

RETURN VALUE
       Em caso de sucesso, retorna um ponteiro para a nova string duplicada.
       Se a alocação de memória falhar, retorna NULL.



Objetivo: A função ft_strdup tem como objetivo duplicar uma string, começando por criar uma nova
cópia exata da string original, com a sua própria área de memória e retornar um ponteiro para essa 
nova string, que é independente da original.

1 - Parâmetros da função

1.1 - const char *s: É um ponteiro para uma string original que queremos duplicar.

                     O modificador `const` indica que os dados da string não devem ser modificados dentro
					 da função. Ou seja, podemos ler os caracteres da string, mas não podemos alterá-los.

                     Na função ft_strdup, a string original não deve ser alterada, apenas copiada.
					 Garante que a função não vai modificar a string recebida, o que vai tornar o código
					 mais seguro, evitando modificações acidentais.

					 Se const não fosse utilizado, a função teria permissão para modificar os dados apontados
					 por s, o que poderia causar erros graves ou comportamentos inesperados.

					  O que o const não faz?

                      const char *s não significa que s é um ponteiro constante — apenas os dados apontados por 
					  ele são constantes.

                      Ainda é possível fazermos s++ (ou seja, mover o ponteiro para o próximo caractere).
                      Podemos alterar o ponteiro, mas não o conteúdo:


2 - Compreender a implementação

	Variáveis:

	char *dest: ponteiro que aponta para o ínicio da área de memória onde será armazenada a cópia da 
	            string original.
				A função precisa de guardar a cópia da string, e é no array dest que a nova string será
				copiada.
				O array dest é o local onde cada caractere da string original será copiado um por um.

2.1 - Alocação dinâmica de memória  - dest = malloc((ft_strlen(s) + 1) * sizeof(char));

      Aqui vamos alocar dinamicamente memória para armazenar a cópia da string s.

	  A função malloc aloca uma área de memória na heap com o número de bytes que especificar-mos.

	  ft_strlen(s): esta função devolve o número de caracteres da string (ou seja, o tamanho da string 
	  original) sem contar o caractere nulo '\0'.       
    
      Por que ft_strlen(s) + 1? Porque precisamos de alocar espaço para todos os caracteres da string
	  mais o caractere nulo, para terminar validamente a string.
    
      Multiplicamos por sizeof(char) para calcular o número total de bytes necessários para armazenar a
	  nova string (incluindo o caractere nulo).

	  No fim, dest passa a apontar para a nova àrea da memória onde vamos copiar a string original.


2.2 - Cópia da string original

      while (s[idx] != '\0')
	  {
	     dest[idx] = s[idx];
	     idx++;
      }
	  dest[idx] = '\0';

      Aqui, vamos copiar o conteúdo da string original s para a string recém-alocada dest, caractere a 
	  caractere, até chegar ao final da string '\0'.

    A cópia acontece enquanto não chegarmos ao caractere \0 da string.

    s[idx] é o caractere da string original.
    dest[idx] recebe o mesmo valor.

    O índice idx vai avançando até o final da string.

    Exemplo: Se s = "42":

        s[0] = '4' → dest[0] = '4'
        s[1] = '2' → dest[1] = '2'
        s[2] = '\0' → saímos do while

	dest[idx] = '\0': Depois de copiar os caracteres, precisamos de terminar a nova string com \0.
    Isto garante que a string dest seja válida e reconhecida corretamente pelas funções em C.



























*/





















*/