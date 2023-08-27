#include "philo.h"

typedef struct s_wisdom
{
    pthread_mutex_t         philos_fed_lock;
    pthread_mutex_t         cemetery_lock;
    pthread_mutex_t         philo_feed_lock;
    size_t                  cemetery;
    size_t                  eat_time;
    size_t                  life_time;
    size_t                  philos_fed;
    size_t                  philos_number;
    size_t                  philo_feed_censorship;
    size_t                  sleep_time;
    size_t                  spaghetti_amount;
    size_t                  start_time;
}                           t_wisdom;

typedef struct s_philo
{
    pthread_mutex_t         *left_fork;
    pthread_mutex_t         right_fork;
    pthread_t               philo;
    size_t                  meals_count;
    size_t                  name;
    size_t                  last_eat;
    struct s_wisdom         *wisdom;
}                           t_philo;
