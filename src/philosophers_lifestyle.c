# include "../inc/philo.h"

void    thinking_about_the_finitude_or_infinitude_of_life(t_philo *philo)
{
    philo_news(philo, THINKING);
}

int trying_to_sleep_like_a_lazy_bear(t_philo *philo, \
int only_releasing_the_fucking_forks)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    if (only_releasing_the_fucking_forks)
        return (0);
    philo_news(philo, SLEEPING);
    spending_my_time(philo->wisdom->sleep_time);
    return (1);
}

int trying_to_eat_a_spaghetti_in_piece(t_philo *philo, pthread_t *starve_demon)
{
    philo->last_eat = timestamp_in_ms();
    pthread_mutex_unlock(&philo->someone_starved_lock);
    pthread_detach(*starve_demon); 
    philo_news(philo, FORK_TAKEN);
    philo_news(philo, EATING);
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
    spending_my_time(philo->wisdom->eat_time);    
    return (SUCCESS);
}

int trying_to_take_the_fucking_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    philo_news(philo, FORK_TAKEN);
    if (philo->wisdom->philos_number == 1)
    {
        spending_my_time(philo->wisdom->life_time + 2);
        return (EXCEPTION);
    }
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_lock(&philo->someone_starved_lock);
    if (philo->someone_starved)
    {
        pthread_mutex_unlock(&philo->someone_starved_lock); 
        return (trying_to_sleep_like_a_lazy_bear(philo, 1));  
    }
    return (SUCCESS);
}   

void    *the_philosopher_lifestyle(void *arg)
{
    t_philo         *philo;
    pthread_t       starve_demon;

    philo = (t_philo *)arg;
    philo->last_eat = philo->wisdom->start_time;
    if (philo->name % 2 == 0 && philo->wisdom->philos_number > 1)
        spending_my_time(2);
    while (1)
    {
        pthread_create(&starve_demon, NULL, the_starve_demon_threat, philo);    
        if (!trying_to_take_the_fucking_forks(philo))
            break;
        if (!trying_to_eat_a_spaghetti_in_piece(philo, &starve_demon))
            break;
        if (!trying_to_sleep_like_a_lazy_bear(philo, 0))
            break;
        thinking_about_the_finitude_or_infinitude_of_life(philo);
    }
    return (NULL);
}