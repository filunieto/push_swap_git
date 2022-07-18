
#include "libft.h"

void	print_array(char **array_words , int *posicion)
{
	int	i;
	int	j;

	i = 0;
	if (!array_words[i])
	{
 		printf("array de 0. Error \n"); //si metemos entre comillas ningun argumento
		exit (1) ;
	}
	while (array_words[i])
	{
		//printf("palabra No %i : %s. Numero entero : %i\n", i, array_words[i], ft_atoi((const char *)array_words[i]));
		j = 0;
		if ('-' == array_words[i][j])
			j++;
		while (array_words[i][j])
		{
			if (!ft_isdigit(array_words[i][j]))
			{
				printf("ha encontardo un NO digito. Error\n");
				exit (2);				
			}
			//printf("digito ok! sigue\n");
			j++;
		}
		printf("palabra No %i : %s. Numero entero : %i ira en la posicion del stack: %iª \n",
		 i, array_words[i], ft_atoi((const char *)array_words[i]), *posicion);
		//si llega aqui hay que convertir el numero y mndarlo a la lista
		*posicion = *posicion + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char **array_words;
	const char *frase;
	int posicion;
	int i;

	char c = ' ';
	posicion = 0;
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
		print_array(array_words, &posicion);
		i++;
	}
	return (0);
}