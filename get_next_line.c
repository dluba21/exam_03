#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *ft_calloc(int n)
{
	char *str;
	int		i;

	i = 0;
	str = malloc(n);
	if (!str)
		return (NULL);
	while (i < n)
		str[i++] = 0;
	return (str);
	
}

char *get_next_line(int fd)
{
	char c;
	int rd;
	char *str;
	int i;
	
	if ((rd = read(fd, &c, 1)) == 0)
		return (NULL);
	
	str = ft_calloc(100000);
	i = 0;
	str[i++] = c;
	while ((rd = read(fd, &c, 1)) > 0 && c != '\n')
		str[i++] = c;
	if (c == '\n')
		str[i] = '\n';
	return (str);

}


//char	*get_next_line(int fd)
//{
//	int rd = 0;
//	char	c;
//	if ((rd = read(fd, &c, 1)) == 0)
//		return (NULL); // Возвращаем NULL, если файл пустой
//	char	*line = malloc(100000); // 1000000 для BigFile1
//	char	*word = line;
//	*line++ = c;
//	while ((rd = read(fd, &c, 1)) > 0 && c != '\n')
//		*line++ = c;
//	if (c == '\n')
//		*line++ = '\n';
//	*line = '\0';
//	return (word);
//}

int main()
{
	int fd = open("aboba.txt", O_RDONLY);
	if (fd < 0)
		printf("govmo\n");
	printf("%s", get_next_line(fd));
}
