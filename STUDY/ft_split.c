static int count_words(const char *s, char sep)
{
	int idx;
	int count;
	int in_word;

	idx = 0,
	count = 0;
	in_word = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] != sep && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		if (s[idx] == sep)
			in_word = 0;
		idx++;
	}
	return (count);
}

static char	*malloc_words(const char **s, char sep)
{
	int			len;
	char		*word;
	const char	*str;

	len = 0;
	while (**s != '\0' && **s == sep)
		(*s)++;
	str = (*s);
	while (**s != '\0' && **s != sep)
	{
		len++;
		(*s)++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len + 1);
	return (word);
}

void	free_split(char **array, int current)
{
	while (current >= 0)
		free(array[current--]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		idx;
	char	**strings;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strings = malloc((words + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	idx = 0;
	while (idx < words)
	{
		strings[idx] = malloc_words(&s, c);
		if (!strings[idx])
			return (free_split(strings, idx - 1), NULL);
		idx++;
	}
	strings[idx] = NULL;
	return (strings);
}

/*

[FT_SPLIT]

Objetivo da função: Divide a string s em várias palavras utilizando o caractere separador c e
retorna um array de strings (palavras) alocadas dinamicamente.

1. words = count_words(s, c);

Essa linha chama a função count_words para contar quantas palavras existem na string s, considerando
o caractere c como separador.

A função count_words percorre a string s e conta quantas sequências de caracteres (palavras) estão separadas
pelo caractere c.

[COUNT_WORDS]

while (s[idx] != '\0')
	{
		if (s[idx] != sep && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		if (s[idx] == sep)
			in_word = 0;
		idx++;
	}
	return (count);

A função count_words conta quantas palavras existem na string s, considerando o caractere c como separador.

Objetivo: Contar quantas palavras existem na string s, considerando que: > Uma palavra é uma sequência de caracteres 
                                                                         diferentes do separador sep.
                                                                         > Vários separadores consecutivos não contam como palavras.
                                                                         > Os separadores podem estar no início, no meio ou no fim da 
																		 string.

idx: indice que percorre cada caractere da string.
count: conta o número de palavras encontradas e armazena o número total.
in_word: flag que indica se estamos dentro de uma palavra ou não.

in_word = 0: Inicialmente, estamos fora de uma palavra.
in_word = 1: Estamos dentro de uma palavra.

1 - Quando encontramos o ínicio de uma nova palavra
   
	if (s[idx] != sep && in_word == 0)
    {
	   count++;
	   in_word = 1;
  	}

	Se o caractere atual não é o separador e ainda não estamos numa palavra:

    Então começamos uma nova palavra: Incrementamos count.
                                      Definimos in_word = 1 (estamos dentro de uma palavra).

2 - Quando encontramos um separador
	
	if (s[idx] == sep)
		in_word = 0;

	Se o caractere atual é o separador, então estamos fora de uma palavra: 
	
	QUalquer palavra que estivesse a acontecer, acabou.
	Definimos in_word = 0, para indicar que não estamos mais dentro de uma palavra e
	para que possamos contar a próxima palavra.

	Exemplo:

	const char *str = "  ola  mundo 42 ";
    char sep = ' ';

    Caracteres por índice:

	idx	   caractere	in_word	  count	             Ação
	 0	      ' '	       0	    0	    separador → in_word continua 0
     1	      ' '	       0	    0	    separador → in_word continua 0
     2	      'o'	     0 → 1	    1	    início de palavra → conta +1
     3	      'l'	       1	    1	    estamos dentro de palavra
     4	      'a'	       1	    1	    ainda na palavra
     5	      ' '	     1 → 0	    1	    separador → fim da palavra
     6	      ' '	       0	    1	    ainda separador
     7	      'm'	     0 → 1	    2	    nova palavra → conta +1
     8	      'u'	       1	    2	    dentro da palavra
     9	      'n'	       1	    2	    dentro da palavra
    10	      'd'	       1	    2	    dentro da palavra
    11	      'o'	       1	    2	    dentro da palavra
    12	      ' '	     1 → 0	    2	    fim da palavra
    13	      '4'	     0 → 1	    3	    nova palavra → conta +1
    14	      '2'	       1	    3	    dentro da palavra
    15	      ' '	     1 → 0	    3	    fim da palavra

NO fim, a função retorna o count (return (count)), ou seja, o número total de palavras encontradas
que, no exemplo, é count = 3, ou seja, a string " ola mundo 42" tem 3 palavras.


[V0LTANDO AO FT_SPLIT]

2. strings = malloc((words + 1) * sizeof(char *));

Agora, após saber quantas palavras a string s contém, é necessário alocar memória para armazená-las.

Portanto, a expressão malloc((words + 1) * sizeof(char *)) aloca memória suficiente para armazenar um array de
strings. O +1 é necessário para adicionar o terminador NULL, que marca o final da lista de palavras.

Exemplo prático: Se words = 3 (como no caso do exemplo acima, com 3 palavras), a expressão malloc((3 + 1) * sizeof(char *)) 
vai alocar 4 ponteiros (pois estamos a contar 3 palavras + 1 ponteiro para NULL).

3. Percorrer as palavras

    while (idx < words)
    {
   	    strings[idx] = malloc_words(&s, c);
        if (!strings[idx])
        	return (free_split(strings, idx - 1), NULL);
    	idx++;
    }

words: guarda o número total de palavras encontradas (calculada na função count_words) na string s, separadas
       pelo separador c.

idx: é o índice que vai percorrer o array strings (char **strings), onde cada elemento será uma palavra extraída
	 da string original s.

while (idx < words): O loop while vai percorrer o número de palavras que foi calculado anteriormente
                     com a variável words.
                     
                      Processo: 1 - Encontrar a próxima palavra na string original s
                                2 - Alocar memória para ela com malloc_words
                                3 - Armazenar o ponteiro da palavra em strings[idx]

					 Ou seja, o loop vai continuar a executar enquanto o índice idx for menor do que o número 
					 total de palavras words.

					 Exemplo:  s = "ola mundo 42"
                               c = ' '
                               words = 3

                     Iterações:

					 Iteração	idx	    O que faz malloc_words(&s, c)?	   Resultado armazenado em strings[idx]

					    1	      0	             Extrai "ola"	                     strings[0] = "ola"
						2	      1	             Extrai "mundo"	                     strings[1] = "mundo"
					    3	      2	             Extrai "42"	                     strings[2] = "42"

                     Depois do loop: strings[3] = NULL (linha após o while)
                                     Isto marca o final do array de strings.

[MALLOC_WORDS]

Objetivo da função: Encontra a próxima palavra na string s (ignorando os separadores sep),
aloca memória para armazená-la e retorna um ponteiro para essa nova string (palavra terminada em \0).
Esse ponteiro vai ser atribúido a strings[idx], ou seja, a cada palavra encontrada
na string s. 
Assim, a função malloc_words vai ser chamada para alocar memória e retornar uma palavra
extraída da string s. 

1 - Protótipo da função  -  static char *malloc_words(const char **s, char sep)

    const char **s: é um ponteiro que aponta para outro ponteiro, que por sua vez aponta para
	                para uma string.

					Exemplo: 

					const char *str = "ola";
					const char **s = &str;

					Variável	 Tipo	          Valor	             Explicação
					    s	  const char **	  endereço de str	ponteiro para ponteiro
					   *s	  const char *	      "ola"	        ponteiro para a string
                      **s	     char	           'o'	      valor do primeiro caractere da string
					
					
					char *s é um ponteiro para uma string (ou seja, o endereço do primeiro
					caractere da string). O ponteiro **s é um ponteiro para esse ponteiro,
					o que significa que podemos modificar o ponteiro original dentro da função.

					Ele é um ponteiro para um ponteiro para const char, ou seja, a string original
					não pode ser modificada, mas só ponteiro pode ser alterado.
					
					O const garante que podemos mover o ponteiro, mas não podemos alterar os caracteres
					da string.

		            Por que não é só const char *s?

					Se fosse apenas const char *s, significaria que a função não conseguiria avançar
					o ponteiro s para a próxima palavra. Ou seja, você conseguiriamos "consumir"
					a string aos poucos.
					
    char sep: é o caractere separador. Todas as vezes que encontramos esse caractere, consideramos 
	        que ele separa as palavras.

	len: Armazena o tamanho da palavra encontrada, ou seja, o número de caracteres que a palavra
		 tem (sem contar o caractere nulo '\0' no final).

    word: é um array que vai armazenar a palavra alocada, ou seja, vai guardar a nova palavra copiada.

    str: Aponta para o início da palavra atual (usado para copiar depois).

2 - Ignorar os separadores no início - while (**s != '\0' && **s == sep)
    								   	  (*s)++;

    Este while ignora os caracteres separadores no íncio da string, avançando o ponteiro *s até 
	encontrar o primeiro caractere diferente de sep (o início de uma palavra).

	**s == c → verifica se o caractere atual é o caractere separador (por exemplo, ' ' ou ',')

	Se sim, (*s)++ → avança o ponteiro da string (muda o valor de *s) para o próximo caractere.

    Por exemplo, se c for o espaço ' ' e a string for " ola mundo", ele vai pular os três primeiros 
	espaços para que a leitura comece em 'o'.

	Assim, o ponteiro *s vai apontar para o primeiro caractere diferente de c.
	Ou seja, se a string for " ola mundo", o ponteiro *s vai apontar para 'o'.
	O ponteiro é posicionado no íncio da próxima palavra.

3 - Guardar o início da palavra  - str = (*s);

    A variável str vai apontar para o ´inicio da palavra e guarda a posição onde a palavra começa,
	depois de já termos ignorado os separadores para que possamos copiar depois com ft_strlcpy.

	Imaginemos que a string era " ola mundo" e que o separador é o espaço (' ').
    Depois do while (**s == c) (*s)++, o ponteiro *s aponta para 'o' (início da palavra "ola").

    Então str = (*s) significa: "Guarda o endereço atual onde a palavra começa."

	Mais à frente, vamos fazer isto ft_strlcpy(word, str, len + 1);

    Ou seja, copiar desde str até ao final da palavra. Como *s já avançou dentro do while, precisamos
	de guardar este "marcador de início da palavra" para saber onde começamos a copiar depois.

4 - Medir o tamanho da palavra  -  

    while (**s != '\0' && **s != c)
 	{  								
		len++;
    	(*s)++;
	}

	Aqui vamos calcular o comprimento da próxima palavra, ou seja, a sequência de caracteres que 
	não são o separador sep, e ao mesmo tempo vamos avançar o ponteiro *s até ao fim dessa palavra.

    Este while conta os caracteres da palavra até encontrar um separador c ou o final da string.

	Ou seja, estamos a percorrer uma palavra, que é definida como "uma sequência de caracteres 
	diferentes de c".
    
	len++ : conta quantos caracteres a palavra tem. No fim, será utilizada para alocar a memória
	para a palavra.

	(*s)++: avança o ponteiro *s para o próximo caractere, até que ele encontre um separador ou o
	final da string.

5 - Alocar memória para a palavra  -  word = malloc(sizeof(char) * (len + 1));

	Vamos alocar memória dinamicamente para guardar a palavra que acabámos de encontrar
	na string original - incluindo o caractere nulo '\0' no final, para que a string seja
	válida.

    Alocamos len + 1 porque queremos espaço para a palavra + o caractere \0.

6 -  Copiar a palavra para o espaço alocado   -  ft_strlcpy(word, str, len + 1);

     Vamos copiar a palavra extraída da string original (str) para o espaço de memória recém-alocado
	 (word), terminando com o caractere '\0'.
	 
	 Vai copir exatamente os primeiros len caracteres da palavra str para word, e vai garantir que
	 o último caractere de word seja '\0'.

	 size_t	ft_strlcpy(char *dst, const char *src, size_t size);

	 Parâmetro	              Significado
       dst	         Destino (onde vai a cópia) → para word
       src	          Origem (de onde vamos copiar) → da str
       size	         Número máximo de caracteres a copiar incluindo \0

7 - Retornar a palavra  -  return (word);

[VOLTANDO AO FT_SPLIT]

3 - Verificação de erro - if (!strings[idx])

	Se a alocação de memória falhar em malloc_words a função malloc_words retorna NULL, ou seja,
	o que significa que não foi possível alocar memória para armazenar a palavra. Nesse caso, precisamos
	de libertar a memória que já foi alocada para as palavras anteriores para evitar leaks de memória 
	e retornar NULL.

	return (free_split(strings, idx - 1), NULL): A função free_split é chamada para libertar toda a 
	memória alocada até ao índice atual (idx - 1), ou seja, todas as palavras que já foram alocadas
	antes de encontrar o erro (ou seja, antes de a falha ocorrer). O índice é decrementado em 1 porque
	strings[idx] falhou e não foi alocado.

    idx - 1: indica até qual índice devemos libertar a memória. O idx aponta para o próximo elemento que 
	não foi alocado corretamente, então idx - 1 refere-se ao último elemento que foi alocado com sucesso.

	NULL: Após libertar a memória, a função retorna NULL, indicando que a operação de divisão da string falhou.


	[FREE_SPLIT]

	void	free_split(char **array, int current)
    {
		while (current >= 0)
			free(array[current--]);
		free(array);
	}

	current: é o índice atual que indica a última palavra alocada com sucesso.
	         Serve para sabermos quantas strings vamos libertar.
	array: é o array de strings (char **) que contém todas as palavras alocadas até o índice current.


	Imaginemos que alocamos várias strings com malloc_words, mas a certa altura uma falha. Não podemos deixar as
	anteriores sem libertar — isso causaria um memory leak.

	Portanto a função free_split liberta todas as strings já alocadas, e depois liberta o array principal (char **array)
	que as armazenava.


	Essa função é responsável por libertar a memória alocada para o array de strings (array) e
	todas as palavras que foram alocadas até o índice current.

	1 - while (current >= 0)
		Esse loop percorre o array de strings, começando do índice current até 0, e liberta a memória
		alocada para cada palavra.

	2 - free(array[current--]);
		A função free é chamada para libertar a memória alocada para a palavra atual. O operador -- decrementa
		o índice current após libertar a memória.

	3 - free(array);
		Depois de liberar todas as palavras, a função liberta a memória alocada para o array de strings em si.

	Exemplo:  array[0] = strdup("ola");    // malloc_words
              array[1] = strdup("mundo");  // malloc_words
              array[2] = NULL;             // malloc falhou aqui

              Chamamos free_split(array, 1) porque só o índice 0 e 1 foram alocados com sucesso.

              Resultado: free(array[1]);  // "mundo"
                         free(array[0]);  // "ola"
                         free(array);     // array de ponteiros

*/