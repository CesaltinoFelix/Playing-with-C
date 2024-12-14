#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <readline/history.h>

static int	count_words(const char *s, char delimiter)
{
	size_t	words;

	words = 0;
	if (*s == '\0')
		return (words);
	if (delimiter == '\0')
		return (1);
	while (*s == delimiter && *s)
		s++;
	while (*s)
	{
		words++;
		while (*s != delimiter && *s)
			s++;
		while (*s == delimiter && *s)
			s++;
	}
	return (words);
}

void	*rollback(char **morsels)
{
	while (*morsels)
		free(*morsels);
	free(morsels);
	return (NULL);
}

char	**write_words(char **morsels, const char *s, char delimiter)
{
	size_t	length;
	size_t	i;

	i = 0;
	while (*s)
	{
		length = 0;
		while (s[length] != delimiter && s[length])
			length++;
		morsels[i] = (char *) malloc(length * sizeof(char) + 1);
		if (morsels[i] == NULL)
			return (rollback(morsels));
		morsels[i][length] = '\0';
		while (length > 0)
		{
			morsels[i][length - 1] = s[length - 1];
			length--;
		}
		while (*s != delimiter && *s)
			s++;
		while (*s == delimiter && *s)
			s++;
		i++;
	}
	return (morsels);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_count;

	word_count = count_words(s, c);
	arr = (char **) malloc((word_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (*s == c && *s)
		s++;
	arr = write_words(arr, s, c);
	arr[word_count] = NULL;
	return (arr);
}

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
			printf("\nExiting...\n");
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
                printf("%s\n", getcwd(s, sizeof(s)));
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
