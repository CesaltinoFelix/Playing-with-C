#include "minishell.h"

int main(void)
{

	char *str;
    char bin[50];
    char s[100];
    char **argument_list;
    char *env[] = {NULL};
	while(1)
	{

		str = readline("minishell1> ");
		if (str == NULL)
		{
			ft_printf("\nExiting...\n");
			break;
		}
		add_history(str);

        argument_list = ft_split(str, ' ');

        if (argument_list == NULL || argument_list[0] == NULL)
        {
            free(str);
            continue;
        }
			strcpy(bin, "/bin/");
			strcat(bin, argument_list[0]);
		
			add_history(str);
		 pid_t pid = fork();
        if (pid == 0)
        {
            if (strcmp(argument_list[0], "cd") == 0)
            {
                    chdir(argument_list[1]);
            }
            else if (strcmp(argument_list[0], "pwd") == 0)
            {
                ft_printf("%s\n", getcwd(s, sizeof(s)));
            }
            else
            {
                if (execve(bin, argument_list, env) == -1)
                {
                    perror("execve");
                }
            }
            exit(0);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            perror("fork");
        }
		
	}
	return (0);
}
