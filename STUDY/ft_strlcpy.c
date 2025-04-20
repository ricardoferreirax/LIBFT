size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	if (size == 0)
		return (ft_strlen(src));
	idx = 0;
	while (src[idx] != '\0' && (idx < size - 1))
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}

/*

Objetivo: Copiar a string src para a string dest, respeitando o tamanho máximo (size) do buffer
da string dest, com limite máximo de size - 1 caracteres, garantindo que a string resultante
seja sempre terminada com o caractere nulo '\0', desde que size seja maior do que 0. 
A função retorna o comprimento total da string src.

1 - Parâmetros da função  -  size_t ft_strlcpy(char *dest, const char *src, size_t size)

1.1 - char *dest: É o ponteiro para a string dest onde os caracteres da string src serão copiados.
                  A função ft_strlcpy vai preencher essa àrea de memória com os caracteres 
				  copiados da string src, um por um. 
				  A àrea da memória dest é o local onde ficará a nova string, limitada por size - 1
				  caracteres.
				  A função vai modifcar a string dest, pois ft_strlcpy vai escrever os caracteres
				  da string src no interior da àrea da memória da string dest. 
                  Assim, o conteúdo de dest será modificado, pois vai receber os caracteres da src.
                  Como estamos a modificar dest, ele não pode ser const.

				  O que precisamos de garantir na string dest antes de chamar ft_strlcpy?

                  > A memória apontada por dest já deve estar alocada.

                       - dest deve ter, pelo menos, size bytes disponíveis.
                       - A função não aloca memória — ela apenas copia para
					     uma área já alocada.

                  > dest deve ser grande o suficiente, ou a string será truncada 
				    (cortada antes do fim).

                        - Mesmo com truncamento, a função não causa buffer overflow
						  se o buffer tiver size bytes.

1.2 - const char *src: é o ponteiro para a string src que contém os caracteres que vão ser copiados
                       para o final da string dest.
                       A função vai copiar os caracteres da src para a dest, mas ela não irá 
					   ultrapassar o limite máximo dado pelo parâmetro size - 1.

					   Ao contrário da string dest, src é const char *, pelo o que a função não vai
					   modificar o conteúdo de src, mas sim apenas ler. A string src só vai fornecer
					   os caracteres para copiar para a dest.

1.3 - size_t size: representa o tamanho total do buffer dest, ou seja, o espaço total disponível para conter
                   a string final (incluindo o '\0'). 
				   Define o tamanho total disponível para a string final (dest). 
				   O parâmetro size garante que a função não ultrapasse o limite de memória da string dest
				   ao copiar a string src.
				   A função ft_strlcpy nunca copia mais que size - 1 caracteres da src, justamente para:

                    - Evitar a escrita fora dos limites das áreas de memória que não pertencem ao buffer de dest
					 (protege contra buffer overflows).
                    - Reservar sempre espaço para o \0 final, o que garante que a string copiada seja válida.

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
                                                 - Indicar até onde a cópia da string pode ocorrer.

                    Se size == 0, a função não copia nada para dest, mas ainda retorna o comprimento de src.


2 - Compreender a Implementação

2.1 - Verificar se size é 0:

      if (size == 0)
	     return (ft_strlen(src));

	 Na função ft_strlcpy, o parâmetro size representa o tamanho total do buffer dest, ou seja
	 quantos bytes estão disponíveis para receber a cópia da string src. 
	 Nós perguntamos: "A àrea da memória dest tem espaço disponível para armazenar caracteres,
	 incluindo o '\0'?".
   
    Se size == 0, não há espaço para copiar nada para a string dest, nem sequer o \0.
	Se tentássemos copiar algum caractere com size == 0, estariamos a acessar dest[0],
	o que violaria a memória, pois dest é uma string sem espaço alocado. 

    Mas ainda assim, mesmo que nada seja copiado para a string dest, a função precisa de 
	retornar o tamanho total da string src, pois este é o comportamento padrão da strlcpy.

	Vai informar o programador: "Pediste_me para copiar para a string dest sem espaço alocado,
	uma string src, pelo o que não foi possível. Mas, se quiseres copiar tudo da próxima vez, 
	vais precisar de ft_strlen(src) + 1 de espaço necessário para copiar a string completa".

	Retornar o comprimento da src é útil para saber quanto espaço é necessário para copiar a 
	string completa de modo a efetuar uma alocação correta de memória antes de copiar. 

	Exemplo: char *src = "Exemplo";
             char buffer[1];

             size_t result = ft_strlcpy(buffer, src, 0);

             Neste caso: Nada será copiado para buffer, porque size == 0.
                         result receberá o valor 7, que é o tamanho da string "Exemplo".
                         Isso informa que, para copiar "Exemplo" com segurança, precisaríamos 
						 de um buffer de tamanho 8 (7 + 1 para o \0).
    
2.2 - Copiar caracteres de src para dest

	while (src[idx] != '\0' && (idx < size - 1))
	{
		dest[idx] = src[idx];
		idx++;
	}

    O loop copia os caracteres da src para a dest enquanto ainda houver caracteres da src para copiar
	e não ultrapassarmos o limite de espaço disponível na string dest (respeitando o espaço para o '\0'). 
    
	Por que vamos comparar com size - 1? A função strlcpy nunca deve ultrapassar o limite size (que representa 
	o tamanho total do buffer de dest).
	No buffer, o último byte deve ser reservado para o caractere nulo '\0'.
    Queremos garantir espaço para o caractere nulo \0 no final, então só podemos copiar até o índice size - 2, 
	porque size - 1 será reservado para o \0.
	Se copiássemos até size, estaríamos a escrever fora da àrea permitida, pelo o que a cópia poderia ir até
	size - 1 sem deixarmos espaço para o '\0', e a string não terminaria corretamente, o que causaria um
	comportamento indefinido ao utilizar a dest posteriormente. 

	Assim, size - 1: - Protege o buffer contra excesso de escrita. 
	                 - Garante espaço para o '\0' no final. 
					 - Mantém a dest como uma string válida. 

    Isso impede que dest ultrapasse seu limite de memória (evita buffer overflow).

	dest[idx] = src[idx]: copia um único caractere da string src para a string dest, na posição
	                      idx atual.
						  Vamos colocar exatamente o caractere da posição idx da string src na 
						  mesma posição idx da string dest. 

2.3 - Garantir que dest termine com \0  -  dest[idx] = '\0';

      Após copiar os caracteres, adicionamos o \0 no final da string dest, para garantir que seja 
	  uma string C válida.
      Mesmo que a src seja maior do que size - 1, dest tem de terminar com o \0 (caso size > 0), 
	  protegendo o programa.

2.4 - Retornar o comprimento total de src  -  return (ft_strlen(src))

      Retornamos o comprimento total de src, mesmo que a cópia não tenha sido completa.
      Assim, o programador pode ajustar o tamanho do buffer, se quiser copiar toda a src futuramente.

	  Por fim, a função retorna o comprimento da string src. 
	  Mesmo que a cópia não ocorra completamente (na sua totalidade), a função sempre vai informar
	  qual o seria o tamanho final da src se houvesse espaço suficiente.
	  Esta informação pode ser útil se o programador quiser verificar se o buffer fornecido foi grande o 
	  suficiente para copiar a string src.













*/