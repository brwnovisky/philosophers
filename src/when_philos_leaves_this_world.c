# include "../inc/philo.h"

void    here_philosophers_rest_in_peace(t_wisdom *wisdom, t_philo *philo)
{
    size_t  index;
    index = -1;
    while (++index < wisdom->philos_number)
        pthread_join(philo[index].philo, NULL);
}

int   cleaning_the_agora(t_wisdom **wisdom, t_philo **philo, \
int fallacies_not_accepted)
{
    free(*philo);
    free(*wisdom);
    return(fallacies_not_accepted);
} 