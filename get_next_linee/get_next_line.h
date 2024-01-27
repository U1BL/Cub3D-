
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

char	*read_buffer_size(int fd, char *str);
char	*ft_line(char *str);
char	*ft_remain(char *str);

char	*get_next_line(int fd);

char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_strchr_get(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif