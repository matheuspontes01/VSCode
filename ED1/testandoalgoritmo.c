 #include <stdio.h>
 #include <time.h>
 #define numerot 10000

int main()
{
  int vetor[numerot], meio, i, numero, tentativas = 0, numeroencontrado = 0, inicio = 0, fim = numerot;
  for(i = 0; i < numerot; i++)
  {
      vetor[i] = i; // Preenchendo o vetor
  }
  printf("Digite um número a ser buscado: ");
  scanf("%d", &numero);

  struct timespec start, end; // Declarando as variaveis para fazer a contagem do tempo

  clock_gettime(CLOCK_REALTIME, &start); // Inicia a contagem
  meio = (inicio + fim)/2;
  while(numeroencontrado == 0)
  {
      tentativas++;
      if(numero < vetor[meio]) // Se o número for menor que o número do meio, ele tá na metade da esquerda
      {
          fim = meio; // O último número do nosso universo passa a ser o número do meio, pq n tem nenhum número maior que ele
          meio = (fim + inicio)/2; // Calculando o novo número do meio
      }
      else
      {
          if(numero > vetor[meio]) // Se o número for maior que o número do meio, ele tá na metade da direita
          {
              inicio = meio; // o primeiro número do nosso universo passa a ser o número do meio, pq n tem nenhum número menor que ele
              meio = (fim + inicio)/2; // Calculando o novo número do meio
          }
          else // Caso encontrar
          {
            clock_gettime(CLOCK_REALTIME, &end); // Para a contagem
            double tempo_de_execucao = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;// Calcula o tempo em segundos
            numeroencontrado = numero;
            printf("O número foi encontrado e é %d \n", numeroencontrado);
            printf("Número de tentativas: %d \n", tentativas);
            printf("Tempo de execucao: %f\n", tempo_de_execucao); // Mostra o tempo de execucao
            return 0; // Quando encontrar o número vai retornar a função e o programa vai parar
          }
      }
  }
  printf("Número não encontrado"); // Se o programa não parar ainda, quer dizer que o número não foi encontrado
  
    return 0; // Falta calcular o tempo e testar com outros intervalos (até 100000 e até 1000000)
}