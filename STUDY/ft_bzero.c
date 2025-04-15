void	ft_bzero(void *s, size_t n)
{
	size_t			idx;
	unsigned char	*buffer;

	idx = 0;
	buffer = (unsigned char *)s;
	while (idx < n)   // O loop continua enquanto não percorrermos todos os n bytes que queremos colocar a zero
		buffer[idx++] = 0;
}                                      

/*
SYNOPSIS
       #include <strings.h>

       void bzero(void s[.n], size_t n);

DESCRIPTION
       The bzero() function erases the data in the n bytes of the memory start‐
       ing  at the location pointed to by s, by writing zeros (bytes containing
       '\0') to that area.

RETURN VALUE
       None.


Em C, a memória não é automaticamente inicializada.

Quando declaramos uma variável, um array ou alocamos memória com malloc, o conteúdo da memória
pode ser qualquer coisa — valores aleatórios que estavam ali antes (chamado de "lixo de memória").
Quando alocamos memória com o malloc, ou até quando declaramos arrays locais, a memória
fornecida pode conter dados residuais (lixo de memória) que ficaram ali provenientes de execuções
anteriores ou de outras partes do programa. Estes dados não são apagados automaticamente —
são simplesmente reaproveitados. Se tentarmos usar essa memória diretamente, sem a inicializar, 
podemos obter resultados inesperados e até provocar comportamento indefinido.

Por exemplo, ao trabalhar com strings, é essencial que elas terminem com o caractere nulo ('\0'), 
pois funções como printf, strlen, strcpy, entre outras, continuam a ler a memória até encontrarem 
esse caractere. Se não garantirmos que a string esteja corretamente inicializada com \0 nos lugares
certos, o programa poderá ler para além da área alocada, acedendo a dados errados ou mesmo corrompendo
a memória.

Para resolver este problema, utilizamos funções como a bzero, e o seu objetivo é muito simples e direto:
escrever o valor zero em cada um dos bytes de uma determinada área de memória. Ela recebe um ponteiro
genérico (void *s) e um número n, e coloca n bytes seguidos dessa zona da memória com zero (0 ou '\0').
O efeito prático é que vai "limpar" completamente a área, tornando-a segura para uso.

De acordo com o manual, a função bzero apaga os dados dos n primeiros bytes de memória
que começa no endereço apontado por s, escrevendo os zeros (0, ou seja, o byte '\0') nesses
lugares. Ou seja, a função bzero é uma função que limpa uma área de memória, preenchendo-a com zeros.
É, assim,  uma função de manipulação de memória que é usada para colocar zeros (ou limpar)
num bloco de memória. bzero vai “limpar” a memória, substituindo o conteúdo anterior por zeros. 
Isto é útil, por exemplo, para garantir que uma string ou buffer não contenha lixo da memória
anterior.


1 - Parâmetros da função:

void	ft_bzero(void *s, size_t n)

    void *s: O parâmetro s é do tipo void*, o que significa que é um ponteiro genérico, ou seja,
			  ele não aponta para um tipo específico de dado. Isso permite que a função seja flexível
			  e possa trabalhar com qualquer tipo de dado, como char, int, structs, etc.
			  Na prática, isto significa que a função pode ser usada para limpar qualquer tipo de
			  bloco de memória, independentemente do tipo de dados que ele contém.
			  Por exemplo, se usássemos um tipo especifico como char *s, a função só poderia receber
			  arrays de char, mas com void *s, podemos passar qualquer tipo de ponteiro, desde que seja
			  convertido corretamente no interior da função.

			  Assim, o ponteiro s é um ponteiro genérico para o bloco de memória que será preenchido com
			  zeros (aponta para a zona da memória que queremos limpar). É o endereço inicial da região de
			  memória que será preenchida com zeros.
			  O tipo void * permite que a função aceite qualquer tipo de ponteiro (char *, int *,
			  unsgined char *, etc.), tornando a função genérica e reutilizável.
			  
    size_t n → O parâmetro n indica quantos bytes da memória apontada por s devem ser preenchidos com zero (0).
	           O tipo size_t é o tipo de dado (definido através da biblioteca <stddef.h> ou <stdlib.h>) que é usado
			   para representar tamanhos e quantidades de memória. Representa o tamanho máximo de qualquer objeto 
			   possível alocado na memória.
			   size_t é um tipo númerico sem sinal (unsigned), utilizado especificamente para medir tamanhos em bytes,
			   ou seja, é utilizado para contar quantos bytes há numa região memória.
			   É um alias para um tipo inteiro sem sinal (unsigned), definido pelo compilador, e garante ser
			   suficientemente grande para representar o tamanho de qualquer bloco de memória alocável.
			   O tamanho de size_t varia: pode ser 4 bytes (em sistemas 32-bit) ou 8 bytes (em sistemas 64-bit).

			   Por que usamos size_t no bzero? Porque vamos trabalhar com tamanhos de memória.

			   A função bzero tem como objetivo escrever n bytes com valor zero, a partir de um certo endereço de memória.
    		   Esse n deve ser um valor:

        	   		- Não negativo (logo, sem sinal)
         			- Grande o suficiente para cobrir qualquer alocação possível

				→ size_t é o tipo mais adequado para representar tamanhos de memória, pois é garantido que
				   ele pode armazenar o tamanho máximo de qualquer objeto alocável na memória.

				size_t é o tipo padrão e recomendado em C para qualquer situação em que estamos a lidar com quantidades de
				memória (bytes, tamanhos de arrays, alocações dinâmicas, etc).

				É o único tipo garantido pelo compilador para ser:

    			- Sem sinal
    			- Suficientemente grande
    			- Compatível com ponteiros
    			- Seguro contra erros de overflow ou valores negativos

	Tabela de comparação: tipos inteiros relevantes

	Tipo de Dado		Tamanho (32-bit)	Tamanho (64-bit)	Negativo?		Faixa de valores (32-bit)			Faixa de valores (64-bit)						Por que não usar no bzero?
		int					4 bytes				4 bytes			   Sim		  -2.147.483.648 a 2.147.483.647					Idem					Pode ser negativo — nunca usamos números negativos para contar bytes
	unsigned int			4 bytes				4 bytes			   Não				0 a 4.294.967.295							Idem					Limita o tamanho da memória — em 64-bit isso pode ser insuficiente
	unsigned long			4 bytes				8 bytes			   Não				0 a 4.294.967.295				0 a 18.446.744.073.709.551.615		O tamanho muda conforme a arquitetura — não é portátil
	unsigned long long		8 bytes				8 bytes			   Não			0 a 18.446.744.073.709.551.615					Idem					Funciona, mas é desnecessariamente grande em sistemas 32-bit — não ideal para portabilidade
		size_t				4 bytes				8 bytes			   Não				0 a 4.294.967.295				0 a 18.446.744.073.709.551.615		Feito exatamente para representar tamanhos de memória


2 - Variáveis: 

	size_t idx -> É o índice que percorre os bytes da memória. Indica quantos bytes já foram percorridos e
				  qual a posição atual no array de memória (o buffer). 
				  O tipo size_t é usado aqui porque ele é o tipo mais adequado e seguro para representar
				  tamanhos de memória.
				  O loop está a comparar idx < n, onde n é do tipo size_t.
				  Se idx fosse de outro tipo (como int), haveria risco de comparações entre tipos diferentes
				  → o que iria ativar warnings.
				  Como idx representa posições na memória (índices), e estamos a lidar com memória byte a byte,
				  size_t é o tipo ideal, pois:

    			  - É sem sinal (nunca será negativo)
    			  - Representa tamanhos de forma segura
				  - É compatível com o tipo de n (que também é size_t)
				  - Evita comparações entre tipos diferentes (o que poderia levar a erros de lógica)

	unsigned char *buffer -> É um ponteiro utilizado para percorrer a memória recebida por s e é assim usado para
							 manipulação segura da memória.
							 Ele é inicializado com o endereço de memória apontado por s, convertido para unsigned char*.
							 Isso permite acessar e modificar a memória byte a byte, garantindo que não haja problemas com
							 a manipulação de dados.

							Casting (Conversão de tipo):

		                    A função recebe como parâmetro um void *s, ou seja -> void	ft_bzero(void *s, size_t n);

							O que é void *? O tipo void * é um ponteiro genérico. Ou seja, ele pode apontar para qualquer tipo
							de dado, mas não podemos
							manipular diretamente (não pode ser desreferenciado diretaemnte) os dados que ele aponta sem saber
							o tipo de dado exato.
							Ou seja: não podemos fazer s[0] = 0 ou *s = 0 sem saber o tipo exato.
							Isso ocorre porque não sabemos a quantidade de memória que ele ocupa, nem como os dados são organizados.
						    
							Agora vejamos outra situação:

                            Em C, o tipo char é o menor tipo de dado possível (1 byte = 8 bits).
							Mas o char em si pode ser com sinal ou sem sinal, dependendo da implementação.

							Tabela Comparativa: char vs unsigned char

							Característica					char				unsigned char			Observações Técnicas
							   Tamanho		  			1 byte (8 bits)	  		1 byte (8 bits)			Ambos ocupam 1 byte
							Faixa de valores 			  -128 a 127			  0 a 255				char pode ser com sinal ou sem sinal, dependendo do sistema
							Representa byte puro?		Não completamente			Sim					unsigned char cobre todos os 256 valores possíveis
								Conversões				Pode causar problemas		Seguro				Usar unsigned char evita problemas de sinal

							
							Problemas com char (com sinal):

							Se usássemos char *buffer = (char *)s , o valor de cada byte poderia ser interpretado como negativo, pois o
							char tem faixa de -128 até 127.

							Isto é perigoso, porque: - não faz sentido pensar em bytes como negativos.
    												 - Se formos comparar ou manipular esses valores depois, podemos ter comportamentos
													   errados por causa do sinal.

							Por outro lado, unsigned char * é um tipo de ponteiro que aponta para 1 byte de dados e tem uma faixa de
							valores de 0 a 255 
							(o que representa todos os possíveis valores de 1 byte). 
							E é exatamente isso que precisamos quando manipulamos diretamente a memória, byte por byte. A memória é
							organizada em bytes (8 bits), e
							precisamos de garantir que o tipo usado para manipular a memória seja capaz de tratar valores byte por byte.

							Então por que fazemos o casting para unsigned char *? Pois queremos trabalhar byte a byte com a memória
							(1 byte = 1 unsigned char).
							Precisamos de converter o ponteiro genérico (void *) para um tipo acessível.
							Só o tipo unsigned char garante acesso direto à memória byte a byte.
    						unsigned char representa o byte puro, sem risco de sinal negativo.

							unsigned char *buffer;
							buffer = (unsigned char *)s;

							Estamos a dizer ao compilador que queremos tratar a memória de s como se fosse um array de bytes (unsigned char),
							onde cada posição do array
							será 1 byte de dados. Isto vai permiter acessar cada byte de forma precisa.

							Assim, o ponteiro buffer não é um array novo, ele é apenas um ponteiro que recebe o mesmo endereço que foi passado
							para a função bzero, ou seja, *s.
							Ele não copia os dados, ele apenas aponta para a mesma área de memória.
							Então, quando fazemos buffer[idx++] = 0, estamos a escrever 0 no endereço de memória que buffer aponta (que é o mesmo que s).
							Ou seja, buffer[idx++] = 0 é equivalente a s[idx++] = 0, mas com a vantagem de que buffer é um ponteiro para unsigned char,
							que é o tipo ideal para manipular bytes.							

							O que buffer representa na prática

							Imaginamos que temos uma variável assim:

							char arr[4] = {'A', 'B', 'C', 'D'};

							A memória pode estar assim:

							Endereço	Conteúdo	Interpretação
							0x1000		  0x41			'A'
							0x1001		  0x42			'B'
							0x1002		  0x43			'C'
							0x1003		  0x44			'D'

							Quando fazemos ft_bzero(arr, 4);

							Dentro da ft_bzero, s recebe o endereço &arr[0].
							
							Fazemos buffer = (unsigned char *)s;

							Agora buffer aponta para o mesmo endereço (0x1000).
							
							E o loop faz:

							buffer[0] = 0;  // 0x1000 ← 0x00
							buffer[1] = 0;  // 0x1001 ← 0x00
							buffer[2] = 0;  // 0x1002 ← 0x00
							buffer[3] = 0;  // 0x1003 ← 0x00

							Resultado na memória:

							Endereço	Conteúdo	Interpretação
							0x1000		  0x00			'\0'
							0x1001		  0x00			'\0'
							0x1002		  0x00			'\0'
							0x1003		  0x00			'\0'

							A variável arr agora foi zeroed. E isso foi feito com total controlo de cada byte, graças ao unsigned char.


 Edge Cases Handled:

    - If `n == 0`, the function does nothing and the memory block remains unchanged.
    - If `s == NULL`, behavior is undefined, as `bzero` does not check for `NULL` pointers.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>

        int main(void)
        {
            char str[10] = "Hello";
            ft_bzero(str + 3, 4);
            printf("After ft_bzero: '%s'\n", str);
            return 0;
        }

    Step 1: Memory Before `ft_bzero`

    - Initially, the memory block looks like this: 

        str:  ['H', 'e', 'l', 'l', 'o', '\0', ...]
                ^    ^    ^    ^    ^
              str[0] str[1] str[2] str[3] str[4] ...

    Step 2: Function Execution (`ft_bzero(str + 3, 4)`)

    - The function starts at `str[3]` and sets the next `4` bytes to zero:
    
        - `str[3] = 0`
        - `str[4] = 0`
        - `str[5] = 0`
        - `str[6] = 0`

    Step 3: Memory After `ft_bzero` Execution

    The memory block now looks like this:

        str:  ['H', 'e', 'l', '\0', '\0', '\0', '\0', ...]
                ^    ^    ^    ^    ^    ^    ^
              str[0] str[1] str[2] str[3] str[4] str[5] str[6]

    Step 4: Output

    The program will print:

    After ft_bzero: 'Hel'

    The function has zeroed out the memory starting from `str[3]`, replacing the characters `'l'`, `'o'`, and any 
    subsequent characters with `\0` (null terminators).

    - `ft_bzero` is a useful function when you need to clear or reset a portion of memory to zero.
    - It is commonly used to clear memory buffers or structures, especially when the content is no longer needed, or to 
      ensure security by erasing sensitive data.
  
  Alternative Approach Using `memset'
      
    Instead of manually looping through each byte, we can simplify `bzero` using `memset`:

        void	ft_bzero(void *s, size_t n)
        {
            ft_memset(s, 0, n);
        }

    Since `memset` already sets a block of memory to a specific value, passing `0` achieves the same effect as `bzero`.  

    Key Differences Between `bzero` and `memset` 
     
    - `bzero(s, n)` is equivalent to `memset(s, 0, n)`, but `bzero` is deprecated in some modern systems.
    - `memset` is more flexible because it allows setting memory to any value (`memset(s, 'A', n)`, for example).