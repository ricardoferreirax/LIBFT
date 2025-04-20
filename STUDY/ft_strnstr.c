
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	start;

	if (*little == '\0')
		return ((char *)big);
	start = 0;
	while (start < len && big[start] != '\0')
	{
		idx = 0;
		while (little[idx] && big[start + idx] == little[idx] 
				&& (start + idx) < len)
			idx++;
		if (little[idx] == '\0')
			return ((char *)&big[start]);
		start++;
	}
	return (NULL);
}

/*

Objetivo: A função ft_strnstr tem como objetivo localizar a primeira ocorrência de
uma substring (little) dentro de uma string maior (big), dentro de um limite de até
len caracteres de big (apenas nos primeiros len caracteres de big).
É uma versão mais segura da strstr, porque impede que a procura ultrapasse um número
máximo definido de caracteres, o que protege contra acessos indevidos de memória.

Assim: - A função procura se a sequência de caracteres da string little existe dentro
         da string big, começando da esquerda para a direita.
       - Esta procura só pode ser feita até len caracteres da string big, ignorando qualquer
	     ocorrência da substring little depois disso.
       - Se little for encontrada dentro desses limites, a função retorna um ponteiro para
	     a posição da string big onde a substring começa.
       - Se não encontrar, a função retorna NULL.

Parâmetros  -  char *ft_strnstr(const char *big, const char *little, size_t len);

const char *big: representa a string maior onde vamos procurar a substring little.
                 É const, o que indica que o conteúdo apontado não pode ser modificado
				 dentro da função. A função ft_strnstr apenas lê a string big, não
				 altera nenhum caractere dela. 

const char *little: representa a substring que vamos procurar dentro da string maior big.
                    É também const, pois a função só precisa de ler a substring little para
					comparar com a string big, não precisa de modificá-la. 
					O uso de const garante que o conteúdo da substring little não será 
					alterado pela função, o que torna a função mais segura. 

size_t len: representa o número máximo de caracteres da string big que devem ser considerados
            ao procurar a substring little. 
			A variável len diz-nos: "Procura a substring little dentro da string big, mas só
			nos primeiros len caracteres de big". 
			Esta variável é importante, pois evita que a função leia para além da àrea da
			memória permitida. 

			Por que usar size_t para len?

            - Evitamos valores negativos: Como len representa um tamanho, nunca pode ser negativo.
              Usar int len abriria a possibilidade de len = -1, o que não faz sentido e pode causar 
			  comportamento indefinido.

            - Compatibilidade com outras funções:  Usar size_t torna a função compatível com: - strlen()
			                                                                                  - sizeof
                                                                                              - Outras funções da
																							    LibC que também usam 
																							    size_t.

            Exemplo:  const char *big = "programar em C é fixe";
                      const char *little = "em C";
                      size_t len = 10;

                      char *res = ft_strnstr(big, little, len);

                      A função vai procurar a susbtring "em C" dentro da string "programar em C é fixe".
                      Mas só vai olhar para os primeiros 10 caracteres da string big, ou seja: "programar ".
                      Assim, a string "em C" aparece só depois da posição 10, então o resultado será NULL.

2 - Análise passo a passo da implementação

2.1 - Verificação de string vazia
    
    if (*little == '\0')
		 return ((char *)big);

    Se a substring little for uma string vazia (ou seja, se o primeiro caractere for \0 - é o mesmo que 
	escrever little[0] == '\0'), o padrão da função strnstr é o de retornar a própria string big, pois uma
	string vazia está presente em qualquer posição de qualquer substring.
	A primeira ocorrência de uma string vazia dentro de outra é no início da string maior. 

	Assim, procurar por uma string vazia dentro de outra string deve sempre retornar a string original.
    
	Esta verificação é essencial para respeitar o comportamento padrão da linguagem e evitar fazer 
	comparações desnecessárias quando sabemos, de antemão, que a string vazia sempre “existe” no 
	início da outra.

	Exemplo:	Procurar "" em "42 Network Lisboa" retorna "42 Network Lisboa"

	Porque convertemos para (char *)big?

     A função ft_strnstr retorna um char *, ou seja, um ponteiro não constante.
     Mas como o array big foi declarado como const char * temos de convertê-lo para char *.

     Logo, fazemos um typecast: (char *)big

     Isto converte o tipo para o que a função precisa de retornar.
     Este cast remove a proteção de "const".

2.2 - Loop principal

    while (start < len && big[start] != '\0')

    Aqui iniciamos o loop principal, onde vamos percorrer, do ínicio, a string big, posição
	por posição, à procura da ocorrência da substring little.

	Este while é executado enquanto não ultrapassar o limite len e ainda houver caracteres na
	string big e continuamos a tentar encontrar a substring little a partir da posição atual.

	A variável start é um índice que representa a posição atual na string big onde começamos
	a verificar se a substring little aparece.
    
    Começamos com start = 0 (ou seja, no início de big) e vamos avançando um caractere de cada vez,
	até encontrarmos a substring little ou até atingirmos o limite de len.
	
	- start < len: garante que não vamos ultrapassar o limite de caracteres imposto por len.
                   A função ft_strnstr deve procurar no máximo len caracteres da string big.
                   Se start (o índice atual de onde estamos a tentar iniciar a comparação) for
				   igual ou maior que len, paramos o loop, porque estaríamos fora da área permitida.

				   A função ft_strnstr é segura porque nunca acessa mais do que len caracteres da
				   string big. 

	- big[start] != '\0': Esta verificação assegura que ainda estamos dentro da string big.
                          Se chegarmos ao caractere nulo ('\0'), é sinal de que acabou a string. 
						  Não há mais nada para procurar.

	Assim, só continuamos o loop se ainda estivermos dentro do limite len (limite de procura), e
    se ainda não chegamos ao fim da string big (enquanto ainda houver caracteres na string big). 

2.3 - Inicio da verificação: 


	while (little[idx] && big[start + idx] == little[idx] 
			&& (start + idx) < len)
		idx++;

	O while percorre a substring little e, ao mesmo tempo, compara cada caractere com os caracteres
	da string big, a partir de uma posição start especifica (big[start + idx]), apenas se ainda 
	estivermos dentro do limite len. 
	
	little[idx] representa a posição dentro da substring little que estamos a comparar. 

	- big[start + idx] == little[idx]: Compara o caractere atual da substring little com o caractere 
	                                   correspondente da string big, ajustado pela posição start,
									   que é onde estamos a tentar encontrar a substring little. 
									   Isto verifica se, a partir daquela posição especifica da
									   string big, os caracteres correspondem exatamente aos da
									   substring little. 

                                       Começamos a comparar: big[start] com little[0]
                                                             big[start + 1] com little[1]
															 big[start + 2] com little[2]
                                                                 e assim por diante.

                                        O loop continua enquanto os caracteres forem iguais.

	-  (start + idx) < len: garante que a comparação não ultrapasse o limite de caracteres 
	                        permitidos (len) dentro da string big.
    
	- idx++: Se todas as condições forem verdadeiras, a comparação avança para o próximo caractere
	         da substring little, incrementando o indice idx.
	
    Se todos os caracteres da substring little forem encontrados sequencialmente, o while irá terminar quando little[idx] == '\0'.

    Suponhamos:  big    = "bananada";
                 little = "nada";
                 len    = 8;

    1. Primeira tentativa: start = 0

        big[0] == 'b' e little[0] == 'n' → ❌ (sai do laço interno)

	2. start = 1

	    big[1] == 'a' e little[0] == 'n' ❌ (sai do laço interno)

    3. start = 2

        big[2] == 'n' e little[0] == 'n' → ✅

        big[3] == 'a' e little[1] == 'a' → ✅

        big[4] == 'n' e little[2] == 'd' → ❌ (sai do laço interno)

    3. start = 4

       big[4] == 'n' e little[0] == 'n' → ✅

       big[5] == 'a' e little[1] == 'a' → ✅

      big[6] == 'd' e little[2] == 'd' → ✅

      big[7] == 'a' e little[3] == 'a' → ✅

      little[4] == '\0' → fim de little, sucesso!
    

2.4 - Verificação de sucesso

    if (little[idx] == '\0')
	    return ((char *)&big[start]);

	Aqui, verificamos se conseguimos comparar com sucesso todos os caracteres da substring little
	com os caracteres da string big, a partir da posição start.
	Ou seja, se saímos do while e o índice idx atingiu o final da string little, significa que toda 
	a substring little foi encontrada na string big, a partir do começo da posição start. 
	
	Se for verdade, significa que a substring little foi totalmente encontrada dentro da string big,
	e neste caso a função retorna a posição onde a ocorrência começa.

	Quando little[idx] == '\0', sabemos que:

      > Todos os caracteres de little coincidiram com os da big[start + idx].
      > Portanto, a substring little está contida dentro da big, começando na posição start.

	return ((char *)&big[start]): retorna um ponteiro para o início da substring encontrada.

                                  &big[start] → é o endereço de memória onde a substring little começa 
								  dentro da string big.

                                  (char *) → é um cast, necessário porque big é um const char * e o retorno
								  da função é char *. (A função precisa de retornar um ponteiro para char, e
								  não para const char, pois o protótipo permite modificações.)


    start++: Se não encontramos a substring little em big[start], incrementamos start para tentar na próxima posição.

    return (NULL): Se o loop terminar sem encontrar a substring little, a função retorna NULL, indicando que a substring
	               não foi encontrada nos primeiros len caracteres de big.




*/