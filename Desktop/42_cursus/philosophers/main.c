/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:05:07 by mtacunan          #+#    #+#             */
/*   Updated: 2022/11/17 13:49:02 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	lock =PTHREAD_MUTEX_INITIALIZER;

void* present(void *arg)
{
	usleep(100000);
	t_philo	*philo = (t_philo	*)arg;
	printf("----------\n");
	printf("soy el filosofo %d\n", philo->id);
	printf("  t_muerte: %d ms\n  t_comer: %d ms\n  t_dormir: %d ms\n",\
			philo->tdie, philo->teat, philo->tsleep);
	return (NULL);
}


/*Hay que revisar que no es necesaria esta funcion
	para que funcionen los hilos
*/
void	a_func(int limit)
{
	usleep(100000);
}

/*
	Se encarga de recopilar los datos en una struct
*/
void	fill_dphilo(int id, char **argv, t_philo *philo)
{
	philo->id = id + 1;
	philo->tdie = atoi(argv[2]);
	philo->teat = atoi(argv[3]);
	philo->tsleep = atoi(argv[4]);
}

/* ESTA HACIENDO 5 PHILOSOPHOS */
void	create_philos(int nb, char **argv)
{
	int			id;
	t_philo		*philo;
	pthread_t	*h1;
	
	id = 0;
	philo = malloc(sizeof(t_philo));
	h1 = malloc(sizeof(pthread_t) * nb);
	while (id < nb)
	{
		fill_dphilo(id,argv, philo);
		pthread_create(&h1[id] , NULL , present , philo);
		a_func(nb);
		id++;
	}
}

int	main(int argc, char **argv)
{
	/*
	* number_of_philosophers : numeor de filos
	* time_to_die :
	* time_to_eat : 
	* time_to_sleep :
	* [number_of_times_each_philosopher_must_eat] opcional para que se pare 
		el programa:
	*/

	// if (argc != 5)
	// {
	// 	write(1, "introduzca : [n_philos] [t_muerte]  [t_comer] [t_dormir].\n", 58);
	// 	return (0);
	// }
	/*parseo*/
	/*
	antes de eso, como vamos a hacer el proyecto? hacemos una struct con los tenedores, una struc con los fflosofos
	*/
	//pthread_create();

	
	if(argc != 5)
		return (0);

	create_philos(atoi(argv[1]), argv);
	///system("leaks a.out");
	return (0);
}
