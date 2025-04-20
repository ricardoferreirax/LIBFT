char	*ft_strchr(const char *s, int c)
{
	int		idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}
	if ((char)c == '\0')
		return ((char *)(s + idx));
	return (NULL);
}

/*

SYNOPSIS
       #include <string.h>

       char *strchr(const char *s, int c);

DESCRIPTION
       The  strchr()  function returns a pointer to the first occurrence of the
       character c in the string s.

RETURN VALUE
       Returns a pointer to the matched character or NULL if the character is not found.
       If c is specified as '\0', the function returns a pointer to the null terminator.
       
Objetivo da ft_strchr: Procurar a primeira ocorrência do caractere c numa string s.
                       Se encontrar, retorna um ponteiro para essa posição da string.
                       Se não encontrar, retorna NULL.
					   Se c for '\0', retorna um ponteiro para o fim da string.

---------------------------------------------------------------------------------------------------------
1 - Parâmetros da função  -  char *ft_strchr(const char *s, int c);

1.1 - const char *s: é um ponteiro para o início da string onde a função irá procurar o caractere c.

					 O modificador `const` indica que os dados da string não devem ser modificados dentro
					 da função. Ou seja, podemos ler os caracteres da string, mas não podemos alterá-los.
					 Isto porque a função ft_strchr foi feita apenas para procurar um caractere numa string,
					 não para modificá-la.
					 Usar const é uma boa prática de proteger a memória que está a ser passada para a função.
					 Se const não fosse utilizado, a função teria permissão para modificar os dados apontados
					 por s, o que poderia causar erros graves ou comportamentos inesperados.

					  O que o const não faz?

                      const char *s não significa que s é um ponteiro constante — apenas os dados apontados por 
					  ele são constantes.

                      Ainda é possível fazermos s++ (ou seja, mover o ponteiro para o próximo caractere).
                      Podemos alterar o ponteiro, mas não o conteúdo:

					  const char *s = "Hello";
					  s = s + 1;        // válido → s agora aponta para "ello"
					  *s = 'A';         // inválido → tentativa de modificar conteúdo constante

                      Na função ft_strchr, a string s é lida caractere por caractere, mas nunca modificada.

                      A função lê os caracteres da string s um por um.
                      Compara com o caractere c.
                      Se encontrar, retorna um ponteiro para a posição correspondente.
                      Nunca altera s, nem os dados que ela aponta.

					  Apesar de s ser um const char *, a função retorna um char *  -  return ((char *)(s + idx));

                      Isto pode parecer estranho à primeira vista, mas faz sentido:

                         - A função retorna um ponteiro para uma posição dentro da string original, e pode ser 
						   usada para acessar a string a partir dali.

                         - O retorno é convertido para char * para manter a compatibilidade com as funções clássicas
						   de C, como a strchr, que retornam char *.

                        Importante: Embora o tipo de retorno seja char *, o conteúdo ainda não deve ser modificado se
						a string original for constante.

1.2 - int c: representa o caractere que estamos a procurar na string s.

			 Mesmo que c seja um `int`, a função vai convertê-lo  para um`char`, pois nós vamos comparar a variável c
			 com elementos de um array de caracteres, ou seja, com uma string composta por `chars`.
             Se não fizessemos esta conversão, poderiamos acabar por comparar um valor int (fora do intervalo de um char
			 por exemplo, -1 ou 256) com um char, o que causaria resultados errados ou inconsistentes.

			 Assim, o cast é necessário: para garantir que estamos a comparar dois valores do mesmo tipo (char).
			 
			 Dentro da função ft_strchr  -  if (s[idx] == (char)c)

             Estamos a dizer: “Compara o caractere da string com o valor de c como se fosse um char.”

             Isto evita: - Warnings de compilador.
			             - Comportamento indefinido.
                         - Comparações incorretas se c estiver fora do intervalo de um char.


2 - Compreender a Implementação

2.1 - Loop para procurar o caractere:

	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx++;
	}

	Este loop percorre cada caractere da string s até encontrar o caractere c (que está a ser procurado) ou 
	até chegar ao final da string ('\0').

	if (s[idx] == (char)c): Verificamos se o caractere atual da string é igual ao caractere que estamos à 
	                        procura.

    return ((char *)(s + idx)): Se for, retornamos um ponteiro para o caractere encontrado dentro da string.
                                
	                            > s + idx → ponteiro para a posição onde encontramos o caractere.
                                > (char *)(s + idx) → conversão para char *, pois s é const char * e a função
								está à espera de retornarmos um char *.

								O resultado é um ponteiro que aponta para o restante da string, a começar na 
								ocorrência encontrada.

                                Exemplo: Se s = "42 Lisboa" e c = 'L':

                                s[3] == 'L'

                                Então s + 3 aponta para "Lisboa"

                                return (char *)(s + 3); retorna ponteiro para "Lisboa"

    Avançamos o índice para o próximo caractere da string (idx++).

2.2 - Verificação final para '\0':

	if ((char)c == '\0')
		return ((char *)(s + idx));

	Este if acontece após o loop while, ou seja, só é executado se o caractere c que estamos à procura não
	foi encontrado dentro da string. 
	Aqui, vamos verificar se o caractere que estamos à procura é o caractere nulo.
	Se estivermos à procura do '\0', então ele estará exatamente na posição `s[idx]` (onde `s[idx] == '\0'`
	fez o loop anterior parar).

	Aqui fazemos à mesma a conversão para char, pois vamos comparar c com '\0', que é um char, de modo a 
	evitarmos qualquer problema de comparação de tipos.

	return ((char *)(s + idx)): Como o loop parou no momento s[idx] == '\0' então s + idx aponta exatamente
	                            para o '\0' final da string.

                                Assim, vamos retornar um ponteiro para o '\0', convertendo-o para char *, pois
								s é const char * e a função stá à espera de retornarmos um char *.

	                            Assim, retornamos um ponteiro para o fim da string (o `\0`).

2.3 - Retorno caso o caractere não seja encontrado:

	return (NULL);

	Se o caractere `c` não for encontrado, e também não for o caractere nulo, retornamos NULL, indicando que
	a procura pelo caractere falhou.

3 - Considerações de Segurança e Utilização

- A função só deve ser usada com strings corretamente terminadas por `'\0'`.
- Ideal para encontrar a primeira ocorrência de um caractere.
- Útil em parsing de strings, validação de entrada, manipulação de texto, etc.
- Ao contrário de `strrchr`, que encontra a última ocorrência, `strchr` para na primeira.
- Retornar ponteiro para `'\0'` é um comportamento importante — permite saber onde a string termina.


*/