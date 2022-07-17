
#include "libft.h"

void	print_array(char **array_words)
{
	int	i;

	i = 0;
	if (!array_words[i])
	{
 		printf("array de 0 \n"); //si metemos entre comillas ningun argumento
		return ;
	}
	while (array_words[i])
	{
		printf("palabra No %i : %s\n", i, array_words[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char **array_words;
	const char *frase;

	char c = ' ';
	int i;
	
	if (argc < 2)
	{
		printf("error en argumentos de etrada. Mete mas argumentos compay\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		frase = argv[i];
		array_words = ft_split(frase, c);
		printf("--- imprimirmos el arc: %i ----\n", i);
		print_array(array_words);
		i++;
	}
	return (0);
}