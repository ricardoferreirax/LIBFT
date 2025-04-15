void	*ft_memset(void *s, int c, size_t n)  // Função que preenche os 'n' primeiros bytes da memória apontada por 's' com o valor 'c'.
{
	size_t			idx;  // Variável de controle do índice para percorrer a memória.
	unsigned char	*tmp_s;  // Ponteiro para os dados de memória, que serão manipulados byte a byte.

	idx = 0;  // Inicializa o índice como 0.
	tmp_s = (unsigned char *)s;  // Converte o ponteiro 's' (do tipo void *) para 'unsigned char *', já que a função vai trabalhar byte a byte.

	while (idx < n)  // Laço que percorre os primeiros 'n' bytes da memória.
		tmp_s[idx++] = (unsigned char)c;  // Atribui o valor 'c' (convertido para 'unsigned char') ao byte de memória apontado por 'tmp_s[idx]', e incrementa o índice.
	
	return (s);  // Retorna o ponteiro original 's', como indicado pelo protótipo da função.
}


/*

SYNOPSIS
       #include <string.h>

       void *memset(void s[.n], int c, size_t n);

DESCRIPTION
       The memset() function fills the first n bytes of the memory area pointed
       to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.


1 - Parâmetros da função  -  void *ft_memset(void *s, int c, size_t n)

    void *s: é o ponteiro para o bloco de memória a ser modificado. 
	         O tipo void * é um ponteiro genérico, o que significa que ele pode apontar para 
			 qualquer tipo de dado. Ou seja, a função ft_memset pode ser utilizada para preencher
			 qualquer tipo de memória, seja para um array de inteiros, uma string, ou qualquer outro
			 tipo de dado. A função, portanto, pode preencher qualquer tipo de memória com um valor 
			 especificado.

			 Em C, o tipo void * permite que a função seja genérica. Isso é útil porque a função pode ser
			 usada para manipular diferentes tipos de dados com a mesma implementação. Quando usamos void *,
			 precisamos de fazer um cast (como a conversão para unsigned char * dentro da função) para que o
			 compilador saiba como tratar os dados na memória.

    int c: representa o valor que será atribuído a cada byte da memória. Este valor será o que função irá
	       preencher nos bytes do bloco de memória apontado por s.
	 	   Embora o tipo do parâmetro seja um inteiro (int), ele será convertido para unsigned char dentro
		   da função porque a funçao opera byte a byte na memória. A converao é feita de modo a garantir que 
		   o valor seja tratado como um byte único (já que um unsigned char ocupa exatamente um byte).
		   Assim, a função lida com bytes de memória, e o valor de cada byte é limitado de 0 a 255. 
		   A conversão garante que o valor seja armazenado corretamente como um byte.
		  
		   Exemplo de uso:

		   ft_memset(arr, 'X', 3);

		   Neste caso, 'X' tem o valor ASCII 88, que será o valor usado para preencher os primeiros 3 bytes de arr.

		   Nota: Quando usamos a função com valores como 'X' ou 'A', esses caracteres são convertidos para seus
		         respectivos códigos ASCII (neste caso, 'X' = 88 e 'A' = 65).

    size_t n: indica o número de bytes que serão preenchidos com o valor c. 
	          O tipo size_t é adequado para representar tamanhos de objetos na memória e garante que o número de
			  bytes seja positivo e compatível com o tamanho do sistema.
			  O size_t é adequado para contar a quantidade de memória, já que o tamanho de objetos na memória pode ser
			  muito grande, especialmente em sistemas de 64 bits. O uso de size_t garante que a função funcione
			  corretamente em diferentes plataformas e arquiteturas, sem risco de overflow do inteiro ou problemas de
			  compatibilidade.

			  A função ft_memset vai iterar sobre n bytes de memória, alterando o valor de cada um para o valor 
			  passado em c.
			  Se n for 5, por exemplo, a função preencherá 5 bytes de memória com o valor c.

			  Exemplo de uso:

			  ft_memset(arr, 'X', 3);

			   Aqui, n = 3, o que significa que a função ft_memset preencherá os primeiros 3 bytes de arr com o valor 'X'.


2 - Compreender a Implementação:

2.1 - Conversão do Ponteiro:

	unsigned char *tmp_s;
	tmp_s = (unsigned char *)s;

	A função ft_memset recebe o parâmetro s como um ponteiro void *, que é um ponteiro genérico, ou seja, ele pode
	apontar para qualquer tipo de dado. O void * é utilizado quando queremos que uma função que manipule qualquer 
	tipo de dado na memória, sem saber o tipo de antemão.
	O problema do tipo void *: é genérico e não permite acessar diretamente os dados na memória para podermos
	modificá-los, pois o compilador não sabe o tipo de dado apontado por ele. Ou seja, não podemos utilizar o
	ponteiro void * diretamente para acesar a memória e modificar os dados.

	Para acessar a memória corretamente, precisamos de converter o ponteiro void * para um tipo especifico, que,
	neste caso, é unsigned char *. 
	Na função ft_memset, queremos manipular a memória byte a byte. Por isso, usamos o tipo unsigned char, pois ele
	ocupa exatamente 1 byte, que é a unidade mínima de memória manipulada na função.
	Ao usar um unsigned char *, garantimos que o ponteiro desloque se em passos de 1 byte um por um, o que é
	necessário para preencher a memória corretamente. A conversão é feita para garantir que estamos a acessar e a
	manipular a memória de maneira eficiente e precisa.

	Ao utilizar o cast (unsigned char *), estamos a dizer ao compilador: "Eu sei que o ponteiro s é genérico, mas
	eu quero tratá-lo como se ele fosse um ponteiro para unsigned char, que aponta para um tipo de dado de 1 byte."
	Isso permite-nos acessar cada byte da memória de maneira segura, sem depender do tipo de dado original.

	Em C, o char é um tipo de dado que ocupa 1 byte de memória. O char pode ser signed (com sinal) ou unsigned 
	(sem sinal).
    Unsigned char é um tipo de dado que ocupa um 1 byte sem sinal, o que significa que ele pode armazenar valores
	de 0 até 255 (em vez de -128 a 127, como um signed char).
	Por exemplo, um valor do tipo unsigned char pode ser qualquer número entre 0 e 255, o que é útil para 
	representar dados binários ou caracteres de forma mais genérica.

    tmp_s: O ponteiro tmp_s é declarado como unsigned char * para garantir que a manipulação da memória
	       seja feita byte a byte.
		   O papel de tmp_s na função ft_memset é apontar para o bloco de memória que será preenchida 
		   com o valor desejado (no caso, o valor de c, que será copiado para cada byte da memória).
		   A variável tmp_s não é um valor direto, mas sim um endereço de memória onde está armazenado um 
		   valor do tipo unsigned char. Em vez de armazenar diretamente um valor de unsigned char, ela vai
		   armazenar o endereço de memória onde o valor está contido.
		   A conversão é feita para que possamos acessar a memória byte a byte. Não podemos esquecer que
		   unsigned char é um tipo de dado de 1 byte, então cada índice do ponteiro tmp_s vai acessar um
		   byte da memória. Isto é necessário porque queremos modificar cada byte da memória com o valor de c.

		   Assim, o unsigned char *tmp_s é um ponteiro para um tipo unsigned char. Ele será usado para acessar
		   ou manipular os valores armazenados numa área de memória específica, byte por byte.

		   Após esta conversão, depois que tmp_s aponta para a memória que queremos manipular, podemos usar o ponteiro 
		   para acessar e modificar cada byte da memória apontada por s. 
	       O código dentro da função percorre esses bytes, um por um, e define o seu valor.

2.2 - Preenchendo a Memória:

	while (idx < n)
    	tmp_s[idx++] = (unsigned char)c;

	O objetivo deste while é preencher um bloco de memória com um determinado valor, byte a byte, usando o
	ponteiro tmp_s, que aponta para o início da memória que queremos modificar.

	Aqui, a variável tmp_s é usada para acessar o índice idx do bloco de memória ao qual tmp_s aponta.

    	> while (idx < n): Este laço while é usado para iterar sobre os n bytes de memória, preenchendo cada byte
	                       com o valor de c. A variável idx começa em 0 e é incrementada até atingir n, o número de
					       bytes a serem preenchidos.
					       Quando idx == n, significa que já preenchemos todos os bytes necessários, e o laço termina.

	    > [idx++]: A cada iteração do loop, tmp_s é usado para acessar um byte específico
				   da memória. O valor de idx é incrementado para apontar para o próximo 
				   byte da memória. Então, tmp_s[0], tmp_s[1], etc., acessam os primeiros,
			   	   segundos e terceiros bytes da memória.

		> (unsigned char)c: O valor de c é um int mas queremos armazená-lo num array de bytes 
	                       (unsigned char *). O tipo int pode ter mais do que 1 byte, e queremos
					       garantir que estamos a armazenar apenas o byte correspondente ao valor
						   de c na memória.
						   O casting para unsigned char garante que estamos apenas a selecionar o byte
						   com o valor adequado (no intervalo de 0 a 255, já que unsigned char é um tipo
						   de dado de 1 byte).
						   A função memset vai preencher, assim, a memória com um valor específico
						   (no caso, c) que é do tipo unsigned char.

						   Por exemplo, Se o valor de c for, por exemplo, 257 (em int), ao fazer o cast para
						   unsigned char, o valor será reduzido para 1 (porque 257 % 256 = 1, já que unsigned
						   char tem a capacidade para armazenar apenas valores de 0 a 255).
													    	
        > tmp_s[idx++] = (unsigned char)c;: Enquanto não preenchermos todos os bytes necessários, o byte de memória no índice idx
									        é preenchido com o valor c, que foi convertido para unsigned char (garantindo que ele
									        seja tratado como um byte). O índice idx é incrementado após cada iteração, o que permite
									        preencher os bytes consecutivos.

											Isso faz duas coisas ao mesmo tempo:

    										Atribuição: O valor (unsigned char)c é colocado no byte de posição idx do bloco de memória.
    										Incremento: Após a atribuição, o valor de idx é aumentado em 1, para apontar para o próximo byte.
	  	
		Exemplo:

	    s aponta para uma área de 4 bytes na memória.
   		c = 65 (que representa o caractere 'A' na tabela ASCII).
   		n = 4 → queremos preencher 4 bytes com 'A'.

		Inicialmente:

		idx = 0;
		tmp_s = (unsigned char *)s; // Aponta para o início da memória

		1ª Iteração:  idx = 0    Atribui: tmp_s[0] = 65    Incrementa: idx = 1

		2ª Iteração:   idx = 1   Atribui: tmp_s[1] = 65    Incrementa: idx = 2

		3ª Iteração:   idx = 2   Atribui: tmp_s[2] = 65    Incrementa: idx = 3

		4ª Iteração:   idx = 3   Atribui: tmp_s[3] = 65    Incrementa: idx = 4

		Fim do loop: Agora idx = 4 → idx == n, então o while termina.

		Se antes a memória tivesse valores aleatórios (lixo), agora os primeiros 4 bytes
		foram preenchidos com o valor 65, que representa 'A'.

		Bloco de memória depois do ft_memset:  [ 'A' ][ 'A' ][ 'A' ][ 'A' ]

2.3 - Retorno do Ponteiro:

	return (s);

    Após preencher os n bytes de memória com o valor c, o ponteiro original s é retornado. 
	Isso permite que o código que chamou ft_memset continue a usar o ponteiro sem precisar de mais referências.
    Motivo do retorno do ponteiro original: A prática de retornar o ponteiro original é comum em funções que 
	manipulam ponteiros em C. Isso pode ser útil para permitir encadeamento de chamadas de funções ou simplesmente
	para garantir que a referência à memória alocada seja preservada.

3 - Exemplo Passo a Passo

	Vamos entender como a função ft_memset funciona em um exemplo concreto.

	char arr[5] = {'A', 'B', 'C', 'D', 'E'};
	ft_memset(arr, 'X', 3);

3.1 - Inicialização

    O array arr contém os valores {'A', 'B', 'C', 'D', 'E'}. Cada caractere ocupa 1 byte de memória.
    A função ft_memset é chamada para preencher os 3 primeiros bytes do array com o valor 'X'.

3.2 - Execução da Função

    Conversão do ponteiro: O ponteiro arr é convertido para unsigned char * e armazenado em tmp_s,
	                       permitindo o acesso byte a byte.

    Primeira iteração (idx = 0): O primeiro byte de arr[0] é alterado para o valor 'X' (código ASCII 88).
                                 A memória de arr agora é {'X', 'B', 'C', 'D', 'E'}.

    Segunda iteração (idx = 1): O segundo byte de arr[1] é alterado para 'X'.
                                A memória de arr agora é {'X', 'X', 'C', 'D', 'E'}.

    Terceira iteração (idx = 2): O terceiro byte de arr[2] é alterado para 'X'.
                                 A memória de arr agora é {'X', 'X', 'X', 'D', 'E'}.

    A função termina após a terceira iteração, já que n = 3 e o laço while termina quando idx atinge 3.

3.3 - Resultado Final

	  O conteúdo do array arr após a execução de ft_memset será: {'X', 'X', 'X', 'D', 'E'}
      Os três primeiros caracteres foram substituídos por 'X', enquanto os dois últimos ('D' e 'E')
	  permaneceram inalterados.

4 - Considerações de Segurança e Desempenho

    Segurança: A função ft_memset garante que a memória seja preenchida com um valor específico 
	           (zero no caso de inicialização com zero). Isso evita que dados não inicializados ou 
			   "lixo" de memória causem comportamentos inesperados, como falhas ou vulnerabilidades
			    de segurança.

    Desempenho: A função usa um laço simples para preencher a memória byte a byte. Embora não seja a 
	            solução mais rápida possível (alguns sistemas podem usar otimizações de hardware para
				operações de memória), ela é eficaz e segura para garantir que a memória seja preenchida
				corretamente.

    Uso de Ponteiro void *: O uso de void * como tipo do ponteiro de entrada permite que a função seja 
	                        genérica, permitindo o preenchimento de qualquer tipo de memória. Isso é útil 
							para uma ampla gama de aplicações, como manipulação de buffers ou arrays de 
							diferentes tipos de dados.


Example Usage:

    Suppose we have the following code:

        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            char str[10] = "HelloWorld";
            ft_memset(str, '*', 5);
            printf("%s\n", str);
            return 0;
        }

    Step 1: Understanding the Arguments

    - `str` is an array: `['H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
    - `c` is `'*'` (ASCII `42`), so we will replace bytes with `'*'`.
    - `n` is `5`, meaning we replace the first **5** characters.

    Step 2: Memory Before `ft_memset` Execution

        Index:    0    1    2    3    4    5    6    7    8    9
        Data:   ['H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']
                  ^    ^    ^    ^    ^    
                  s    s+1  s+2  s+3  s+4  (first 5 bytes to be replaced)

    Step 3: Filling Memory with `'*'`

    - The function sets:

        - `str[0] = '*'` → `['*', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[1] = '*'` → `['*', '*', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[2] = '*'` → `['*', '*', '*', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[3] = '*'` → `['*', '*', '*', '*', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[4] = '*'` → `['*', '*', '*', '*', '*', 'W', 'o', 'r', 'l', 'd']`

    Step 4: Memory After `ft_memset` Execution

        Index:    0    1    2    3    4    5    6    7    8    9
        Data:   ['*', '*', '*', '*', '*', 'W', 'o', 'r', 'l', 'd']
                  ^    ^    ^    ^    ^
                (first 5 bytes replaced with '*')

    Step 5: Output

      printf("%s\n", str); // Output: "*****World"

*/