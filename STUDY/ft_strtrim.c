static int	is_in_set(char c, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	int		start;
	int		end;
	int		idx;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed = malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	idx = 0;
	while (start < end)
		trimmed[idx++] = s1[start++];
	trimmed[start] = '\0';
	return (trimmed);
}

/*

Objetivo: remover os caracteres do início e do fim de uma string s1 que estão presentes
no conjunto de caracteres da string set. A ideia é criar uma nova string que começa em
start e termina em end, eliminando os caracteres do ínicio e do fim, que pertencem ao set.

1 - Parâmetros da função  -  char *ft_strtrim(const char *s1, const char *set);

1.1 - const char *s1: É a string original que queremos "aparar" (ou seja, vai ter os caracteres indesejados
                      retirados das extremidades).
                      QUando declaramos s1 como const, estamos a garantir que a função não altera o conteúdo
					  da string original, apenas lê o conteúdo para tomar decisões sobre o que fazer.
					  Na função ft_strtrim, criamos uma nova string (trimmed) que contém os caracteres
					  relevantes de s1, ou seja, os caracteres que não estão no conjunto set, mas não vamos
					  modificar a string original (s1).

    				  Por exemplo, s1 = "---Hello---" é uma string da qual queremos remover os '-' das pontas.

1.2 - const char *set: É o conjunto de caracteres que queremos remover do início e do fim de s1.
                       A função irá considerar que qualquer caractere de set encontrado nas extremidades de s1
					   deve ser removido.
					   A função vai comparar cada caractere de s1 com os de set e eliminar os que coinciderem, 
					   desde que estejam no início ou no fim da string s1.

                       Ele é const, porque não queremos modificar o conjunto de caracteres que estamos a usar para
					   fazer a comparação. Queremos apenas ler os caracteres de set para verificar se estão presentes 
					   nas extremidades de s1.
					   Ou seja, a função ft_strtrim lê a string set, e compara cada caractere de s1 com os caracteres
					   de set, mas nunca modifica o conteúdo de set.
		   
2 - Implementação passo a passo

2.1 - Declaração de variáveis:

    int start: Índice do primeiro caractere relevante de s1 (que não está no set).
			   Começa com 0, que é o primeiro caractere relevante da string s1 .

    int end: Índice após último caractere relevante de s1 (que não está no set).
	         Começa com o comprimento total da string s1.
			 end não aponta para o último caractere relevante, mas sim para o índice logo após ele.
			 Por exemplo, se end = 5, significa que o último caractere relevante é s1[4].
			 end não aponta para s1[4], mas sim para s1[5], que é o caractere nulo '\0'.
			 
    int idx: Índice usado para copiar os caracteres da parte relevante de s1 para a nova string.

    char *trimmed: Ponteiro para a nova string que vamos criar depois de remover os caracteres indesejados
	               do ínicio e do fim da string original s1.
				   OU seja, trimmed é a nova string que vai conter os caracteres relevantes de s1.
				   Vai apontar para a memória alocada dinamicamente contendo apenas os caracteres que
				   queremos manter.

2.3 - Início e fim da string

start = 0;
end = (int)ft_strlen(s1);

	Vamos inicializar os índices start e end, que vão marcar o início e o fim da parte útil da string original s1,
	ou seja, a parte que não contém os caracteres do conjunto set no início e no fim.
    
	Vamos inicializar a variável start com 0, para começarmos a percorrer a string do início.
	Queremos verificar desde o primeiro caractere de s1 se ele pertence ao conjunto set.
	Inicialmente, start aponta para o começo da string (0).

	Em seguida, inicializamos a variável end com o comprimento total da string s1, que é obtido através da função
	ft_strlen(s1). O comprimento total da string é o número de caracteres que ela contém.
	A função ft_strlen retorna um size_t (tipo sem sinal, usado para tamanhos de memória).
    Aqui, fazemos um cast para int, porque estamos a usar p end como índice de posição (e todas as variáveis da função 
	estão como int).

2.4 - Encontrar o início real (ignorando caracteres do set)

    while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;

	O objetivo deste loop é encontrar o primeiro caractere de s1 que não pertence ao conjunto set.
	Vamos ignorar todos os caracteres do ínicio da string s1 que fazem parte do conjunto set.

	[IS_IN_SET]

	static int	is_in_set(char c, char const *set)
	{
		int	idx;

		idx = 0;
		while (set[idx])
		{
			if (set[idx] == c)
				return (1);
			idx++;
		}
		return (0);
	}
	
	Verifica se o caractere c existe dentro da string set.
	Se o caractere c estiver em set, a função retorna 1 (ou seja, verdadeiro).
    Se não estiver, retorna 0 (falso).

	char c: é o caractere que estamos a verificar se está no conjunto set.

	char const *set: é a string que representa o conjunto de caracteres que
	queremos eliminar.

	if (set[idx] == c)
	return (1);

	Verificamos se o caractere atual de set (set[idx]) é igual ao caractere c.
	Se for igual, significa que c está presente no conjunto set, então retornamos 1.
	Se não for igual, incrementamos o índice idx e verificamos o próximo caractere de set.

	Se sairmos do while sem encontrar o caractere c, significa que ele não está presente
	no conjunto set e então retornamos 0.

	Assim:

	is_in_set(s1[start], set): verifica se o caractere atual (s1[start]) está presente no conjunto 
	                           de caracteres a remover (set).
                               Esta função devolve 1 se o caractere estiver no conjunto, e 0 se não
							   estiver.

	Se o caractere atual existe (s1[start] != '\0') e está no conjunto set, avançamos para o próximo
	caractere da string s1 (start++).
	Repetimos este processo até encontrarmos um caractere que não esteja no conjunto set ou até
	chegarmos ao final da string (s1[start] == '\0').
	
	Exemplo:  const char *s1 = ">>>>>Olá Mundo";
             const char *set = ">";

	Índice	s1[i]	Está no set? (is_in_set)
		0	 '>'	          Sim
		1	 '>'	          Sim
		2	 '>'	          Sim
		3	 '>'	          Sim
		4	 '>'	          Sim
		5	 'O'	    Não! → Parar aqui

    Então o start vai passar de 0 até 5:

    start = 0
    → is_in_set('>', ">") → true → start++
    → is_in_set('>', ">") → true → start++
    → is_in_set('>', ">") → true → start++
    → is_in_set('>', ">") → true → start++
    → is_in_set('>', ">") → true → start++
    → is_in_set('O', ">") → false → PARAR

    Agora o start aponta para a letra 'O', ou seja, o início da parte relevante da string.


2.5 - Encontrar o fim real (ignorar caracteres do set no final)

	while (end > start && is_in_set(s1[end - 1], set))
		end--;

	Este loop é responsável por encontrar onde termina o conteúdo relevante da string s1, ou
	seja, o último caractere que não pertence ao conjunto set.

	Enquanto o índice end for maior que start e o caractere s1[end - 1] estiver no conjunto set,
	andamos para trás a partir do fim da string, reduzindo o valor de end, até encontrar um 
	caractere que não esteja em set.

	s1[end - 1] é o último caractere da string s1 que queremos verificar.

	Se end for maior que start, significa que ainda há caracteres relevantes a serem verificados
	e garante que não ultrapassamos o ínicio da string.

	is_in_set(s1[end - 1], set): verifica se o caractere anterior ao end (s1[end - 1]) está presente
	                             no conjunto de caracteres a remover (set).
								 Se estiver, ele deve ser removido, e reduzimos end--.

    Exemplo:   s1  = ">>>Olá Mundo>>>"
               set = ">"

    Índice	Caractere de s1
      0	         '>'
      1	         '>'
      2	         '>'
      3	         'O'
     ...	     ...
      12	     '>'
      13	     '>'
      14	     '>'

    ft_strlen(s1) → 15 → end = 15
    Começamos com s1[end - 1] = s1[14] = '>'
    is_in_set('>', ">") → 1 → end--
    Repetimos até s1[end - 1] não estar mais em set

	Passo a passo do loop:

    end	  s1[end - 1]	Está em set?	Ação
    15	      '>'	         Sim	   end = 14
    14	      '>'	         Sim	   end = 13
    13	      '>'	         Sim	   end = 12
    12	      'o'	         Não	   parar loop

    Resultado final: end = 12, ou seja, o último caractere relevante está no índice 11.

2.6 - Alocação da nova string

	trimmed = malloc((end - start + 1) * sizeof(char));

	Vamos alocar memória suficiente para armazenar a nova string (trimmed) final (ou seja, o segmento
	"limpo" de s1 sem os caracteres do conjunto set, no ínicio e no fim) mais o caractere nulo.

	end - start: é o comprimento da nova string que queremos copiar.

    Exemplo:

        start = 2, end = 7, comprimento = 5.

        Alocamos espaço para 6 (5 + 1) caracteres.

2.7 - Copiar os caracteres relevantes

	  idx = 0;
	  while (start < end)
	  	trimmed[idx++] = s1[start++];

    Copia caractere por caractere da porção relevante da string original (s1[start...end - 1]) para trimmed.

2.8 - Terminar com '\0'

      trimmed[idx] = '\0';

       Garante que a nova string é corretamente terminada.

2.9 - Retornar resultado

      return (trimmed);









*/