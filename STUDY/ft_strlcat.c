size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	idx;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	idx = 0;
	while ((dest_len + idx) < (size - 1) && (src[idx] != '\0'))
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest_len + src_len);
}

/*

Objetivo: Concatenar a string src à string dest, com o limite máximo de tamanho definido
pelo parâmetro size. A função assegura que a string resultante dest tenha, no máximo, 
size - 1 caracteres, com a adição de um caractere nulo (\0) no final.

1 - Parâmetros da função  -  size_t	ft_strlcat(char *dest, const char *src, size_t size)

1.1 - char *dest: é o ponteiro para a string dest que vai armazenar a string resultante da
                  concatenação com a string src. OU seja, é o destino onde os caracteres
				  da string src serão copiados, respeitando o limite máximo de tamanho que 
				  é dado pelo parâmetro size. A função ft_strlcat vai, assim, juntar os
				  caracteres da src no final da string dest.
				  
				  O ponteiro *dest aponta para o local da memória onde será armazenada a string
				  resultante, que corresponde à string à qual queremos adicionar os caracteres 
				  da src.
				  A função ft_strlcat vai modificar a string que dest aponta, ao adicionar os 
				  caracteres da src no fim dela, respeitando o limite de espaço determinado pelo
				  parâmetro size.

				  Não é um const char *, pois a função vai modificar o conteúdo da dest (vai
				  adicionar os caracteres da src no final da dest).

1.2 - const char *src: é o ponteiro para a string src que contém os caracteres que vão ser adicionados
                       no final da string dest.
                       A função vai copiar os caracteres da src para a dest, mas ela não irá 
					   ultrapassar o limite máximo dado pelo parâmetro size - 1.

					   Ao contrário da string dest, src é const char *, pelo o que a função não vai
					   modificar o conteúdo de src, mas sim apenas ler. A string src só vai fornecer
					   os caracteres para copiar para a dest.

1.3 - size_t size: representa o tamanho total do buffer dest, ou seja, o espaço total disponível para conter
                   a string final (incluindo o '\0'). 
				   Define o tamanho total disponível para a string concatenada (dest). A função vai garantir
				   que dest não ultrapasse o tamanho especificado por size - 1 caracteres. Se size for menor 
				   ou igual ao comprimento de dest, a função irá apenas retornar o comprimento total de 
				   dest + o comprimento de src, sem realizar qualquer concatenação. 

				   O tipo size_t é utilizado, pois ele é adequado para expressar tamanhos de memória de forma 
				   portável e segura.

				   Por que usamos size_t e não int, por exemplo?
                    
				   1. Porque o tamanho nunca deve ser negativo.
                      Um tamanho de uma string, de um array ou de uma àrea de memória nunca é negativo.
                      size_t é unsigned, então só representa valores de 0 até o máximo da arquitetura -
					  - unsigned int, para 32 bits, unsigned long, para 64 bits.

					2. size_t é o tipo padrão para representar os tamanhos dos buffers.
					   A função strlcat lida com àreas da memória e como estamos a referirmo-nos ao tamanho
					   da memória, size_t representa bem o tamanho dessas àreas.

					 Característica		             int					     size_t
						  Tipo		           Com sinal (signed)		  Sem sinal (unsigned)
					Pode ser negativo?	             Sim	                      Não
                      Tamanho em bits	       Geralmente 32 bits	       32 bits ou 64 bits
                    Intervalo (32 bits)	 -2.147.483.648 a 2.147.483.647	    0 a 4.294.967.295
                       Usado para quê?	Operações lógicas e matemáticas	  Tamanhos, índices, contagens

				    O parâmetro size serve para: - Impedir que a função ultrapasse o espaço alocado em dest, 
				                                   evitando buffer overflow.
                                                 - Indicar até onde a concatenação da string pode ocorrer.
                                                 - Determinar o valor correto de retorno, que informa o comprimento 
												   total que a nova string teria, mesmo que não caiba toda na dest.

2 - Compreender a Implementação

2.1 - Calcular os Comprimentos de dest e src

      dest_len = ft_strlen(dest): Calculamos o comprimento atual da string que está armazenada na string
	                              dest, ou seja, quantos caracteres já estão presentes no buffer dest.
	                              A função ft_strlcat quer concatenar src no fim da dest, mas para isso, 
								  a funçao precisa de saber onde a string dest termina.
	                              dest_len ao armazenar o comprimento da string dest, vai nos dar o índice 
								  onde a cópia da string vai começar.
 
	  src_len = ft_strlen(src): Calculamos o comprimento da string src, ou seja, quantos caracteres existem
	                            na string que queremos copiar para o final da string dest.
								A função ft_strlcat precisa de saber quantos caracteres existem na src para
								saber até onde pode copiar, respeitando o espaço disponível na dest.
		
	
     Estes valores são essenciais para determinar se a concatenação pode ocorrer e qual é o espaço restante
	 na dest para adicionar os caracteres da src.

2.2 - Verificação de Capacidade de dest

	  if (size <= dest_len)
      	 return (src_len + size);

      Este if verifica se não há espaço suficiente na string dest para concatenar qualquer parte da 
	  string src.
	  Se o size (número máximo de bytes que o dest pode conter, incluindo o '\0') for menor ou igual
	  ao tamanho atual da dest (dest_len), significa que já ultrapassamos ou estamos no limite da 
	  capacidade de dest, então não é possível adicionar mais nenhum caractere da src.
	  Neste caso, a função não altera nada na string dest e retorna apenas o valor teórico do
	  tamanho total que a string final concatenada teria se houvesse espaço suficiente e se não
	  houvesse o limite de size.

      Assim, esta verificação garante que, se o tamanho total de dest já ultrapassar ou for igual a size,
	  a função não tentará concatenar nada. Isto evita que dest ultrapasse o limite de memória.

2.3 - Início da Concatenção


	  while ((dest_len + idx) < (size - 1) && (src[idx] != '\0'))
	  {
           dest[dest_len + idx] = src[idx];
           idx++;
      }
      
	  Após verificar se há espaço suficiente, a função entra num loop while, que vai copiar os caracteres
	  da src para o final da dest, sem ultrapassar o limite de size e garantindo que haja espaço para o caractere nulo no final da string final.
	  O loop também é interrompido se a string src terminar (até atingir o limite de size - 1
	  caracteres). 
	  Assim, a cópia dos caracteres da src para a dest continua enquanto ainda houver espaço suficiente
	  no buffer dest e enquanto ainda existirem caracteres na src para copiar.
      
      dest_len + idx: corresponde ao índice atual de dest onde será copiado o próximo caractere da
	  src.

	  Por que vamos comparar com size - 1? A função strlcat nunca deve ultrapassar o limite size (que representa 
	  o tamanho total do buffer de dest).
	  No buffer, o último byte deve ser reservado para o caractere nulo '\0'.
      Queremos garantir espaço para o caractere nulo \0 no final, então só podemos copiar até o índice size - 2, 
	  porque dest[size - 1] será reservado para o \0.
	  Se copiássemos até size, estaríamos a escrever fora da àrea permitida, pelo o que a cópia poderia ir até
	  size - 1 sem deixarmos espaço para o '\0', e a string não terminaria corretamente, o que causaria um
	  comportamento indefinido ao utilizar a dest posteriormente. 

	  Assim, size - 1: - Protege o buffer contra excesso de escrita. 
	                   - Garante espaço para o '\0' no final. 
					   - Mantém a dest como uma string válida. 

	  (dest_len + idx) < size: Esta condição protege contra a escrita fora dos limites do buffer, pelo o que: 
	                           
	                           - O buffer da string dest tem size posições (índices de 0 até size - 1). 
							   - Só podemos escrever até size - 1, porque depois disso estamos a aceder
							     a memória inválida. 
      
	  dest[dest_len + idx] = src[idx]: vamos copiar cada caractere da src, um por um, para o final da
	                                   string dest. 

	  Assim, resumindo o loop while, a condição significa que a posição onde vamos copiar o próximo caractere
	  da string src ainda estiver dentro dos limites permitidos pelo buffer, copiamos o caractere da src para 
	  a posição final atual da string dest, um por um. 
	  
	  As condições deste while evitam o buffer overflow, o que protege a memória, garante que a string dest
	  continue a ser uma string válida, com o '\0' no final e copia de forma segura e eficiente, até onde
	  for possível. 

2.4 - Garantir o Caractere Nulo (\0)  -  dest[dest_len + idx] = '\0';

       Após copiar todos os caracteres de src para dest, a função garante que a string resultante em dest 
	   será terminada com o caractere nulo (\0). Isso é essencial para que a string seja válida e para que
	   as funções de manipulação de strings (como ft_strlen) funcionem corretamente.

2.5 - Retorno do Comprimento Total  -  return (dest_len + src_len);

      Por fim, a função retorna o comprimento total da string concatenada. 
	  Esse valor é dest_len + src_len, o que representa o tamanho que a string final teria se o limite de
	  size não existisse. 
	  Ou seja, mesmo que a cópia não ocorra completamente (na sua totalidade), a função sempre vai informar
	  qual o seria o tamanho final se houvesse espaço suficiente.
	  Esta informação pode ser útil se o programador quiser verificar se o buffer fornecido foi grande o 
	  suficiente para armazenar a concatenação.


Exemplo:   char dest[12] = "Hello ";  // Já contém 6 caracteres
           char src[] = "World!";     // Tem 6 caracteres
           size_t size = 12;          // Capacidade total do buffer 'dest'

           Situação Inicial:  dest = "Hello "     // dest_len = 6
                              src  = "World!"     // src_len = 6
                              size = 12

		    1. Calcular os comprimentos:  dest_len = ft_strlen(dest);  // 6
                                          src_len  = ft_strlen(src);   // 6

            2. Verificar se é possível concatenar algo:

            if (size <= dest_len)
                return (src_len + size);

            size = 12
            dest_len = 6

            Como 12 > 6, não entra no if, pode continuar.

            3. Loop de cópia:

            idx = 0;
            while ((dest_len + idx) < (size - 1) && src[idx] != '\0')
            {
                dest[dest_len + idx] = src[idx];
                idx++;
            }

            idx	  dest_len + idx	size - 1 = 11	src[idx]	  Ação	        Resultado em dest
			 0	         6	              11	      'W'	   dest[6] = 'W'	   "Hello W"
			 1	         7                11	      'o'	   dest[7] = 'o'	   "Hello Wo"
			 2 	         8	              11	      'r'	   dest[8] = 'r'	   "Hello Wor"
			 3	         9	              11	      'l'	   dest[9] = 'l'	   "Hello Worl"
			 4	        10	              11	      'd'	   dest[10] = 'd'	   "Hello World"
			 5	        11	              11	      '!'	    FIM DO LOOP	

            Agora adicionamos o terminador nulo: dest[dest_len + idx] = '\0';  // dest[11] = '\0'

            4. Retorno da função: return (dest_len + src_len);  // 6 + 6 = 12

            A função retorna: 12, que é o tamanho total da string pretendida















*/