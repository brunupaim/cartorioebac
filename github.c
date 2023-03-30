#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{
     //inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
     //inicio criacao de variaveis/string

	printf("digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //refere-se a string

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

     getchar();

}

int consulta()
{
     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

     char cpf[40];
     char conteudo[200];

     printf("digite o cpf a ser condultado: ");
     scanf("%s",cpf);

     FILE *file;
     file = fopen(cpf,"r");
     getchar();

     if(file == NULL)
     {
          printf("não foi possível abrir o arquivo, não localizado.\n");
     }

     while(fgets(conteudo, 200, file) != NULL)
     {
          printf("\nEssas são as informações do usuário: ");
          printf("%s", conteudo);
          printf("\n\n");
     }

     getchar();


}

int deletar()
{
	char cpf[40];

	printf("digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r");
	getchar();

	if(file == NULL)
     {
          printf("o usuário não se encontra no sistema!.\n");
          getchar();
     }

}



int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;

	for(laco=1;laco=1;)
	{

		system("clear");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("escolha a opção desejada do menu\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		printf("Opção: ");//fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário

		system("clear"); //responsavel por limpar a tela

		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funcoes
			break;

			case 2:
			consulta();
			break;

			case 3:
			deletar();
			break;

			case 4:
               printf("obrigado por utilizar o sistema\n");
               return 0;
               break;

			default:
			printf("essa opção não está disponivel!\n");
			getchar();
			break;
		} //fim da seleção

	}
}
