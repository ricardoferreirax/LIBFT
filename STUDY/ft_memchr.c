void	*ft_memchr(const void *s, int c, size_t n) // Início da função. Procura a primeira ocorrência do byte 'c' nos primeiros 'n' bytes de 's'.
{
	const unsigned char	*tmp_s;	// Ponteiro temporário para acessar os bytes da memória como unsigned char (de 0 a 255).
	size_t				idx;	// Índice usado para percorrer a memória, byte a byte.

	tmp_s = (const unsigned char *)s;	// Converte o ponteiro genérico 's' para ponteiro de unsigned char, pois vamos trabalhar byte a byte.
	idx = 0;							// Inicializa o índice com 0 (início da área de memória).

	while (idx < n)					// Enquanto ainda estivermos dentro do limite de 'n' bytes...
	{
		if (tmp_s[idx] == (unsigned char)c)		// Se o byte atual for igual ao valor procurado (c convertido para unsigned char)...
			return ((void *)(tmp_s + idx));		// Retorna um ponteiro para a posição onde o byte foi encontrado (cast para void *).
		idx++;									// Se não encontrou ainda, avança para o próximo byte.
	}
	return (NULL);	// Se percorreu os n bytes e não encontrou o valor, retorna NULL (valor não encontrado).
}



/*
SYNOPSIS
       #include <string.h>

       void *memchr(const void s[.n], int c, size_t n);

DESCRIPTION
       The  memchr()  function  scans  the  initial  n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and  the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.

RETURN VALUE
       The memchr() return a pointer  to  the  matching
       byte or NULL if the character does not occur in the given memory area.


Objetivo da ft_memchr: Procurar a primeira ocorrência de um byte específico (c) nos primeiros n bytes da
                       memória apontada por s.

1 - Parâmetros da função  -  void *ft_memchr(const void *s, int c, size_t n);

1.1 - const void *s: é o ponteiro genérico para a àrea de memória onde queremos procurar o byte c.
					 A variável s aponta para o ínicio da memória onde a função vai procurar um byte especifico.
                     O tipo void * permite que o ponteiro aponte para qualquer tipo de dado.
					 A razão de *s ser genérico é porque a função memchr foi feita para ser genérica, ou seja,
					 pode ser usada para qualquer tipo de dado, seja um array de char, int, ou qualquer outro tipo.
                     
					 O modificador const indica que os dados apontados por s não serão modificado dentro
					 da função. A função apenas lê os dados da memória.
					 Se a função ft_memchr não tivesse o const, isso permitira que a função modificasse os dados
					 apontados por s, o que seria perigoso, pois a função não foi projetada para modificar os dados.
					 A função deve apenas procurar o byte c e retornar um ponteiro para a primeira ocorrência, e não
					 modificar a memória.
					 Assim, o const serve como garantia de segurança, tanto para o programador como para o compilador.

                     Como o tipo é void * e não pode ser desreferenciado diretamente (não sabemos o tamanho dos dados) 
					 precisamos de fazer um cast para um tipo específico (como unsigned char *) para podermos acessar os 
					 dados corretamente.

					 Exemplo: Se s for um ponteiro para um array de char, ft_memchr pode ser usada para 
					          encontrar a primeira ocorrência de um caractere nesse array.

					 Na conversão: const unsigned char *tmp_s = (const unsigned char *)s;

                     É convertido para const unsigned char * porque a função trabalha byte a byte, e unsigned char tem
					 exatamente 1 byte (8 bits). unsigned evita problemas com valores negativos. 
					 Por exemplo, um byte com valor 255 seria -1 se fosse signed char, o que causaria confusão.

                    
1.2 - int c: Este é o valor que queremos procurar na memória.
			 Mesmo sendo declarado como int, ele será convertido internamente para unsigned char, pois a função
			 opera byte a byte.

			 o que é um unsigned char? unsigned char é um byte (8 bits), mas sem sinal (ou seja, só valores positivos).
									  Pode armazenar valores de 0 até 255.
									  Já um char comum pode ser com sinal: Se for signed char, vai de -128 a 127.
									                                       Se for unsigned char, vai de 0 a 255.

		    O problema: int c pode ser negativo !
			A função ft_memchr recebe o caractere a procurar como um int, mas a comparação dentro da função é feita 
			com bytes da memória — ou seja, com unsigned char.

			Se c for negativo, a comparação não funcionará corretamente, pois o valor negativo não pode ser representado
			como um byte (unsigned char). Por isso, a função converte c para unsigned char antes de fazer a comparação.
			Isso garante que a comparação seja feita corretamente, mesmo que c seja negativo.

			Na prática, isso significa que a função ft_memchr vai ignorar o sinal de c e considerar apenas o valor
			absoluto dele, ou seja, o valor positivo correspondente.
			Se c for maior que 255, o valor será reduzido para o intervalo de 0 a 255 usando a operação de módulo (%).
			Isso é feito porque o tipo unsigned char só pode armazenar valores entre 0 e 255.

			Assim, se c for maior que 255, a função vai fazer c % 256 para obter o valor correto.
			Por exemplo, se c for 300, a função vai considerar apenas o valor 44 (porque 300 % 256 = 44).

			Isso é importante porque a função ft_memchr foi projetada para trabalhar com bytes de memória, e
			um byte só pode armazenar valores entre 0 e 255.
			
			Isso significa que apenas o byte menos significativo (valores entre 0 e 255) de c será considerado.

1.3 - size_t n: representa o número de bytes a serem lidos a partir do ponteiro s.
				O tipo size_t é usado porque ele é adequado para expressar tamanhos de memória, de forma portável
				e segura e garante que o valor da quantidade de bytes a serem lidos seja sempre positivo.

                Na prática, size_t é um apelido (typedef) para unsigned int ou unsigned long, dependendo da arquitetura
				do sistema (32 ou 64 bits).

                A função vai verificar até n bytes, ou até encontrar o valor c, o que ocorrer primeiro.

				 Por que não usamos int n?

				Porque: int tem sinal e pode receber valores negativos, o que não faz sentido para tamanho de memória 
				(não existe "menos 5 bytes").
				        int pode não ser grande o suficiente para representar todos os tamanhos possíveis (em sistemas 64 bits,
						por exemplo).

2 - Compreender a Implementação

2.1 - Conversão do Ponteiro

	const unsigned char *tmp_s;
	tmp_s = (const unsigned char *)s;

	const unsigned char *tmp_s: Declara um ponteiro para unsigned char, que é usado para acessar os bytes da memória.
	                            Ele vai apontar para os dados do tipo unsigned char constantes.
	                            O tipo unsigned char é usado porque a função vai trabalhar com bytes de memória, e cada
								byte é representado por um unsigned char (8 bits).
								Os dados apontados não podem ser modificados por esse ponteiro, já que é um ponteiro
								constante (const unsigned char *).

    A função começa a converter s (do tipo const void *) para const unsigned char *.
    A conversão é necessária porque não podemos indexar ou acessar diretamente um void *.
    unsigned char é usado porque queremos ler byte a byte, e este tipo representa um único byte (0 a 255).
    O modificador const é mantido porque a função não modifica a memória apontada.

    Agora, com a conversão, permite-nos percorrer/acessar os bytes de indíce idx na memória ao utilizar tmp_s[idx] e 
	comparar com (unsigned char)c.

	
2.2 - Laço de Busca

	while (idx < n)
	{	
		if (tmp_s[idx] == (unsigned char)c)
			return ((void *)(tmp_s + idx));
		idx++;
	}

    Este while percorre os bytes de memória até encontrar o valor c ou até percorrer os n bytes do início
	(idx = 0) até idx = n - 1.
	A comparação é feita com (unsigned char)c para garantir que estamos a comparar os bytes corretamente.
	Isso é importante porque c pode ser um int, e queremos comparar apenas o byte correspondente.
    Assim, a cada iteração, verificamos se o byte atual (tmp_s[idx]) é igual a c, convertido para unsigned char.

    Se for encontrado, a função retorna um ponteiro para a posição onde a primeira ocorrência do valor (byte)
	foi encontrado.
    A conversão (void *)(tmp_s + idx) retorna um ponteiro genérico, como exigido pelo protótipo da função.
	O tmp_s + idx é um ponteiro para a posição onde o byte foi encontrado.
	(void *) faz um cast para void * porque a função está à espera de um retorno de um ponteiro genérico, e tmp_s
	é um ponteiro para unsigned char. O cast é necessário para garantir que o tipo de retorno seja compatível
	com o protótipo da função.

	Exemplo:

	Digamos que temos o seguinte array: char arr[] = {72, 101, 108, 108, 111}; // corresponde à string "Hello"

	E fazemos: ft_memchr(arr, 108, 5); // Procurar o byte 108 (letra 'l') nos 5 primeiros bytes

	Na função:   const unsigned char *tmp_s;
                 tmp_s = (const unsigned char *)s;

    s é const void * → ou seja, um ponteiro genérico para o início de arr
    Fazemos o cast para const unsigned char *, assim:  tmp_s = (const unsigned char *)s;

    Agora podemos fazer: if (tmp_s[i] == (unsigned char)c)

    E comparar byte por byte.

	Assim :

	s → aponta para arr → {72, 101, 108, 108, 111}
                            ↑    ↑
                            H    e
                            ...

	Depois do cast: tmp_s[0] == 72   → 'H'
                    tmp_s[1] == 101  → 'e'
                    tmp_s[2] == 108  → 'l'

    Se c == 108, então: tmp_s[2] == (unsigned char)c  → condição verdadeira

	arr: {'H', 'e', 'l', 'l', 'o'}
           ↑    ↑    ↑
           0    1    2 ← encontramos 'l'

	return ((void *)(tmp_s + 2));

	Imprimirmos "llo".


2.3 - Retorno se Nada for Encontrado

return (NULL);

    Se o laço termina sem encontrar o valor, a função retorna NULL.
    Isso indica que o valor c não foi encontrado nos primeiros n bytes da memória apontada por s.


3 - Considerações de Segurança e Desempenho
	
	Segurança: A função respeita os limites de n bytes, evitando o acesso fora dos limites da memória.
               Útil para trabalhar com buffers binários ou memória crua, sem necessidade de strings
			   com o caractere nulo (\0).

    Utilização: Pode ser usada em contextos de análise de dados binários, busca por caracteres em blocos
	            de memória, parsing de protocolos, etc.
				Diferente de strchr, que só funciona com strings (char *), memchr pode trabalhar com qualquer 
				tipo de memória.

*/