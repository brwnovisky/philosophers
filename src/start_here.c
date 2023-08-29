# include "../inc/philo.h"

int main(int args_quantity, char **args_quality)
{
    t_philo     *philo;
    t_wisdom    *wisdom;
    int         possible_fallacies;
        
    possible_fallacies = philosofhy_is_the_love_of_wisdom(&wisdom, &philo, \
    args_quantity, args_quality);
    if (fallacies_will_not_be_appreciated(&wisdom, &philo, args_quantity, \
    possible_fallacies))
        return (EXIT_FAILURE); 
    forks_factory(wisdom);
    philosophers_genetical_handling(philo, wisdom);
    philosophers_maternity(philo, wisdom);
    here_philosophers_rest_in_peace(wisdom, philo);
    cleaning_the_agora(&wisdom, &philo, possible_fallacies);
    return (EXIT_SUCCESS);
}