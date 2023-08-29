# include "../inc/philo.h"

void    philo_news_censorship(t_philo *philo)
{
    pthread_mutex_lock(&philo->wisdom->philo_news_lock);
    philo->wisdom->philo_news_censorship = 1;
    pthread_mutex_unlock(&philo->wisdom->philo_news_lock);
}  

void    philo_news(t_philo *philo, char *event)
{
    size_t    time;

    time = timestamp_in_ms() - philo->wisdom->start_time;
    pthread_mutex_lock(&philo->wisdom->philo_news_lock);
    if (!philo->wisdom->philo_news_censorship \
    ||(philo->wisdom->philo_news_censorship && event[0] == 'd') )
        printf(FORMAT, time, philo->name, event);
    pthread_mutex_unlock(&philo->wisdom->philo_news_lock);
}

int fallacies_will_not_be_appreciated(t_wisdom **wisdom, t_philo **philo, \
int args_quantity, int possible_fallacies)
{
    int     bad_arguments;

    bad_arguments = 0;
    if (possible_fallacies)
        write(2, ERROR_ARGS_3, 19);      
    if (args_quantity < 5 && ++bad_arguments)
        write(2, ERROR_ARGS_1, 23);      
    else if (args_quantity > 6 && ++bad_arguments)
        write(2, ERROR_ARGS_2, 20);
    if (bad_arguments || possible_fallacies)
        return (cleaning_the_agora(wisdom, philo, 1));
    return (EXIT_SUCCESS);
}