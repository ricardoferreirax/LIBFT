int	ft_memcmp(const void *s1, const void *s2, size_t n) // Início da função. Compara n bytes das áreas de memória s1 e s2.
{
	size_t				idx;			// Índice para percorrer os bytes, começa em 0 e vai até n-1.
	const unsigned char		*tmp_s1;	// Ponteiro temporário para os bytes de s1, convertido para unsigned char.
	const unsigned char		*tmp_s2;	// Ponteiro temporário para os bytes de s2, convertido para unsigned char.

	if (n == 0)							// Verifica se não há bytes para comparar.
		return (0);						// Se n for 0, retorna 0 imediatamente (blocos vazios são considerados iguais).

	tmp_s1 = (const unsigned char *)s1;	// Faz cast de s1 (void *) para const unsigned char *, para comparar byte a byte.
	tmp_s2 = (const unsigned char *)s2;	// Faz cast de s2 (void *) para const unsigned char *, mesma lógica.

	idx = 0;							// Inicializa o índice para começar a comparação do primeiro byte (posição 0).

	while (tmp_s1[idx] == tmp_s2[idx]	// Enquanto os bytes forem iguais...
		&& idx < n - 1)				// ... e ainda não for o último byte (idx vai até n - 1)...
		idx++;							// Avança para o próximo byte.

	return (tmp_s1[idx] - tmp_s2[idx]);	// Retorna a diferença entre os bytes onde houve a primeira diferença.
										// Se todos forem iguais, retorna 0. Caso contrário, retorna valor positivo ou negativo.
}

