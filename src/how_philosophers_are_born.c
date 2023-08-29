# include "../inc/philo.h"

int    philosofhy_is_the_love_of_wisdom(t_wisdom **wisdom, \
t_philo **philo, int args_quantity, char **args_quality)
{
    int     not_a_digit;

    not_a_digit = 0;
    *wisdom = malloc_with_zeros(1, sizeof(t_wisdom));
    if (args_quantity > 1)
    (*wisdom)->philos_number = a_to_sizet(args_quality[1], &not_a_digit);
    if (args_quantity > 2)
    (*wisdom)->life_time = a_to_sizet(args_quality[2], &not_a_digit);
    if (args_quantity > 3)
    (*wisdom)->eat_time = a_to_sizet(args_quality[3], &not_a_digit);
    if (args_quantity > 5)
    (*wisdom)->sleep_time = a_to_sizet(args_quality[4], &not_a_digit);
    if (args_quantity == 6)
        (*wisdom)->spaghetti_amount= a_to_sizet(args_quality[5], &not_a_digit);
    pthread_mutex_init(&((*wisdom)->philos_fed_lock), NULL);
    pthread_mutex_init(&((*wisdom)->cemetery_lock), NULL);
    pthread_mutex_init(&((*wisdom)->philo_news_lock), NULL);
    if (!not_a_digit)
        *philo = malloc_with_zeros((*wisdom)->philos_number, sizeof(t_philo));
    return(not_a_digit);
}

void    philosophers_genetical_handling(t_philo *philo, t_wisdom *wisdom)
{
    size_t          index;
    
    index = -1;
    while (++index < wisdom->philos_number)
    {
        philo[index].name = index + 1;
        philo[index].wisdom = wisdom;
        philo[index].right_fork = &wisdom->forks[index];
        if (index == wisdom->philos_number - 1)
            philo[0].left_fork = &wisdom->forks[index];
        if (index)
            philo[index].left_fork = &wisdom->forks[index - 1];    
    }
}
void    philosophers_maternity(t_philo *philo, t_wisdom *wisdom)
{
    size_t  index;
    index = -1;
    while (++index < wisdom->philos_number)
    {
        if (!index)         
            wisdom->start_time = timestamp_in_ms();
        pthread_create(&philo[index].philo, NULL, \
        &the_philosopher_lifestyle, &philo[index]);
    }
}

void    forks_factory(t_wisdom *wisdom)
{
    size_t  index;
    index = -1;
    wisdom->forks = malloc_with_zeros(wisdom->philos_number, \
    sizeof(pthread_mutex_t));
    while (++index < wisdom->philos_number)
        pthread_mutex_init(&wisdom->forks[index], NULL);
}
