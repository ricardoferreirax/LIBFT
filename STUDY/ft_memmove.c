void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	size_t			idx;

	if (!dest || !src)
		return (NULL);
	tmp_src = (const unsigned char *)src;
	tmp_dst = (unsigned char *)dest;
	if (tmp_dst > tmp_src)
	{
		while (n-- > 0)
			tmp_dst[n] = tmp_src[n];
	}
	else if (tmp_dst < tmp_src)
	{
		idx = 0;
		while (idx < n)
		{
			tmp_dst[idx] = tmp_src[idx];
			idx++;	
		}
	}
	return (dest);
}

/*

SYNOPSIS
       #include <string.h>

       void *memmove(void dest[.n], const void src[.n], size_t n);

DESCRIPTION
       The  memmove()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas may overlap: copying takes place as  though
       the  bytes  in src are first copied into a temporary array that does not
       overlap src or dest, and the bytes are then copied  from  the  temporary
       array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.


Objetivo da ft_memmove:  Copia n bytes da área da memória apontada por src para a área 
                         de memória apontada por dest, permitindo que essas àreas se
						 sobreponham mesmo que as áreas se sobreponham (o que a diferencia
						 de funções como ft_memcpy, que não garante a correta cópia no caso
						 de sobreposição).

1 - Parâmetros da função   -  void *ft_memmove(void *dest, const void *src, size_t n);

1.1 - void *dest: é o ponteiro para a àrea da memória de destino para onde os bytes serão copiados,
                  ou seja, para onde os n bytes da memória serão transportados.
				  Como void * é um ponteiro genérico, pode apontar para qualquer tipo de dado.
				  A função ft_memmove vai modificar os dados para onde dest aponta, pois está a
				  copiar os valores para lá, ou seja, a função vai escrever os dados neste endereço, 
				  por isso não é const como o ponteiro *src.
                  Como não sabemos o tipo exato dos dados, precisamos de converter este ponteiro
				  para unsigned char * dentro da função, para podermos acessar e copiar byte a byte.

1.2 - const void *src: é o ponteiro para a àrea da memória de origem da qual os bytes serão lidos e
                       posteriormente copiados para a àrea da memória apontada por dest.
                       O tipo void * é um ponteiro genérico, ou seja, um ponteiro que pode apontar para
					   qualquer tipo de dado. Assim, não podemos diretamente acessar os dados de
					   um void * porque o tipo void não tem um tamanho definido.

					   O modificador const é usado para indicar que a variável (ou o conteúdo para
					   onde a variável aponta) não pode ser alterado. Portanto, quando temos um ponteiro
					   const void *, isso significa que a função não pode modificar os dados para onde o
					   ponteiro src está a apontar.
					   No contexto de const void *src, a função que recebe esse ponteiro só pode ler os
					   dados apontados por src e não pode modificá-los. Isso é útil para garantir que os 
					   dados originais não sejam alterados inadvertidamente dentro da função.
					   
					   Assim, o tipo const void *src é usado quando a função precisa de ler os dados de uma
					   origem, mas não precisa modificá-los. Isto ajuda a garantir que os dados da origem
					   (no caso, src) permanecem inalterados.

                       Por exemplo, na função ft_memmove, a função pode copiar dados da origem (src) para 
					   o destino (dest) sem alterar os dados da origem. O modificador const impede que a 
					   função altere os dados na src enquanto faz a cópia.

                       A conversão para const unsigned char * é necessária para acessar os dados byte a 
					   byte corretamente.

1.3 - size_t n: é o número de bytes a serem copiados ou movidos da memória de origem (src) 
                para a memória de destino (dest).
				A ft_memmove copia n bytes da àrea de memória apontada por src para a àrea
				memória apontada por dest.
				O tipo size_t é um tipo de dado sem sinal, que é usado para representar 
				tamanhos de memória em C. É geralmente utilizado para armazenar tamanhos de 
				objetos em memória, como o número de bytes de um bloco de memória.
                O motivo de usar size_t para representar tamanhos e contagens de memória é 
				que ele é adaptado ao sistema (32 bits ou 64 bits), garantindo que possa 
				armazenar tamanhos de memória grandes o suficiente para plataformas modernas.

                Por exemplo, em sistemas de 64 bits, size_t é geralmente um unsigned long de 64 bits,
				enquanto em sistemas de 32 bits, é um unsigned int de 32 bits.

2 - Compreender a Implementação

2.1 - Conversão dos Ponteiros

  unsigned char *tmp_dst = (unsigned char *)dest;
  const unsigned char *tmp_src = (const unsigned char *)src;

  As variáveis tmp_src e tmp_dst são ponteiros auxiliares que facilitam o acesso à memória, garantindo que
  a função trabalhe de forma correta com src e dest.

  tmp_dst: é o ponteiro para a área de memória de destino (onde vamos copiar os dados de src).

  tmp_src: é o ponteiro para a área de memória de origem (de onde os dados serão copiados para dest).

  unsigned char: O tipo unsigned char é um tipo de dado que representa um único byte (8 bits) de memória. 
                 A principal razão para usar unsigned char é que ele garante que o valor armazenado será 
				 sempre positivo, que varia de 0 a 255.

  Quando estamos a manipular a memória byte a byte, como é o caso em funções como ft_memmove, é fundamental 
  tratar os dados como uma sequência de bytes. Como char pode ser conter valores negativos, usar unsigned 
  char elimina a possibilidade de confusão com números negativos, garantindo que qualquer valor de cada byte
  possa ser representado corretamente.

  tmp_src = (const unsigned char *)src: src é do tipo const void *, que é um ponteiro genérico. Não podemos
                                        acessar diretamente os dados da memória apontada por src, porque não
										sabemos qual é o tipo dos dados. Então, precisamos de "converter" o 
										ponteiro src para um tipo de ponteiro mais específico para que possamos
										acessar os bytes da memória corretamente.
										O tipo unsigned char é escolhido porque a função ft_memmove trabalha byte 
										a byte, e cada byte é representado por um valor entre 0 e 255, o que é
										garantido pelo tipo unsigned char.
                                        O const é mantido, pois src é uma área da memória de leitura apenas. Isso
										significa que a função não deve modificar os dados de src, apenas lê-los.

                                        Resultado: A variável tmp_src agora é um ponteiro para const unsigned char,
										que vai permitir que percorramos e acessemos os bytes de src de forma segura,
										byte por byte.

	tmp_dst = (unsigned char *)dest: dest é do tipo void *, ou seja, um ponteiro genérico. Para trabalhar com
	                                 ele, precisamos de convertê-lo para um tipo específico que nos permita acessar
									 os bytes da memória. O tipo unsigned char também é usado para a àrea de memória
									 apontada por dest por uma razão similar: a função vai manipular a memória byte a byte.

                                     Não usamos const aqui, porque dest é a área de memória de destino, onde os dados serão
									 copiados, ou seja, os dados de dest podem ser modificados.

                                     Resultado: A variável tmp_dst agora é um ponteiro para unsigned char, o que nos permite 
									 modificar os dados da àrea da memória apontada por dest durante a execução da função.

2.2 - Sobreposição (Overlapping) - Copiar de trás para a frente

	if (tmp_dst > tmp_src)
	{
    	while (n-- > 0)
        	tmp_dst[n] = tmp_src[n];
	}

	Esta parte é responsável por garantir a cópia de dados da memória de src para dest de maneira correta,
	especialmente quando há sobreposição de memória (ou seja, quando as duas áreas de memória se sobrepõem).

	if (tmp_dst > tmp_src): condição compara os endereços de memória das áreas dest e src. A razão para essa
	                        comparação é que a função ft_memmove precisa de lidar corretamente com áreas de 
							memória sobrepostas. Se dest e src se sobrepõem, ou seja, se há uma parte da memória 
							de dest que se sobrepõe à parte da memória de src, isso pode causar problemas durante
							a cópia. Para evitar a sobreposição de dados, precisamos decidir a ordem correta da cópia.

                            Se tmp_dst > tmp_src, isso significa que dest está "à frente" de src na memória, ou seja, 
							dest começa após src. Nesse caso, a cópia dos dados deve ser feita de trás para frente, para
							garantir que os dados de src não sobrescrevam os dados de dest antes de serem copiados.
							OU seja, significa que as áreas de memória src e dest se sobrepõem, e a cópia precisa de ser 
							feita de trás para frente para evitar sobrescrever dados antes que eles sejam copiados.

                            Se tmp_dst <= tmp_src, significa que dest está "antes" de src ou num lugar não sobreposto. 
							Neste caso, podemos copiar os dados de src para dest diretamente de frente para trás.

	while (n-- > 0): se tmp_dst > src, o loop while vai percorrer os bytes de src e dest de trás para a frente, copiando
	                 os dados.
					 Primeiro a comparação é feita (verificando se n > 0), e depois o valor de n é decrementado.
                     n-- > 0: Esse é o teste condicional que verifica se n é maior que 0. O loop vai continuar enquanto
					 n for maior que 0.

                     Inicialmente, n representa o número de bytes a serem copiados. À medida que o loop percorre os bytes
					 de src e dest, o valor de n vai diminuindo.

					 O loop começa com o valor de n e vai ser decrementado até chegar a 0. Em cada iteração do loop, o 
					 valor de n é usado para acessar a posição correspondente nos ponteiros tmp_dst e tmp_src.

                     tmp_dst[n] = tmp_src[n]: Aqui, é feita a copia do valor do byte em src (em tmp_src[n]) para o byte
					 correspondente em dest (em tmp_dst[n]).

                     O uso de n aqui é crucial porque, ao percorrermos de trás para frente, os índices n vão ser mapeados para
					 a última posição da área de memória e vão diminuindo à medida que o loop continua. Isso garante que os dados
					 sejam copiados sem sobrescrever as posições anteriores de dest antes que os dados de src tenham sido copiados
					 para lá.
                     
					 Em C, tudo o que está armazenado (variáveis, arrays, estruturas, etc.) fica guardado num certo endereço de memória. 
					 Imaginemos a memória:

					  Endereço:   1000   1001   1002   1003   1004   1005   1006   ...
					  Conteúdo:   'a'    'b'    'c'    'd'    'e'    ...     ...

                     Cada byte ocupa uma casa. E os ponteiros em C (como src e dest) apontam para essas casas.

                     char str[] = "abcdef";

                     Este array está na memória assim:        Índice	Conteúdo	Endereço (exemplo)
                                                                0	      'a'	           1000
                                                                1	      'b'	           1001
                                                                2	      'c'	           1002
                                                                3	      'd'	           1003
                                                                4	      'e'	           1004
                                                                5	      'f'	           1005

                     Agora vamos fazer isto:   ft_memmove(str + 2, str, 4);

                     src = str → começa na posição str[0] e aponta para 'a' (endereço 1000).
                     dest = str + 2 → começa na posição str[2] e aponta para 'c' (endereço 1002).
                     
					 Bytes a copiar: 4 (ou seja, str[0], str[1], str[2], str[3] → 'a', 'b', 'c', 'd')
					 Vamos copiar 4 bytes: 'a', 'b', 'c', 'd' (endereços 1000 a 1003) para os 4 bytes a
					 partir de 1002, ou seja, vamos iniciar a cópia a partir da posição donde começa 'c'.
                     Ou seja: copiar de 1000 a 1003 para 1002 a 1005

                     Agora reparemos: dest > src, porque 1002 > 1000.

                     Como há sobreposição, e vamos copiar para um local que está à frente na memória, temos de
					 copiar de trás para frente, senão sobrescrevemos os dados antes de copiar.

                     Por que copiar de trás para frente?

                     Vamos ver o que poderia correr mal se copiássemos de frente para trás:

                     Copiamos 'a' de src[0] (1000) para dest[0] (1002) → OK.
                     Agora src[1] (1001) ainda tem 'b', copiamos para dest[1] (1003) → OK.
                     MAS: src[2] é 1002, que já foi alterado na etapa 1! Já não é 'c', agora é 'a'.

                     Por isso, ao copiar de frente para trás, podemos perder dados importantes, porque estamos a 
					 escrever por cima de dados que ainda precisamos de copiar.

					 Assim, com o ft_memmove, como a comparação tmp_dst > tmp_src é verdadeira, pois tmp_dst aponta para uma área de memória
					 depois de tmp_src, o loop então começa a copiar os dados de src para dest de trás para frente:

					 Representação da memória antes da cópia:  [1000] a
                                                               [1001] b
                                                               [1002] c
                                                               [1003] d
                                                               [1004] e
                                                               [1005] f

                     - No primeiro passo (quando n = 4), a função copia o último byte de src (tmp_src[3] -> 1003, que é 'd') para o último byte 
					   de dest (tmp_dst[3] -> 1005).
                     - No segundo passo (quando n = 3), a função copia o penúltimo byte de src (tmp_src[2] -> 1002, que é 'c') para a posição 
					   anterior de dest (tmp_dst[2] -> 1004).
                     - No terceiro passo (quando n = 2), a função copia o terceiro byte de src (tmp_src[1] -> 1001, que é 'b') para a posição 
					   correspondente em dest (tmp_dst[1] -> 1003).
                     - No quarto passo (quando n = 1), a função copia o primeiro byte de src (tmp_src[0] -> 1000, que é 'a') para a posição 
					   inicial de dest (tmp_dst[0] -> 1002).
					
					 Iteração	Índice (n--)	tmp_dst[n] = tmp_src[n]	     Resultado
						1			3			 str[5] = str[3] = 'd'	    str[5] = 'd'
						2			2			 str[4] = str[2] = 'c'	    str[4] = 'c'
						3			1			 str[3] = str[1] = 'b'	    str[3] = 'b'
						4			0			 str[2] = str[0] = 'a'	    str[2] = 'a'

					 Resultado na memória: [0] 'a'
					     				   [1] 'b'
										   [2] 'a'   ← sobrescrito
										   [3] 'b'   ← sobrescrito
										   [4] 'c'   ← sobrescrito
										   [5] 'd'   ← sobrescrito

					 Resultado como string: "ababcd"
			

2.3 - Sem Sobreposição (Overlapping) - Copiar de frente para trás

	else if (tmp_dst < tmp_src)
		{
			idx = 0;
			while (idx < n)
			{
				tmp_dst[idx] = tmp_src[idx];
				idx++;	
			}
		}

	Isto quer dizer que a área de memória para onde vamos copiar (dest) vem antes da área de onde vamos copiar (src). 
	Em termos de endereços de memória, tmp_dst tem um valor menor que tmp_src.

    Exemplo:

    char str[] = "abcdef";
    ft_memmove(str, str + 2, 4);

    src = str + 2 → começa na posição str[2] e aponta para 'c' (endereço 1002)
    dest = str → começa na posição str[0] e aponta para 'a' (endereço 1000)

	Bytes a copiar: 4 (ou seja, valores de str[2], str[3], str[4], str[5]).
    Vamos copiar 'c', 'd', 'e', 'f' (endereços 1002 a 1005) para os primeiros 4 bytes de str (endereços 1000 a 1003).

    Aqui, dest < src e não há sobreposição problemática porque vamos copiar de uma zona que ainda não foi tocada.
    
	dest começa antes de src, logo: Os dados que estamos a copiar ainda não foram alterados no momento em que estamos
	                                a copiá-los, neste caso, da esquerda para a direita.

	Exemplo prático

	Representação da memória antes:  [1000] a
                                     [1001] b
                                     [1002] c
                                     [1003] d
                                     [1004] e
                                     [1005] f

    Passo a passo da cópia:
 
	Iteração	idx	    src[idx]	dst[idx]	Efeito
		1		 0		  'c'	      'a'	   'a' → 'c'  str[0] = str[2] = 'c'
		2	     1	      'd'	      'b'	   'b' → 'd'  str[1] = str[3] = 'd'
		3	     2	      'e'	      'c'	   'c' → 'e'  str[2] = str[4] = 'e'
		4		 3	      'f'	      'd'	   'd' → 'f'  str[3] = str[5] = 'f'



    Resultado final:  [1000] c
                      [1001] d
                      [1002] e
                      [1003] f
                      [1004] e
                      [1005] f

    A string agora é "cdefef".


3 - Retorno - return (dest);

    A função retorna o ponteiro para o início do destino.
    Isso permite encadear chamadas ou trabalhar diretamente com o ponteiro retornado.



*/