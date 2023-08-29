# include "../inc/philo.h"

void    thinking_about_the_finitude_or_infinitude_of_life(t_philo *philo)
{
    philo_news(philo, THINKING);
}

int trying_to_sleep_like_a_lazy_bear(t_philo *philo, \
int only_releasing_the_fucking_forks)
{
    if (philo->name % 2 != 0)
        pthread_mutex_unlock(philo->left_fork);
    if (philo->wisdom->philos_number > 1)
        pthread_mutex_unlock(philo->right_fork);
    if (philo->name % 2 == 0)
        pthread_mutex_unlock(philo->left_fork);
    if (only_releasing_the_fucking_forks)
        return (0);
    philo_news(philo, SLEEPING);
    spending_my_time(philo->wisdom->sleep_time);
    return (1);
}

int trying_to_eat_a_spaghetti_in_piece(t_philo *philo)
{
    philo->last_eat = timestamp_in_ms();
    philo_news(philo, EATING);
    if (philo->wisdom->spaghetti_amount)
    {
        philo->meals_count += 1;
        pthread_mutex_lock(&philo->wisdom->philos_fed_lock);
        philo->wisdom->philos_fed += \
        (philo->meals_count == philo->wisdom->spaghetti_amount);
        if (philo->wisdom->philos_fed >= philo->wisdom->philos_number)
        {
            if (philo->wisdom->philos_fed == philo->wisdom->philos_number) 
                philo_news_censorship(philo);
            pthread_mutex_unlock(&philo->wisdom->philos_fed_lock);
            return(trying_to_sleep_like_a_lazy_bear(philo, 1));
        }
        pthread_mutex_unlock(&philo->wisdom->philos_fed_lock);
    }
    spending_my_time(philo->wisdom->eat_time);    
    return (SUCCESS);
}

int trying_to_take_the_fucking_forks(t_philo *philo)
{
    if (philo->name % 2 != 0)
        pthread_mutex_lock(philo->left_fork);
    philo_news(philo, FORK_TAKEN);
    if (philo->wisdom->philos_number == 1)
        spending_my_time(philo->wisdom->life_time + 1);
    else
        pthread_mutex_lock(philo->right_fork);
    if (philo->name % 2 == 0)
        pthread_mutex_lock(philo->left_fork);
    pthread_mutex_lock(&philo->wisdom->cemetery_lock);
    if (timestamp_in_ms() - philo->last_eat > philo->wisdom->life_time \
    || philo->wisdom->cemetery)
    {
        philo_news_censorship(philo);
        if (!philo->wisdom->cemetery)
            philo_news(philo, DIED);      
        philo->wisdom->cemetery = 1;
        pthread_mutex_unlock(&philo->wisdom->cemetery_lock);
        return (trying_to_sleep_like_a_lazy_bear(philo, 1));
    }
    pthread_mutex_unlock(&philo->wisdom->cemetery_lock);
    philo_news(philo, FORK_TAKEN);
    return (1);
}

void    *the_philosopher_lifestyle(void *arg)
{
    t_philo         *philo;

    philo = (t_philo *)arg;
    philo->last_eat = philo->wisdom->start_time;
    if (philo->name % 2 == 0)
        spending_my_time(1);
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