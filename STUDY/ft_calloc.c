void	*ft_calloc(size_t nmemb, size_t size) // Função que aloca memória para um array de 'nmemb' elementos, cada um com 'size' bytes, e inicializa todos os bytes com zero.
{
	void	*buffer; // Ponteiro genérico que vai apontar para o bloco de memória alocado.

	if ((size != 0 && nmemb != 0) && nmemb > SIZE_MAX / size) // Verifica se haverá overflow na multiplicação: nmemb * size
		return (NULL); // Se houver risco de overflow, retorna NULL para evitar comportamento indefinido.

	buffer = malloc(nmemb * size); // Aloca o espaço de memória necessário: número de elementos vezes o tamanho de cada um.
	if (!buffer) // Se malloc falhar (ou seja, se retornar NULL)...
		return (NULL); // ...retorna NULL imediatamente.

	ft_memset(buffer, 0, nmemb * size); // Preenche toda a memória alocada com zeros usando a função ft_memset.
	return (buffer); // Retorna o ponteiro para a memória alocada e zerada.
}


/*
SYNOPSIS
       #include <stdlib.h>

       void *calloc(size_t nmemb, size_t size);

  calloc()
       The calloc() function allocates memory for an array of nmemb elements of
       size bytes each and returns a pointer to the allocated memory.  The mem‐
       ory  is  set  to  zero.   If nmemb or size is 0, then calloc() returns a
       unique pointer value that can later be successfully passed to free().

       If the multiplication of nmemb and size would result  in  integer  over‐
       flow,  then calloc() returns an error.  By contrast, an integer overflow
       would not be detected in the following call to malloc(), with the result
       that an incorrectly sized block of memory would be allocated:

           malloc(nmemb * size);

	RETURN VALUE
       The malloc(), calloc(), realloc(), and reallocarray() functions return a
       pointer to the allocated memory, which is suitably aligned for any  type
       that  fits  into  the requested size or less.  On error, these functions
       return NULL and set errno.  Attempting to allocate more than PTRDIFF_MAX
       bytes is considered an error, as an object that large could cause  later
       pointer subtraction to overflow.

1 - Parâmetros da função:

	void	*ft_calloc(size_t nmemb, size_t size)

    size_t nmemb: Este parâmetro representa o número de elementos a serem alocados. O tipo size_t 
				  é utilizado porque ele é adequado para representar os tamanhos de memória. O
				  size_t é sem sinal, o que significa que não pode ter valores negativos, o que é
				  importante ao trabalhar com alocações de memória, pois tamanhos negativos não são
				  válidos.

    size_t size: Este parâmetro representa o tamanho de cada elemento que será alocado. Também é do
	             tipo size_t porque, mais uma vez, estamos a lidar com tamanhos de memória e precisamos
				 garantir que o valor seja sem sinal e suficientemente grande para representar qualquer
				 tamanho de bloco de memória.

2 - Compreender a Implementação:

2.1 - Verificação de overflow - if ((size != 0 && nmemb != 0) && nmemb > SIZE_MAX / size)
    								return (NULL);

				> nmemb = número de elementos.
				> size = tamanho de cada elemento.
				> nmemb * size = quantidade total de memória a alocar.
				> SIZE_MAX = valor máximo que um size_t pode armazenar
				  (geralmente 2^64 - 1 em sistemas 64 bits).

      Antes de realizar a alocação de memória, verificamos se a multiplicação de nmemb 
	  (número de elementos) e size (tamanho de cada elemento) pode resultar num valor
	  que ultrapasse o valor máximo que pode ser representado por size_t (SIZE_MAX). 
	  Isso é feito para evitar o "overflow" durante a alocação de memória.
	  Se a multiplicação for muito grande, causando um valor maior que SIZE_MAX, 
	  retornamos NULL, indicando que a alocação falhou.

	  Como o if evita isso?

		A ideia é: Se nmemb > SIZE_MAX / size, então a multiplicação nmemb * size vai
		ultrapassar SIZE_MAX.

		Exemplo:

		SIZE_MAX = 100
		size = 20
		SIZE_MAX / size = 5

		Assim, se nmemb > 5, então nmemb * size será maior que 100 → o que resulta num overflow!

      A verificação (size != 0 && nmemb != 0) é realizada para garantir que nem o número
	  de elementos nem o tamanho de cada elemento sejam zero. Se um deles for zero, não 
	  faria sentido tentar alocar memória, pois o tamanho total seria igualmente zero e a 
	  alocação falharia.

2.2 - Alocação de memória - buffer = malloc(nmemb * size);

	  Se a verificação de overflow passar, alocamos memória ao utilizar a função malloc. 
	  O malloc é usada para alocar um bloco de memória do tamanho total, que é a multiplicação
	  de nmemb e size.

      A função malloc recebe o total de bytes que queremos reservar.
      nmemb * size é o total: número de elementos (nmemb) × tamanho de cada elemento (size).

	  O resultado do malloc é um ponteiro para o início da área de memória alocada. Esse ponteiro
	  é armazenado no buffer.
	  O resultado é armazenado no ponteiro buffer e ele vai conter o endereço do bloco de memória
	  alocado.
	  O malloc retorna um ponteiro para o bloco de memória alocado ou NULL se a alocação falhar. 

	  A alocação de memória em C é feita através de funções como malloc e o calloc.
	  Estas funções são usadas para solicitar ao sistema um bloco de memória do tamanho desejado.
	  O malloc e o calloc são usados para alocar memória dinâmica, que pode ser libertada posteriormente
	  com a função free.
	  A diferença entre eles é que o malloc não inicializa a memória alocada, enquanto o calloc inicializa
	  a memória com zeros.

	  > malloc: Aloca um bloco de memória contínuo com size bytes do tamanho especificado (size bytes), mas
	            não inicializa os bytes, ou seja não inicializa a memória alocada - o conteúdo será
				indefinido/lixo.
	  > calloc: Aloca memória para um array de nmemb elementos, cada um com size bytes, e inicializa todos os
	            bytes a zero. Ou seja, o calloc não só aloca a memória, mas também garante que todos os bytes
				da memória alocada sejam inicializados a zero. Isso é útil para evitar comportamentos indesejados
				ou vulnerabilidades de segurança, pois a memória inicializada com zero é mais segura para uso imediato.

2.3 - Preenchimento com zeros - ft_memset(buffer, 0, nmemb * size);

	  Após a alocação de memória, usamos a função ft_memset para preencher o bloco de memória alocado
	  com zeros.
	  O ft_memset é uma função que preenche um bloco de memória com um valor específico (neste caso, zero).
	  O ponteiro buffer aponta para o início do bloco de memória e o tamanho do bloco é nmemb * size.
	  Isso garante que todos os bytes do bloco de memória alocado sejam inicializados com zero, o que é
	  útil para evitar comportamentos indesejados ao usar a memória alocada, como lixo de memória ou valores
	  não inicializados.

	  Vamos ver um exemplo prático de como essa função pode ser usada:

	  int *arr = ft_calloc(5, sizeof(int));

	  Aqui, estamos a alocar memória para 5 elementos do tipo int. Como cada int geralmente ocupa 4 bytes 
	  (dependendo da arquitetura), a função malloc alocará 5 * 4 = 20 bytes de memória.
	  A função ft_calloc vai garantir que a memória alocada seja inicializada com zeros.
      Assim, função ft_memset vai garantir que cada byte desse bloco de memória seja inicializado com o 
	  valor zero, ou seja, todos os valores de arr serão zero.
	  O ponteiro arr vai, assim, receber o endereço do bloco de memória alocado na função ft_calloc.
	  
2.4 - Retorno do ponteiro - return (buffer);

	  Finalmente, retornamos o ponteiro buffer, que agora aponta para o bloco de memória alocado e 
	  inicializado/preenchido com zeros.Podemos usar este ponteiro para acessar à memória alocada.
	  

4 - Considerações de segurança e desempenho:

    Verificação de overflow: A verificação de overflow antes da alocação é uma prática importante para evitar
	                         problemas de alocação que podem ocorrer em sistemas com limitações de memória.

    Inicialização com zero: A inicialização com 0 garante que a memória alocada seja segura para uso, já que
	                        pode ser interpretada como memória "limpa" e não vai conter valores "aleatórios" de 
							lixo que poderiam causar comportamentos inesperados ou vulnerabilidades de segurança.

    Edge Cases Handled:

    - If either `nmemb == 0` or `size == 0`, the function returns `malloc(0)`.
    - If `nmemb * size` exceeds the maximum allowed value for `size_t`, it returns `NULL`.
    - If memory allocation fails, it returns `NULL`.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>
        #include <stdlib.h>

        int main(void)
        {
            size_t nmemb = 5;
            size_t size = sizeof(int);
            int *arr = ft_calloc(nmemb, size);

            if (arr)
            {
                for (size_t i = 0; i < nmemb; i++)
                {
                    printf("arr[%zu] = %d\n", i, arr[i]);
                }
                free(arr);
            }
            return 0;
        }

    Step 1: Memory Allocation

    - The function allocates space for an array of `5` integers (each of size `sizeof(int)`).

    Step 2: Memory After Allocation (Initialized to Zero)

    The memory allocated looks like this:

        arr:  [0, 0, 0, 0, 0]
               ^  ^  ^  ^  ^
               arr[0] arr[1] arr[2] arr[3] arr[4]

    Each element is initialized to zero.

    Step 3: Output

    The program will print:

        arr[0] = 0
        arr[1] = 0
        arr[2] = 0
        arr[3] = 0
        arr[4] = 0

    - `ft_calloc` is essential for allocating and initializing memory to zero, commonly used for initializing arrays 
      or buffers before use.
    - The function safely handles edge cases like zero-sized allocations and overflow during multiplication.

     Key Differences Between `malloc` and `calloc`:
    
    - `malloc` only allocates memory but does NOT INITIALIZE it. The memory may contain garbage values.
    - `calloc`, on the other hand, ALLOCATES AND INITIALIZES the memory to zero, making it safer to use right after
       allocation.

*/