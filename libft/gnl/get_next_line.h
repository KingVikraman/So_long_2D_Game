#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h> 
# include <stdio.h>
# include <fcntl.h>

/*********** CHAR HEADERS ***********/
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_line(char *buffer);

/*********** SIZE_T HEADERS ***********/
size_t	ft_strlen(const char *String);

/*********** VOID HEADERS ***********/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementNum, size_t elementSize);

#endif
