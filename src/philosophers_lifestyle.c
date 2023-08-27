# include "../inc/philo.h"

void    thinking_about_the_finitude_or_infinitude_of_life(t_philo *philo)
{
    philo_feed(philo, THINKING);
}

int trying_to_sleep_like_a_lazy_bear(t_philo *philo, \
int only_releasing_the_fucking_forks)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(&philo->right_fork);
    if (only_releasing_the_fucking_forks)
        return (0);
    philo_feed(philo, SLEEPING);
    spending_my_time(philo->wisdom->sleep_time);
    return (1);
}

int trying_to_eat_a_spaghetti_in_piece(t_philo *philo)
{
    int     return_n;

    philo->last_eat = timestamp_in_ms();
    philo->meals_count += 1;
    philo_feed(philo, EATING);
    pthread_mutex_lock(&philo->wisdom->philos_fed_lock);
    philo->wisdom->philos_fed += \
    (philo->meals_count == philo->wisdom->spaghetti_amount);
    return_n = (philo->wisdom->philos_fed == philo->wisdom->philos_number);
    pthread_mutex_unlock(&philo->wisdom->philos_fed_lock);
    if (return_n)
    {
        philo_feed_censorship(philo);
        return(trying_to_sleep_like_a_lazy_bear(philo, 1));
    }
    spending_my_time(philo->wisdom->eat_time);    
    return (1);
}

int trying_to_take_the_fucking_forks(t_philo *philo)
{
    int     me_starved;
    int     anybody_starved;

    pthread_mutex_lock(philo->left_fork);
    pthread_mutex_lock(&philo->right_fork);
    pthread_mutex_lock(&philo->wisdom->cemetery_lock);
    me_starved =  (timestamp_in_ms() - philo->last_eat > philo->wisdom->life_time);
    if (me_starved)
    {
        if (!philo->wisdom->cemetery)
            philo_feed(philo, DIED);      
        philo->wisdom->cemetery = 1;
    }
    else
        anybody_starved = (philo->wisdom->cemetery);
    pthread_mutex_unlock(&philo->wisdom->cemetery_lock);
    if (me_starved || anybody_starved)
    {
        if (me_starved)
            philo_feed_censorship(philo);
        return (trying_to_sleep_like_a_lazy_bear(philo, 1));
    }
    philo_feed(philo, FORK_TAKEN);
    philo_feed(philo, FORK_TAKEN);
    return (1);
}   

void    *the_philosopher_lifestyle(void *arg)
{
    t_philo     *philo;

    philo = (t_philo *)arg;
    philo->last_eat = philo->wisdom->start_time;
    if (philo->wisdom->philos_number == 1)
        spending_my_time(philo->wisdom->life_time + 1);
    else if (philo->name == 1)
        spending_my_time(2);
    while (1)
    {
        if (!trying_to_take_the_fucking_forks(philo))
            break;
        if (!trying_to_eat_a_spaghetti_in_piece(philo))
            break;
        if (!trying_to_sleep_like_a_lazy_bear(philo, 0))
            break;
        thinking_about_the_finitude_or_infinitude_of_life(philo);
    }
    return (NULL);
}