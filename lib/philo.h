/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupferstrahl <kupferstrahl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:16:58 by kupferstrah       #+#    #+#             */
/*   Updated: 2023/10/03 12:51:46 by kupferstrah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h>
# include <sys/types.h>

# define ALLOC_ERR_1 "Error while Allocating threads IDs"
# define ALLOC_ERR_2 "Error while Allocating Philosophers"
# define ALLOC_ERR_3 "Error while Allocating forks"

# define ERR_IN_1 "Invalid Character"
# define ERR_IN_2 "Invalid Value"

# define TH_ERR "Error while creating threads"
# define JOIN_ERR "Error while joining threads"
# define INIT_ERR_1 "Error while initiating forks"

# define TIME_ERR "Uable to retreive the correct time"

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				eat_cont;
	int				status;
	int				eating;
	int				id;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

long		ft_atoi(char *str);
int			error(char *str, t_data *data);
int			ft_strcmp(char *s1, char *s2);
void		messages(char *str, t_philo *philo);
void		ft_exit(t_data *data);

uint64_t	get_time(void);
int			ft_usleep(useconds_t time);
int			init(t_data *data, char **argv, int argc);
int			thread_init(t_data *data);
int			input_checker(char **argv);
void		eat(t_philo *philo);
void		*routine(void *p_pointer);
#endif