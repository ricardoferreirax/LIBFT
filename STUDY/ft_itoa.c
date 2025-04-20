static int	numberlen(int num)
{
	int			len;
	long	n;

	n = num;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*number;
	long	nbr;

	nbr = n;
	len = numberlen(nbr);
	number = malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	if (nbr == 0)
		number[0] = '0';
	if (nbr < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	number[len--] = '\0';
	while (len >= 0 && nbr > 0)
	{
		number[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (number);
}

/*

Objetivo: Converter um número inteiro (int) para uma string (char *) que representa
esse número em texto.

1 - Parâmetros da Função  -  char *ft_itoa(int n);

    int n: número que queremos converter para string.

2 - Como a função funciona

2.1 - Declaração da função  -  char *ft_itoa(int n);

	 A função recebe um número inteiro (int n) e retorna um ponteiro para uma string (char *) 
	 que representa o número em formato de array.

2.2 - Declaração de variáveis:

	int len: Armazena o número de caracteres que a string final tem (incluindo o sinal
	         '-' se o número for negativo). Armazena o tamanho da string final.

	         É calculado com a função numberlen, que analisa o número e devolve quantos caracteres
	         serão necessários para o representar como uma string.

	char *number: ponteiro que aponta para o bloco de memória alocado dinamicamente onde será armazenada
	              e construída a string final (para representar o número).
				  É uma variável que aponta para o primeiro caractere da string (array de caracteres).

	long nbr: Armazena o valor original de n, convertido para long para evitar problemas com números
	          negativos extremos (overflow).

			   Mas por que usar long? Porque o int tem limites:

                    - int: pode ir de -2,147,483,648 a 2,147,483,647

                    Se n == -2,147,483,648, ao fazer n = -n (tornar positivo), ocorre overflow, pois não 
					cabe num int.

                Ao fazer nbr = n, o valor é armazenado como long, e nbr tem mais espaço para armazenar
				o número negativo, armazenando até -2^63 (num sistema 64-bit), sendo seguro inverter
				o sinal.

				- long: pode ir de -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807
				O long é maior e pode armazenar números maiores que o int.

2.3 - Conversão para long para evitar overflow:asm
	
	nbr = n;

	Usamos long para evitar problemas de overflow, já que o valor absoluto de n pode ser maior que
	o máximo que um int pode armazenar.

2.4 - Cálculo do tamanho da string:
	
	len = numberlen(nbr);

	[NUMBERLEN]

    2.4.1 - Calculo o número de dígitos do número n.

	static int	numberlen(int num)
	{
		int		len;
		long	n;

		n = num;
		len = 0;
		if (n == 0)
			return (1);
		if (n < 0)
		{
			n = -n;
			len++;
		}
		while (n > 0)
		{
			n /= 10;
			len++;
		}
		return (len);
	}
	
	A função numberlen conta quantos caracteres serão necessários para armazenar o
	número como uma string.
	Calcula o número de dígitos que o número n tem.
	Ou seja, calcula quantos caracteres são necessários para reprresentar o número.
	Isso inclui os digitos e, se o número for negativo, o sinal de menos '-'.
	Se n for 0, retorna 1 (pois "0" tem 1 dígito).
	Se n for negativo, conta o sinal '-' e transforma n em positivo.
	Depois, conta quantas vezes n pode ser dividido por 10 até chegar a 0.
	Isso nos dá o número total de dígitos.

	1) long n = num;
	
	Convertemos o número para long para evitar problemas de overflow, pois, caso n seja o menor
	número que um int pode armazenar (INT_MIN), ao fazer n = -n diretamente com um int, teríamos um
	overflow, já que o valor positivo correspondente não pode ser representado como um int.

    Isto é importante porque INT_MIN não pode ser representado como um número positivo.
	// Exemplo: INT_MIN = -2147483648, não pode ser representado como um número positivo.
	// Portanto, convertemos n para long para evitar problemas de overflow.

	2) Verificação de 0:

	if (n == 0)
    	return (1);

    Se for zero, precisamos de contar apenas 1 dígito: '0', pois len de 0 é 1.
	
	3) Verificação de negativo:

	if (n < 0)
	{
		n = -n;
		len++;
	}

	Se n for negativo, convertemos o número em positivo para facilitar o cálculo dos digitos, pois 
	é mais fácil trabalhar e contar os dígitos de um número positivo.

	Quando encontramos um número negativo, precisamos de reservar um espaço extra na string para o
	sinal de menos '-'.
	Assim, se n for negativo, aumentamos len em 1 para contar o sinal '-' e transformamos n em
	positivo.

	Exemplo:

    O número 123 tem 3 dígitos → "123"
    O número -123 tem 4 caracteres → "-123" (o sinal conta e precisamos de reservar espaço para ele).

	4) Contagem de dígitos:
	
	while (n > 0)
	{
		n /= 10;
		len++;
	}

	Vamos contar quantos dígitos tem o número inteiro positivo.
	Divide o número por 10 a cada repetição até chegar a 0, contando quantas vezes fizemos isto.
	Ou seja, o loop vai dividir o número por 10 sucessivmente, eliminando um digito a cada repetição,
	contando sempre quantas vezes fizemos isso (len++) - a cada divisão, somamos 1 a len, pois cada 
	dígito removido é um que temos de contar para o itoa.
	Quando n chega a 0, o loop para e len contém o número total de dígitos.
	Vai nos dar o número total de dígitos.

	Exemplo:
	
		n = 1234
		1ª iteração: n = 1234 / 10 = 123 → len = 1
		2ª iteração: n = 123 / 10 = 12 → len = 2
		3ª iteração: n = 12 / 10 = 1 → len = 3
		4ª iteração: n = 1 / 10 = 0 → len = 4

	[DE VOLTA A FT_ITOA]

	Recapitulando, a função numberlen calcula o número de dígitos que o número nbr tem.
	Ou seja, calcula quantos caracteres são necessários para reprresentar o número.
	Isso inclui os digitos e, se o número for negativo, o sinal de menos '-'.
	Se nbr for 0, retorna 1 (pois "0" tem 1 dígito).
	Se nbr for negativo, conta o sinal '-' e transforma nbr em positivo.
	Depois, conta quantas vezes nbr pode ser dividido por 10 até chegar a 0.
	Isso nos dá o número total de dígitos.

	2.5 - Alocação de memória para a string:

	number = malloc(sizeof(char) * (len + 1));

	Alocamos espaço na memória para armazenar a string number que vai conter a representação
	do número inteiro.
	Precisamos de len + 1 bytes, pois precisamos da posição extra para o caractere nulo '\0' 
	que indica o final da string.
	Se a alocação falhar, retornamos NULL.

	O que acontece com malloc(sizeof(char) * (len + 1))?

    Vamos dizer que len = 3 (como no número 123). 
	Então: number = malloc(sizeof(char) * (3 + 1)); // malloc(4)

    Isso reserva 4 bytes na memória:

        Um para '1'
        Um para '2'
        Um para '3'
        Um para '\0'

 	O ponteiro number passa a apontar para o início desse bloco de memória.

	2.6 - Verificação número zero:
	
	if (nbr == 0)
		number[0] = '0';
	
	Se o número for zero, colocamos manualmente o caractere '0' na primeira posição da string.
	Isso é importante porque, se o número for zero, não entraremos no loop seguinte.
	
	2.7 - Verificação número negativo:
	
	if (nbr < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	
	Se o número for negativo, colocamos o sinal '-' na primeira posição da string e
	convertemos o número em positivo para facilitar a extração dos dígitos depois, 
	ao utilizar o modulo (%).

	Depois de colocar o sinal, transformamos o número em positivo, porque:

    - A parte que converte os dígitos (o loop com % 10) só funciona bem com números positivos.
    - O operador `%` com números negativos pode gerar comportamentos confusos ou indesejados.

	Então aqui, garatimos que o sinal '-' seja representado corretamente na string.
	
	2.8 - Preenchimento da string com os dígitos:
	
	number[len--] = '\0';
    while (len >= 0 && nbr > 0)
	{
		number[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}

	Colocamos o caractere nulo '\0' na última posição da string e movemos para a posição anterior
	decrementando len (len--).

	1) number[len--] = '\0': Coloca o caractere nulo '\0' no fim da string, indicando onde ela termina.
                             A variável len representa o índice do último caractere válido da string.
							 Não esquecer que a string precisa de espaço para todos os dígitos mais um 
							 que é o '\0'.

                             Como a alocação foi malloc(sizeof(char) * (len + 1)), temos uma posição extra
							 no fim do array.

                             Ao escrever number[len--] = '\0';, fazemos duas coisas ao mesmo tempo:

                              - Colocamos '\0' na última posição.

                              - Decrementamos len, para apontar agora para o último dígito a ser preenchido no loop.

	Preenchemos a string number de trás para frente (da direita para a esquerda), começando pelo 
	último dígito.

	2) while (len >= 0 && nbr > 0): Enquanto não ultrapassarmos o tamanho da string (len >= 0) e enquanto 
	                                ainda houver diigtos para processar (o) número for maior que zero (nbr > 0)), 
		                            continuamos a preencher a string.

	3) number[len--] = (nbr % 10) + '0': Aqui, obtemos o último dígito do número ao utilizar o operador módulo (%), que 
	                                     nos vai dar o resto da divisão por 10. 

                                         Ex: Se nbr = 123, então 123 % 10 = 3.

	                                     Depois, convertemos esse dígito para o caractere ASCII correspondente
	                                     adicionando '0' (o valor ASCII de '0' é 48, então, se pegarmos o dígito 3,
	                                     e fizermos 3 + '0', obtemos o caractere '3').
									     Isso é necessário porque estamos a trabalhar com números inteiros, e
	                                     queremos representá-los como caracteres.

	                                     O resultado é armazenado na posição number[len--], que é a posição
	                                     atual da string onde devemos colocar o dígito.
	                                     O len-- decrementa o índice para a próxima iteração, movendo-se
	                                     para a esquerda na string.

	 4) nbr /= 10:  Aqui, removemos o último dígito do número dividindo-o por 10.
	                Isso reduz o número para o próximo dígito a ser processado na próxima iteração.
	                Por exemplo, se nbr = 123, então 123 / 10 = 12.

	Quando terminamos, a string number contém a representação em string do número inteiro n.

	
    Exemplo: ft_itoa(123)

    nbr = 123, len = 3 (3 dígitos)

    Alocamos char *number = malloc(4); → espaço para "123" + \0

    Colocamos number[3] = '\0';

    Começamos de trás pra frente:

        123 % 10 = 3 → number[2] = '3'
        123 / 10 = 12

        12 % 10 = 2 → number[1] = '2'
        12 / 10 = 1

        1 % 10 = 1 → number[0] = '1'

    Resultado: "123"

    Exemplo: ft_itoa(-42)

    nbr = -42, len = 3 (1 para sinal, 2 para dígitos)

    Alocamos espaço para "−42\0"

    number[0] = '-'
    nbr = 42

    Escrevemos:

		number[3] = '\0'
        number[2] = '2'
        number[1] = '4'
		number[0] = '-'

    Resultado: "-42"


*/