/*
SYNOPSIS
       #include <string.h>

       int memcmp(const void s1[.n], const void s2[.n], size_t n);

DESCRIPTION
       The  memcmp()  function  compares the first n bytes (each interpreted as
       unsigned char) of the memory areas s1 and s2.

RETURN VALUE
       The memcmp() function returns an integer less than, equal to, or greater
       than zero if the first n bytes of s1 is found, respectively, to be  less
       than, to match, or be greater than the first n bytes of s2.

       For  a  nonzero  return value, the sign is determined by the sign of the
       difference between the first pair  of  bytes  (interpreted  as  unsigned
       char) that differ in s1 and s2.

       If n is zero, the return value is zero.


Objetivo da ft_memcmp: Compara os primeiros n bytes de dois blocos de memória (s1 e s2) 
                       byte a byte, e indicar se são iguais ou qual é o primeiro byte em que
					   diferem e retornar a diferença entre eles (qual é o maior com base no
					   valor dos bytes).

1 - Parâmetros da função  -  int ft_memcmp(const void *s1, const void *s2, size_t n);

1.1 - const void *s1: é o ponteiro para o primeiro bloco de memória a ser comparado.
                      O tipo void * permite que esse ponteiro aponte para qualquer tipo de dado,
					  tornando a função genérica e reutilizável para diversos tipos de dados.
                      O modificador const garante que os dados apontados por s1 não serão modificados
					  durante a execução da função, apenas serão lidos para compará-los.
					  Isso aumenta a segurança da função, evitando alterações indesejadas na memória.
					  Como não é possível acessarmos diretamente aos dados de um ponteiro void (pois o
					  compilador não sabe o tamanho nem o tipo dos dados para fazer a desreferenciação)
					  é necessário fazer a conversão do ponteiro para um tipo de dado específico, que
					  neste caso, o ponteiro será convertido para const unsigned char *, já que a comparação
					  será feita byte a byte. O tipo unsigned char é utilizado para representar um único byte
					  (8 bits) com valores entre 0 e 255, o que é ideal para comparação de bytes.
					  
					  Exemplo: Se s1 for um ponteiro para um array de inteiros, a função ft_memcmp pode ser
					           usada para comparar os primeiros n bytes do array.

1.2 - const void *s2: é o ponteiro para o segundo bloco de memória a ser comparado.
                      Assim como o parâmetro s1, o modificador const impede a modificação dos dados de s2. 
					  A conversão também ocorre para const unsigned char *, permitindo o acesso e a comparação
					  dos dados byte a byte.

1.3 - size_t n: Representa o número de bytes a serem comparados a partir de s1 e s2. Ele indica-nos quantos bytes
			    da memória devem ser comparados.
                O tipo size_t é utilizado para armazenar e representar tamanhos de memória de forma segura e portável,
				pois é sempre positivo e suficientemente grande para representar qualqur tamanho de memória válido.

				Ele é definido em <stddef.h> e <stdio.h> como um alias (typedef) de um tipo interno, normalmente:

    				- unsigned int em sistemas de 32 bits
					- unsigned long ou unsigned long long em sistemas de 64 bits

				Isso depende da arquitetura do sistema.

				Por que usar size_t em vez de int?
                
			         	   Motivo	                                              Explicação
                      Sempre positivo	                 Não existe "tamanho negativo". size_t evita erros como n = -1.
                 Representa corretamente o tamanho	     size_t consegue representar todos os tamanhos possíveis da memória.
                  Compatível com funções da Libc	         A maioria das funções de memória e string usam size_t como padrão.

                A função compara os primeiros n bytes de s1 e s2 (de 0 até n - 1) ou até encontrar a primeira diferença,
				o que ocorrer primeiro.

2 - Compreensão da Implementação:

2.1 - Conversão dos Ponteiros

    Os ponteiros auxiliares tmp_s1 e tmp_s2 são criados para podermos acessar os bytes de s1 e s2, que originalmente
	sao do tipo const void *. 
	Como originalmente os ponteiros s1 e s2 são do tipo void *, eles apontam para qualquer tipo de dado, mas não podemos
	desreferenciá-los diretamente, ou seja, não podemos acessá-los diretamente como se fossem arrays de bytes (por exemplo,
	s1[0], s1[1], etc.).
	Para poder percorrer a memória byte a byte, precisamos de converter os ponteiros para um tipo que tenha tamanho
	equivalente a um byte - esse tipo é o const unsigned char.

	Por que const? Porque os dados originais (s1 e s2) são const void * → ou seja, não podem ser modificados.
                   O cast mantém o const, para garantir que esses ponteiros apenas leem os dados da memória.
                   Isto aumenta a segurança e a clareza do código: estamos apenas a comparar, não a alterar.


	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;

	Aqui, tmp_s1 e tmp_s2 passam a apontar para os mesmos dados de memória que s1 e s2, agora com o tipo const unsigned char *,
	permitindo o acesso byte a byte. Essas duas variáveis temporárias são utilizadas para acessar os dados de s1 e s2 byte a
	byte de forma segura e eficiente. Não criamos uma cópia da memória, só alteramos a forma como acessamos os dados.
	A função compara os blocos de memória byte a byte, e para isso, é necessário usar unsigned char, que representa
	um único byte (8 bits) com valores entre 0 e 255.

2.2 - Loop de Comparação

	  while (tmp_s1[idx] == tmp_s2[idx] && idx < n - 1)
      	idx++;

	  O loop while percorre os bytes dos dois blocos de memória apontados por tmp_s1 e tmp_s2, enquanto eles forem iguais e 
	  não tenhamos verificado todos os n bytes.

      tmp_s1[idx] == tmp_s2[idx]: Verifica se o byte atual dos dois blocos é igual.
								  OU seja, A função só deve continuar se os valores forem iguais naquele índice.

	  O loop percorre os blocos de memória comparando os bytes de tmp_s1 e tmp_s2 até encontrar uma diferença ou até percorrer
	  os n primeiros bytes de cada bloco.
	  Se os bytes forem iguais, o índice (idx) é incrementado. 
	  Caso contrário, a comparação é interrompida, e a função retorna a diferença entre os bytes que são diferentes. 
	  O loop garante que a comparação não ultrapasse o limite de n - 1, para evitar acessar dados fora da área da memória.

2.3 - Retorno da Função

    return (tmp_s1[idx] - tmp_s2[idx]);

    Quando o laço termina, significa que foi encontrada uma diferença entre os blocos de memória, ou todos os bytes foram
	comparados. A função então retorna a diferença entre o primeiro byte diferente encontrado.
    Se não houver diferença entre os primeiros n bytes, a função retorna 0, indicando que os blocos de memória são iguais.


	NOTES:

        - If `ptr1[i]` is different from `ptr2[i]`, the function returns `ptr1[i] - ptr2[i]`, which gives:
        
            - A NEGATIVE value if `ptr1[i]` is smaller than `ptr2[i]`.
            - ZERO if both bytes are equal.
            - A POSITIVE value if `ptr1[i]` is greater than `ptr2[i]`.
            
        - If all `n` bytes are equal, the function returns `0`.

    Handling Edge Cases:

    - If `n == 0`, the function returns `0` immediately, since there is nothing to compare.
    - If `s1` or `s2` is `NULL`, behavior is undefined (standard implementations do not check for `NULL`).
    - The function does NOT stop at the first null byte (`\0`), as it treats memory as a raw block, not a string.

    Example Usage:

    1 - Suppose we have the following code:

        char str1[] = "Hello, World!";
        char str2[] = "Hello, world!";

        int result = ft_memcmp(str1, str2, 13);

        if (result < 0)
            printf("str1 is less than str2\n");
        else if (result > 0)
            printf("str1 is greater than str2\n");
        else
            printf("str1 and str2 are equal\n");

    **Memory representation of `str1` and `str2`:**

        str1: [H] [e] [l] [l] [o] [,] [ ] [W] [o] [r] [l] [d] [!]
        str2: [H] [e] [l] [l] [o] [,] [ ] [w] [o] [r] [l] [d] [!]

    - The function compares each byte until it finds `'W'` (ASCII `87`) in `str1` and `'w'` (ASCII `119`) in `str2`.
    - Since `87 - 119 = -32`, `ft_memcmp` returns a negative value, meaning `str1` is "less than" `str2`.

    2 - Suppose we have the following code:

        char str1[] = "hello";
        char str2[] = "hellz";

        int result = ft_memcmp(str1, str2, 5);

    **Memory comparison:**
    
    str1:  h  e  l  l  o  
            │  │  │  │  └── 'o' (111)  
            │  │  │  │      ≠  
            │  │  │  │      'z' (122)  
    str2:  h  e  l  l  z  

    Since `'o'` (111 in ASCII) is less than `'z'` (122),  
    `ft_memcmp` returns a negative value.

    The function efficiently determines whether two memory blocks are identical or which one is greater if they differ.
*/


















*/