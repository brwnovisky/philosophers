# include "../inc/philo.h"

void    *the_starve_demon_threat(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
    spending_my_time(philo->wisdom->life_time + 1);
    pthread_mutex_lock(&philo->someone_starved_lock); 
    if ((timestamp_in_ms() - philo->last_eat) > philo->wisdom->life_time)
    {
        philo_news_censorship(philo);
        pthread_mutex_lock(&philo->wisdom->cemetery_lock);
        if (!philo->wisdom->cemetery)
        {
            philo_news(philo, DIED);
            philo->wisdom->cemetery = 1;
        }
        pthread_mutex_unlock(&philo->wisdom->cemetery_lock);
        philo->someone_starved = 1;
    }
    pthread_mutex_unlock(&philo->someone_starved_lock); 
    return (NULL);
}

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
    while (++index < (*wisdom)->philos_number)
    {
        pthread_mutex_destroy(&(*wisdom)->forks[index]);
    }
    // pthread_mutex_destroy(&((*philo)->someone_starved_lock));
    pthread_mutex_destroy(&((*wisdom)->cemetery_lock));
    pthread_mutex_destroy(&((*wisdom)->philo_news_lock));
    pthread_mutex_destroy(&((*wisdom)->philos_fed_lock));
    free((*wisdom)->forks);
    free(*philo);
    free(*wisdom);
    return(fallacies_not_accepted);
} 