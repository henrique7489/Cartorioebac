#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o
#include <string.h> //bliblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�vel/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletandoi informa��o do usu�rio
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // chama e cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // virgula 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // nome do cliente
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");// virgula 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); // sobrenome do cliente
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // virgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s,",cargo); // cargo do cliente
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");		
}

int consultar () //inicio da fun��o de consultar cliente/aluno
{
	//inicio cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese"); //Linguagem para identificar a acentua��o
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�vel/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abre arquivo
	
	if(file == NULL) //caso n�o localizar o arquivo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informa��es caso localizada
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Fim da fun��o de consultar cliente/aluno
}

int deletar() //Come�o da fun��o deletar cliente/aluno
{
	//inicio cria��o de vari�veis/string
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	//final da cria��o de vari�vel/string
	
	//Diferente do exercicio aqui foi utlizado o else.
	if(remove(cpf) == 0){
	  	printf("Cliente deletado com sucesso.\n");  
	} else {
		printf("O usu�rio n�o se encontra no sistema! .\n");
	}
	
	system("pause"); //Fim do fun��o de deletar cliente/aluno
}
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Defenindo a linguagem
	
		printf("\t### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("\tEscolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();	//chamada de fun��es	
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); 
					
		}  //fim da sele��o
	
    }
}
