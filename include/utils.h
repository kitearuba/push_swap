#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

// Utility Functions
void    error_exit(const char *message);
int     is_sorted(t_stack *a);
int     ft_atoi(const char *str);

#endif // UTILS_H
