#include <stdio.h>
#include <string.h>
#define PATH "C:\\Users\\HP\\Documents\\Playing with C 1.0\\tarefas.txt"
int main()
{
    int arquivoCriado(FILE * file, char tipo);
    void mostrarMenu(int *opcao);
    char tarefa[100];
    char getTarefas[100];
    int opcao;

    mostrarMenu(&opcao);

    if (opcao == 1)
    {
        FILE *file = fopen(PATH, "r"); 
        int criado = arquivoCriado(file, 'r');
         if (criado)
        {
            fgets(getTarefas, sizeof(getTarefas), file);
            fclose(file);
            printf("\n%s", getTarefas);
        }

    }else if (opcao == 2)
    {
        while(getchar() != '\n');
        printf("\nDigite a terefa: ");
        gets(tarefa);

        FILE *file = fopen(PATH, "w"); 
        int criado = arquivoCriado(file, 'w');
        if (criado)
        {
            fprintf(file, tarefa);
            fclose(file);
        }
        
    }
    
    
    
}

void mostrarMenu(int *opcao){
    printf("\n\n==============MENU=============\n\n");
    printf("1- Mostrar tarefas\n2- Escrever Tarefa\n3- Eliminar Tarefa\n\nEscolher uma opcao: ");
    scanf("%d", opcao); 
}

int arquivoCriado(FILE *file,char tipo)
{
    if (file == NULL)
    {
        printf("\nOcorreu algum erro ao abrir o arquivo!");
        return 0;
    }
    else if (file != NULL && tipo != 'r')
    {
        printf("Arquivo aperto com sucesso!.");
        return 1;
    }
    
    return 1;
}

