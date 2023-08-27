# include "../inc/philo.h"

int    philosofhy_is_the_love_of_wisdom(t_wisdom **wisdom, \
t_philo **philo, int args_quantity, char **args_quality)
{
    int     not_a_digit;

    not_a_digit = 0;
    (*wisdom) = malloc_with_zeros(1, sizeof(t_wisdom));
    if (args_quantity == 5 || args_quantity == 6)
    {
        (*wisdom)->philos_number = a_to_sizet(args_quality[1], &not_a_digit);
        (*wisdom)->life_time = a_to_sizet(args_quality[2], &not_a_digit);
        (*wisdom)->eat_time = a_to_sizet(args_quality[3], &not_a_digit);
        (*wisdom)->sleep_time = a_to_sizet(args_quality[4], &not_a_digit);
        if (args_quantity == 6)
            (*wisdom)->spaghetti_amount= a_to_sizet(args_quality[5], \
            &not_a_digit);
        pthread_mutex_init(&((*wisdom)->philos_fed_lock), NULL);
        pthread_mutex_init(&((*wisdom)->cemetery_lock), NULL);
        pthread_mutex_init(&((*wisdom)->philo_feed_lock), NULL);
    }
    *philo = malloc_with_zeros((*wisdom)->philos_number, sizeof(t_philo));
    return(not_a_digit);
}

void    philosophers_genetical_handling(t_philo *philo, t_wisdom *wisdom)
{
    size_t          index;
    pthread_mutex_t forever_alone_pseudo_fork;
    
    index = -1;
    pthread_mutex_init(&(forever_alone_pseudo_fork), NULL);
    while (++index < wisdom->philos_number)
    {

        philo[index].name = index + 1;
        philo[index].wisdom = wisdom;
        pthread_mutex_init(&(philo[index].right_fork), NULL);
        if (index == wisdom->philos_number - 1)
        {
            if (wisdom->philos_number >= 2)
                philo[0].left_fork = &philo[index].right_fork;
            else
                philo[0].left_fork = &forever_alone_pseudo_fork;
        }
        if (index)
            philo[index].left_fork = &philo[index - 1].right_fork;    
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

