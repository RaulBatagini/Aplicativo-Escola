#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[50];
	float nota;
	
}Aluno;

//Cadastrar o aluno 
void cadastrarAluno(){
	Aluno aluno;
	
	FILE *file = fopen("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\Aluno.txt","a");//Modo "a" Adiciona dados ao final do arquivo
	
	if(file == NULL){
		printf(" Erro ao abrir o arquivo");//Verificando erros
		return;
	}
	
	printf("\n Digite o nome do aluno: ");
	fgets(aluno.nome,50,stdin); //fgets para ler strings
	aluno.nome[strcspn(aluno.nome,"\n")] = 0;
	
	printf(" Digite a nota do aluno: ");
	scanf("%f",&aluno.nota);
	getchar();
	
	fprintf(file, "%s %.2f" , aluno.nome, aluno.nota);
	fclose(file);
	
	printf("\n Cadastro realizado\n");
	
}

//Consultar alunos
void consultarAluno(){
	char nome[50];
	int achou = 0;
	
	Aluno aluno;
	
	FILE *file = fopen("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\Aluno.txt","r");// Modo "r" modo de leitura
	
	if(file == NULL){
		printf(" Erro ao abrir o arquivo");//Verificando erros
		return;
	}
	
	printf("\n Digite o nome do aluno que deseja consultar: ");
	fgets(nome,50, stdin);//fgets para ler strings
	nome[strcspn(nome,"\n")] = 0;
	
	
	while (fscanf(file, "%49s %f", aluno.nome, &aluno.nota) != EOF){//fscanf ler dados formatados
		if(strcmp(aluno.nome,nome)== 0){
			printf("\n Aluno: %s \n Nota: %.2f\n",aluno.nome,aluno.nota);
			achou = 1;
			break;
		}
	
	}

	if(!achou){
		printf("\n Aluno nao localizado\n");
	}
	
	fclose(file);
	
} 

//Gerar relatorio
void gerarRelatorio(){
	Aluno aluno;
	
	FILE *file = fopen("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\Aluno.txt","r");//Modo "r" para leitura
	
	if(file == NULL){//Verificando erros
		printf(" Erro ao abrir o arquivo");
		return;
	}
	
	printf("\n -------Relatorio Alunos-------\n\n");
	
	while(fscanf(file, "%49s %f", aluno.nome, &aluno.nota)!= EOF){//fscanf ler dados fomatados, lendo dados em "file" enquanto for diferente de EOF
		printf(" Aluno: %s \n Nota: %.2f\n\n", aluno.nome,aluno.nota);
	}
	printf(" ------------------------------\n");
	fclose(file);
}

//Excluir alunos
void excluir(){
	char nome[50];
	int achou = 0;
	Aluno aluno;
	
	FILE *file = fopen("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\Aluno.txt","r");//Modo "r" para leitura dos aqruivos
	FILE *filetemp = fopen("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\temporario.txt","w");//Modo "w" para escrita
	
	if(file == NULL || filetemp == NULL){ //Verificando a abertura dos aqruivos
		printf(" Erro ao abrir o arquivo");
		return;
	}
	
	printf("\n Digite o nome do aluno para ser excluido: ");
	fgets(nome,50, stdin);
	nome[strcspn(nome, "\n")] = 0;
	
	while(fscanf(file, "%49s %f", aluno.nome, &aluno.nota)!= EOF){
		if(strcmp(aluno.nome,nome) == 0){
			achou = 1;	
		
		printf(" Aluno %s excluido\n", aluno.nome);
	}else{
		fprintf(filetemp, "%49s %f",aluno.nome, aluno.nota);
	 }
	}
	if(!achou){
		printf(" Aluno nao encontrado\n");
	}
	
	fclose(file);
	fclose(filetemp);
	
	remove("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\Aluno.txt");
	 rename("C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\temporario.txt", 
           "C:\\Faculdade Projetos com Arquivos\\Aplicativo Cadastrar Aluno\\Aluno.txt");
	
}

int main(){
	
	int opcao;
	
	do{
		
	 printf("\n -------MENU-------\n\n");
	 printf(" 1.Cadastrar aluno \n");
	 printf(" 2.Consultar aluno \n");
	 printf(" 3.Gerar relatorio da turma\n");
	 printf(" 4.Excluir \n");
	 printf(" 5.Para sair \n");
	 printf("\n Escolha uma opcao: ");
	 scanf("%d",&opcao);
	 getchar();
	
	 switch(opcao){
	 	
	 case 1: cadastrarAluno();break;
	 case 2: consultarAluno();break;
	 case 3: gerarRelatorio();break;
	 case 4: excluir();break;
	 case 5: printf("\n Saindo...\n\n");break;
     default: printf("\n Opcao invalida");
	 }
	
	}while(opcao != 5);
	
	
	return 0;
}

