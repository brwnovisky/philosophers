# include "../inc/philo.h"

size_t	size_of_a_string(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		++len;
	return (len);
}

void	*malloc_with_zeros(size_t nmemb, size_t size)
{
	void	*ptr;
	int		result;
	void	*s;

	result = nmemb * size;
	if (result == 0 || result / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(result);
	s = ptr;
	while (result--)
		*(unsigned char *)s++ = 0;
	return (ptr);
}

size_t	a_to_sizet(const char *nptr, int *not_a_digit)
{
	size_t  result;

	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
    if (size_of_a_string(nptr) > 19)
    {
        *not_a_digit = 1;
        return (result);
    }
	while (*nptr && !*not_a_digit)
    {
        if (*nptr > 47 && *nptr < 58)
		    result = result * 10 + *nptr++ - '0';
        else
            *not_a_digit = 1;
    }
	return (result);
}

size_t timestamp_in_ms(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * (size_t)1000) + (tv.tv_usec / (size_t)1000));
}

void    spending_my_time(size_t time)
{
	size_t	start;

	start = timestamp_in_ms();
	while ((timestamp_in_ms() - start) < time)
		usleep(time / 10);
}