/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:33:32 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 10:15:02 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* STRUCT */

struct	s_total;

typedef struct s_philo
{
	int				nb;
	int				last_eat;
	int				nb_has_eaten;
	pthread_mutex_t	mutex_check;
	struct s_total	*total_ptr;
}	t_philo;

typedef struct s_total
{
	long long		nb_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		nb_must_eat;
	pthread_t		*threads;
	t_philo			*philo_tab;
	pthread_mutex_t	*forks;
	int				start;
	int				now;
	int				time_of_death;
	int				someone_died;
	pthread_mutex_t	starter;
	pthread_mutex_t	dies;
	long long		philos_who_ate_enough;
}	t_total;

/* CHECK */

int				ft_strcmp(char *s1, char *s2);
int				ft_is_num(char *str);
int				ft_check_values(int ac, char **av);

/* INIT */

void			ft_init_null(t_total *total);
void			ft_init_philo_tab(t_total *total);
void			ft_init_atoi(t_total *total, int ac, char **av);
int				ft_init(int ac, char **av, t_total *total);

/* CREATE_THREADS */

int				ft_get_time(void);
void			ft_wait_before_start(t_philo *philo);
void			*routine(void *arg);
int				ft_create_threads(t_total *total);

/* LAUNCH_ACTIONS */

void			ft_assemble_and_print(t_philo *philo, char *time, char *phrase);
int				ft_launch_action(t_philo *philo, char *phrase);

/* ACTIONS */

int				ft_has_taken_left_fork(t_philo *philo);
int				ft_has_taken_right_fork(t_philo *philo);
int				ft_is_eating(t_philo *philo);
int				ft_is_sleeping(t_philo *philo);
int				ft_is_thinking(t_philo *philo);

/* DEATH */

int				ft_philo_is_dead(t_philo *philo);
int				ft_someone_died(t_total *total, t_philo *philo, int i, int now);
int				ft_check_if_stop(t_total *total);

/* FREE */

void			ft_free_and_destroy(t_total *total);

/* STR_UTILS */

long long		ft_atoi(const char *nptr);
unsigned int	ft_get_length(int nb);
char			*ft_itoa(int n);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);

/* ERROR */

int				ft_error_values(int ac, char **av);
int				ft_error_and_return(t_total *total, char *phrase);

#endif
