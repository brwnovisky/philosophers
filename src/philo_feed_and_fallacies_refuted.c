# include "../inc/philo.h"

void    philo_feed_censorship(t_philo *philo)
{
    pthread_mutex_lock(&philo->wisdom->philo_feed_lock);
    philo->wisdom->philo_feed_censorship = 1;
    pthread_mutex_unlock(&philo->wisdom->philo_feed_lock);
}  

void    philo_feed(t_philo *philo, char *event)
{
    size_t    time;

    time = timestamp_in_ms() - philo->wisdom->start_time;
    pthread_mutex_lock(&philo->wisdom->philo_feed_lock);
    if (!philo->wisdom->philo_feed_censorship \
    ||(philo->wisdom->philo_feed_censorship && event[0] == 'd') )
        printf(FORMAT, time, philo->name, event);
    pthread_mutex_unlock(&philo->wisdom->philo_feed_lock);
}

int fallacies_will_not_be_appreciated(t_wisdom **wisdom, t_philo **philo, \
int args_quantity, int possible_fallacies)
{
    if (args_quantity < 5)
    {
        write(2, ERROR_ARGS_1, 23);      
        return (cleaning_the_agora(wisdom, philo, 1));
    }
    else if (args_quantity > 6)
    {
        write(2, ERROR_ARGS_2, 20);
        return (cleaning_the_agora(wisdom, philo, 1));
    }
    else if (possible_fallacies)
    {
        write(2, ERROR_ARGS_3, 19);      
        return (cleaning_the_agora(wisdom, philo, 1));
    }
    return (0);
}