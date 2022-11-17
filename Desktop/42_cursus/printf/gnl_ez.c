/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_ez.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:24:58 by mtacunan          #+#    #+#             */
/*   Updated: 2022/10/06 16:41:54 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd)
{
	char	*s = malloc(10000);
	char	*c = s;

	while (read(fd, c, 1) > 0 && *c++ != '\n');
		return c > s ? (*c = 0,s) : (free(s),NULL);	
}

int main()
{
	int fd1;
	char *s;
	fd1 = open ("./prueba.txt", O_RDONLY);
	s = get_next_line(fd1);
	printf("%s\n", s);
	//free(s);
	while(s != NULL)
	{
	s = get_next_line(fd1);
	printf("%s\n", s);
	//free(s);
	}
	system("leaks a.out");
	return(0);
}