/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:40:27 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/23 12:18:34 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define BUFF_SIZE 10
# define MAX_FD 400
# define MAX_INT 2147483647

# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct __attribute__((__packed__)) s_bmp_fileheader		t_fileheader;
typedef struct __attribute__((__packed__)) s_bmp_image			t_image;
typedef struct __attribute__((__packed__)) s_bmp				t_bmp;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_hsl
{
	float			h;
	float			s;
	float			l;
}					t_hsl;

typedef struct		s_hsv
{
	float			h;
	float			s;
	float			v;
}					t_hsv;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

struct				s_bmp_fileheader
{
	uint16_t		type;
	uint32_t		filesize;
	uint16_t		r1;
	uint16_t		r2;
	uint32_t		offset;
	uint32_t		size;
	int32_t			width;
	int32_t			height;
	uint16_t		planes;
	uint16_t		bitppx;
	uint32_t		compression;
	uint32_t		imgsize;
	uint32_t		x_res;
	uint32_t		y_res;
	uint32_t		num_colors;
	uint32_t		important_colors;
};

struct				s_bmp_image
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
};

typedef struct		s_bmp
{
	t_fileheader	fheader;
	unsigned char	*img;
}					t_bmp;

void				ft_free_bmp(t_bmp *file);

t_bmp				*ft_parse_bmp(char *pth);

int					ft_hsl_to_rgb(t_hsl hsl);

int					ft_hsv_to_rgb(t_hsv hsv);

double 				ft_atof(const char *str);

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

int					ft_isblank(int c);

void				*ft_memalloc(size_t size);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				ft_memdel(void **ap);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *s, int c, size_t n);

char				*ft_strcat(char *dest, const char *src);

void				ft_strclr(char *s);

char				*ft_strchr(const char *s, int c);

char				*ft_strdup(const char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t				ft_strlcat(char *dest, const char *src, size_t n);

size_t				ft_strlen(const char *s);

char				*ft_strmap(char const *s, char(*f)(char));

char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));

char				*ft_strncat(char *dest, const char *src, size_t n);

char				*ft_strrchr(const char *s, int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strcmp_nocase(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strstr(const char *str, const char *to_find);

char				*ft_strnstr(const char *str, const char *to_find,
					size_t len);

char				*ft_strsub(const char *s, unsigned int start, size_t len);

char				**ft_strsplit(const char *s, char c);

int					ft_strequ(const char *s1, const char *s2);

int					ft_strnequ(const char *s1, const char *s2, size_t n);

char				*ft_strjoin(const char *s1, const char *s2);

char				*ft_strtrim(const char *s);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_putstr(const char *str);

void				ft_putchar(char c);

void				ft_putendl(const char *s);

void				ft_putnbr(int n);

void				ft_putstr_fd(const char *str, int fd);

void				ft_putchar_fd(char c, int fd);

void				ft_putendl_fd(const char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

int					ft_getndigits(int nb);

char				*ft_itoa(int n);

char				*ft_itoabase(int n, int base);

void				ft_lstadd(t_list **alst, t_list *new);

t_list				*ft_lstnew(const void *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*ft_strcapitalize(char *str);

int					ft_str_is_alpha(char *str);

int					ft_str_is_lowercase(char *str);

int					ft_str_is_numeric(char *str);

int					ft_str_is_printable(char *str);

int					ft_str_is_uppercase(char *str);

char				*ft_strlowcase(char *str);

char				*ft_strupcase(char *str);

void				ft_putlst(t_list *elem);

t_list				*ft_lstsplit(const char *s, char c);

char				*ft_strappend(char *add, char *end, int l);

size_t				ft_strclen(const char *s, char c);

size_t				ft_strlenc(const char *s, char c);

size_t				ft_strclenc(const char *s, char b, char c);

int					ft_strrep(char *s, char r, char c);

int					get_next_line(const int fd, char **line);

size_t				ft_countwords(const char *s, char c);

char				**ft_retwords(const char *s, char c);

#endif
