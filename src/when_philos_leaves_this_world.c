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

    size_t  index;
    index = -1;
    while (!fallacies_not_accepted && ++index < (*wisdom)->philos_number)
        pthread_mutex_destroy(&(*wisdom)->forks[index]);
    pthread_mutex_destroy(&((*wisdom)->cemetery_lock));
    pthread_mutex_destroy(&((*wisdom)->philo_news_lock));
    pthread_mutex_destroy(&((*wisdom)->philos_fed_lock));
    free((*wisdom)->forks);
    free(*wisdom);
    if (!fallacies_not_accepted)
        free(*philo);
    return (fallacies_not_accepted);
}
 