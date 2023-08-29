#include "philo.h"

/*----------------------------------------------------------------------------*/
/*                           how_philosophers_are_born.c                      */
/*----------------------------------------------------------------------------*/

int     philosofhy_is_the_love_of_wisdom(t_wisdom **wisdom, \
t_philo **philo, int args_quantity, char **args_quality);

void    forks_factory(t_wisdom *wisdom);

void    philosophers_genetical_handling(t_philo *philo, t_wisdom *wisdom);

void    philosophers_maternity(t_philo *philo, t_wisdom *wisdom);



/*----------------------------------------------------------------------------*/
/*                           philo_news_and_fallacies_refuted.c               */
/*----------------------------------------------------------------------------*/

int     fallacies_will_not_be_appreciated(t_wisdom **wisdom, t_philo **philo, \
int args_quantity, int possible_fallacies);

void    philo_news(t_philo *philo, char *event);

void    philo_news_censorship(t_philo *philo);
 

/*----------------------------------------------------------------------------*/
/*                           philosophers_lifestyle.c                         */
/*----------------------------------------------------------------------------*/

void    *the_philosopher_lifestyle(void *arg);

int     trying_to_take_the_fucking_forks(t_philo *philo);

int     trying_to_eat_a_spaghetti_in_piece(t_philo *philo, \
pthread_t *starve_demon);

int     trying_to_sleep_like_a_lazy_bear(t_philo *philo, \
int only_releasing_the_fucking_forks);

void    thinking_about_the_finitude_or_infinitude_of_life(t_philo *philo);


/*----------------------------------------------------------------------------*/
/*                           philosophical_utilities.c                        */
/*----------------------------------------------------------------------------*/

size_t  a_to_sizet(const char *nptr, int *not_a_digit);

size_t  size_of_a_string(const char *s);

size_t  timestamp_in_ms(void);

void    *malloc_with_zeros(size_t nmemb, size_t size);

void    spending_my_time(size_t time);


/*----------------------------------------------------------------------------*/
/*                           when_philos_leaves_this_world.c                  */
/*----------------------------------------------------------------------------*/

int     cleaning_the_agora(t_wisdom **wisdom, t_philo **philo, \
int fallacies_not_accepted);

void    here_philosophers_rest_in_peace(t_wisdom *wisdom, t_philo *philo);

void    *the_starve_demon_threat(void *arg);
