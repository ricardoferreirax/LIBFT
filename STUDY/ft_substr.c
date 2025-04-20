char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		idx;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	idx = 0;
	while (idx < len)
		substring[idx++] = s[start++];
	substring[idx] = '\0';
	return (substring);
}

/*

Objetivo: ft_substr cria uma nova string, dinamicamente alocada, que contém uma cópia de até len 
caracteres, começando no índice start da string original s.
Esta função é usada, por exemplo, para dividir uma string em partes menores, ou extrair uma palavra
dentro de uma frase, ou simplesmente selecionar os primeiros n caracteres a partir de um ponto 
específico.


1- Parâmetros  - char *ft_substr(char const *s, unsigned int start, size_t len)

- char const *s: representa a string original a partir da qual a função vai extrair a substring. 
                 É um const, ou seja, a função lê a string s, onde calcula o seu comprimento e 
				 copia os caracteres dela para uma nova string alocada dinamicamente, mas em
				 nenhum momento tenta modificá-la. 

- unsigned int start: representa o índice do ínicio da substring dentro da string s, ou seja, é
                      o número da posição onde começa a cópia dos caracteres. 

					   Por que usar unsigned int?

					   > Evita valores negativos: Se usássemos um int, poderiamos chamar 
					     ft_substr("42Lisboa", -5, 3) o que causaria acesso inválido à memória,
						 porque s[-5] é uma posição antes do início da string.

                       Com unsigned int, é garantido que o valor seja sempre positivo (ou zero) 
					   e evita acessos inválidos.

					   unsigned int é um tipo inteiro sem sinal, ou seja, nunca representa valores 
					   negativos.

                       Tipo	              Intervalo comum (32 bits)
                       int	           -2,147,483,648 a +2,147,483,647
                       unsigned int	         0 a 4,294,967,295

- size_t len: indica o número máximo de caracteres que queremos copiar da string s, a partir da
		      posição start. 
			  A nova string alocada deve conter até len caracteres + o '\0'. 
			  Não corresponde ao comprimento da string s, mas sim ao tamanho desejado da nova
			  substring. 

			  Como este valor está diretamente relacionado com o tamanho de uma área de memória,
			  usamos o size_t, que foi projetado exatamente para isso. 

Compreender o comportamento

2. Verificar se start está fora dos limites

	if (start >= ft_strlen(s))
    	return (ft_strdup(""));

    Começamos por verificar se o valor de start está fora dos limites da string original. 
	Se start >= ft_strlen(s) significa que estamos a tentar começar uma substring a partir de uma
	posição que não existe na string original. Ou seja, estamos a tentar começar uma substring
	após o final da string. Não há mais nenhum caractere para ler — estamos para além do fim da string.

    Exemplo: const char *s = "hello"; // comprimento = 5 (índices 0 a 4)
             unsigned int start = 7;
             size_t len = 3;

             ft_substr(s, start, len);

             Etapas: ft_strlen(s) = 5
                     start = 7 → estamos a tentar começar depois do fim da string
                     start >= 5 → condição verdadeira

			Portanto, o código executa return (ft_strdup(""));
            Ou seja, devolve uma string vazia, porque não há nada para copiar.

3. Ajustar o comprimento da substring

	if (len > ft_strlen(s) - start)
    	len = ft_strlen(s) - start;

	Esta verificação ajusta o comprimento da substring que queremos extrair, para não ultrapassar
	os limites da string original. Se se verificar ajustamos len para que ela apenas vá até ao 
	fim da string.

    start: Índice inicial a partir do qual vamos extrair a substring.

	len: valor que o utilizador passou para indicar quantos caracteres deseja copiar a partir da
	     posição start.

	ft_strlen(s) - start: calcula quantos caracteres restam a partir da posição start até ao
	                      fim da string. 

	Se o utilizador pediu para copiar mais caracteres do que existem a partir de start, então 
	devemos ajustar len para o valor máximo possível — ou seja, o número de caracteres restantes.

	Exemplo: const char *s = "abcdef";
             unsigned int start = 4;
             size_t len = 10;

             ft_strlen(s) = 6

             start = 4 → a partir da letra 'e'

             6 - 4 = 2 → restam apenas 'e' e 'f'

             len = 10 → queremos copiar mais do que o disponível

             A condição len > ft_strlen(s) - start é verdadeira
             Fazemos: len = 2

             Resultado: copiamos só o que é possível, e não ultrapassamos os limites da string original.

	Por que isto é importante?

	> Evita a leitura fora de memória válida: Se não fizermos este ajuste, e tentarmos copiar 
	  10 caracteres quando só existem 2, vamos aceder a memória fora dos limites da string, o 
	  que pode levar a comportamento indefinido.
    > Garante que a substring resultante é segura e correta: Mesmo que o utilizador peça para 
	  copiar um tamanho exagerado, garantimos que a substring nunca ultrapassa o fim da string
	  original.

4. Alocação de memória para a substring

	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
    	return (NULL);

	A string substring vai armazenar dinamicamente a nova string extraída a partir da string original
	s, que começa na posição start, com comprimento len. 
	Vai servir como armazenamento da substring, isto é, vai servir de nova cadeia de caracteres
	que vamos alocar, e copiar para lá os caracteres desejados, terminando com '\0', na ultima
	posição.  

	Reservamos, assim, memória suficiente para len caracteres da substring + 1 byte para o '\0'.

5. Copiar os caracteres da string original

	while (idx < len)
    	substring[idx++] = s[start++];

	Criamos um laço para copiar caractere por caractere da string original s, a partir do índice start,
	até len caracteres.

📌 Explicação linha a linha:

    s[start++]: acessa o caractere atual e avança start para o próximo

    substring[idx++]: coloca esse caractere na nova string e incrementa o índice de destino


6. Adicionar o terminador nulo \0

substring[idx] = '\0';

🔍 O que está a ser feito:
Colocamos o \0 no final da substring. Isso marca o fim lógico da string.

📌 Sem isso, a string seria inválida!
Funções de string dependem do \0 para saber quando parar.
7. Retornar a nova substring

return (substring);

🔍 Resultado final:
Devolvemos um ponteiro para a nova string alocada, que contém os caracteres desejados extraídos da original.





*/