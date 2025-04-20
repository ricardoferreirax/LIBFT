char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	idx = 0;
	while (s[idx] != '\0')
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

/*

A função ft_strmapi aplica uma função f a cada caractere da string s, passando o índice do
caractere e o próprio caractere como parâmetros. O resultado da aplicação de f é armazenado
numa nova string, que é alocada dinamicamente. Essa nova string é então retornada.
A função não altera a string original — apenas lê os seus valores e cria uma nova string 
modificada.

1 - Parâmetros da função  -  char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

1.1 - char const *s: é a string sobre a qual a função f será aplicada, caractere a caractere.
                     O modificador const indica que a função não deve modificar os dados originais
					 de s.
					 A função ft_strmapi percorre a string s original para criar uma nova (alocada
					 dinamicamente) em que f vai atuar e modificar essa nova string e que será
					 retornada, sem modificar a original. 
					 É algo como: "Recebo uma string de entrada, leio os caracteres um por um, 
					 mas não altero o conteúdo original. Crio e devolvo uma nova string modificada."
					
1.2 - char (*f)(unsigned int, char): é o ponteiro para uma função que vai modificar cada caractere
                                     da string s de acordo com o índice em que ele está.
									 A variável f vai aplicar uma modificação nos caracteres da
									 string de forma personalizada (de acordo com a execução
									 da função passada como argumento). 

									 f é um ponteiro para uma função que recebe dois argumentos:

                                     - um índice (unsigned int) correspondente à posição do caractere 
									   na string original,
                                     - um caractere (char) da string original.

                                     A função f deve retornar um char, que será armazenado na nova string 
									 resultante.

									 Dentro de ft_strmapi, a função faz o seguinte:

                                     > A função ft_strmapi percorre a string s, caractere a caractere.
                                     > Para cada caractere, ela chama a função f, passando o índice atual 
									   e o caractere da posição.
                                     > A função f recebe esses dois parâmetros e retorna um novo caractere 
									   (que pode ser o mesmo ou modificado).
                                     > O novo caractere retornado por f é armazenado na nova string que 
									   está a ser criada.

3 - Compreender a Implementação

3.1 - Alocação de memória

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);

	char *str: A função ft_strmapi vai criar uma nova string a partir da string s, aplicando uma 
	           modificação nos caracteres dessa string. A nova string será armazenada em str. 
			   A memória para essa nova string é alocada dinamicamente. 
	           A variável str aponta para a memória onde a nova string alocada dinamicamente será 
			   armazenada, e cada caractere transformado será colocado lá dentro. 
	           A string str vai ser utilizada para construir a nova string, pois à medida que a 
			   função percorre a string original s, ela chama a função f e armazena os resultados 
			   na string str. 

    Aqui vamos alocar dinamicamente memória suficiente para armazenar a string s (com todos os seus
	caracteres) mais o caractere nulo '\0'. Esta nova string alocada, tem o mesmo tamanho que a string
	s (mais 1 para o \0 final) e será armazenada na string str. 

3.2 - Transformação dos caracteres

	while (s[idx] != '\0')
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}

    Vamos percorrer cada caractere da string original de s, aplicando a modificação da função f a cada
	caractere dessa string e armazenar o resultado na nova string str. 

    f(idx, s[idx]) é uma função que recebe dois parâmetros: 
	  
	   > idx: o índice do caractere atual da string s. Este índice é útil para a função f, pois
	   ela precisa de saber em que posição vai modificar o caractere. 
       > s[idx]: o caractere da string original s na posição idx. Esse é o caractere que será modificado.

	Atribuição str[idx] = f(idx, s[idx]): Agora, f(idx, s[idx]) dá-nos um novo caractere que será armazenado 
	                                      na posição correspondente da nova string str.
                                          Portanto, str[idx] = f(idx, s[idx]) coloca esse caractere modificado
										  na posição idx de str.

    A função f retorna um novo caractere com base no índice e no caractere original. 
	O comportamento de f depende da lógica implementada dentro da função chamada.

	Por exemplo: Se o caractere é uma letra minúscula (por exemplo, 'a'), f pode convertê-lo em
	             maiúsculo (retornando 'A').
                 Se o caractere não é uma letra minúscula, f pode simplesmente retornar o mesmo
				 caractere.

3.3 - Finalização da nova string - str[idx] = '\0':

      Após o loop, colocamos o caractere nulo (\0) no final da nova string para garantir que ela seja válida.






*/