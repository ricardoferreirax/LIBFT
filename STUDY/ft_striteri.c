void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;

	if (!s || !f)
		return ;
	idx = 0;
	while (s[idx] != '\0')
	{
		f(idx, s + idx);
		idx++;
	}
}

/*

Objetivo: A função ft_striteri percorre uma string e aplica, a cada caractere dela, uma função
fornecida pelo utilizador. Esta função pode modificar o conteúdo da string, pois recebe um 
ponteiro direto para cada caractere.
A função ft_striteri vai modificar a string original, caractere a caractere, com base numa
função externa.
É útil quando precisamos de alterar a string original com base no índice de cada caractere.

> ft_striteri recebe uma string s e uma função f.
> A cada caractere s[i], chama f(i, &s[i]).
> A função f tem permissão para modificar s[i] diretamente, porque recebe um ponteiro para o
  caractere original.
> Isto é feito até chegarmos ao final da string.



1 - Parâmetros da função  -  void ft_striteri(char *s, void (*f)(unsigned int, char *))

    char *s: variável que aponta para a string que desejamos modificar ou processar. 
	         Utilizamos um ponteiro para a string em vez de passar a string como uma cópia
			 por valor, porque em C as strings são manipuladas através dos ponteiros.
			 Isto permite que a função altere diretamente os caracteres da string original,
			 sem a necessidade de criar cópias.
			 COmo s é um ponteiro para o primeiro caractere da string, se alterássemos o valor
			 de *s, isso iria alterar o primeiro caractere da string, ou seja, s[0] assumiria
			 outro valor.
	         Assim, como ele é um ponteiro e não uma cópia da string, qualquer modificação em s
			 dentro da função vai afetar diretamente a string original fora da função.

			 Dentro da função ft_striteri, o ponteiro s é utilizado para acessar diretamente cada
			 caractere da string. QUando a função percorre a string, ela faz isso através do índice,
			 e s[idx] acessa cada caractere da string. 
			 s + idx devolve o endereço de memória do caractere atual da string (ou seja, o ponteiro
			 para esse caractere), o que significa que a função pode modificar diretamente o conteúdo
			 de s.

             Assim, s é a string que será modificada caractere a caractere.
             É uma string mutável (não const), porque a função f vai alterar os caracteres.

    void (*f)(unsigned int, char *): é o ponteiro para a função que será chamada em cada repetição do
	                                 loop, que vai passar o índice idx e o endereço do caractere atual 
									 (s + idx) para cada caractere da string.

	Ponteiro para uma função: Em C, podemos ter variáveis que não apenas armazenam dados, mas
	também apontam para funções. Isto permite que possamos passar funções como argumentos para
	outra funções.

	O uso de um ponteiro para uma função em ft_striteri tem uma vantagem significativa: flexibilidade.
	O ponteiro f permite que passemos qualquer função sem precisarmos de modificar a implementação de ft_striteri.

    Por exemplo, em vez de forçar a função ft_striteri a sempre alterar os caracteres para maiúsculas,
	podemos passar diferentes funções para realizar outras operações, como: - Converter para minúsculas.
                                                                            - Imprimir o caractere na tela.
                                                                            - Alterar o caractere com base em um 
																			  critério específico.
    
    Neste caso, o ponteiro f aponta para uma função do tipo void f(unsigned int, char *), ou seja:

	  - f é um ponteiro que aponta para uma função que aceita um parâmetro do tipo unsigned int e
	  um parâmetro do tipo char * e não retorna nada, pois é do tipo void.

    Assim, a função f é chamada para cada caractere da string, e vai modificá-lo diretamente, um a um.

    O ponto chave aqui é que a função ft_striteri não precisa de saber o que a função f faz. Ela apenas a chama, 
	e passa os parâmetros necessários. A função f pode ser uma qualquer função que aceite um unsigned int (índice) 
	e um char * (ponteiro para caractere) como argumentos, permitindo uma grande flexibilidade.


2 - Compreender o código:

2.1 - Aplicar a função f a cada caractere da string s

	while (s[idx] != '\0')
	{
		f(idx, s + idx);
		idx++;
	}

	O loop vai percorrer todos os caracteres da string s, um por um, aplicando a ação da função f a cada
	um desses caracteres.

	f(idx, s + idx): Chamamos a funçaõ f, passando o índice atual e um ponteiro para o caractere atual
	                 da string.
					 A função passada como argumento vai poder saber onde está na string (através do índice)
					 e modificar diretamente o caractere (porque recebe o endereço dele).
    
	 Exemplo: Suponhamos que a função f:

			  void colocar_maiuscula(unsigned int i, char *c)
			  {
			  	    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		            *c = *c - 32;
              }

              E chamamos:  char str[] = "exemplo";
                           ft_striteri(str, colocar_maiuscula);

              Resultado:  índice 0: 'e' → maiúscula: 'E'
                          índice 1: 'x' → não muda
                          índice 2: 'e' → 'E'
                          índice 3: 'm' → não muda
                                    ...

              Resultado final: "ExEmPlO"

              Ou seja, a função f foi aplicada a cada letra, de acordo com a posição dela na string.


*/