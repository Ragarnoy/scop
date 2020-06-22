/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:33:16 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/19 15:52:36 by tlernoul         ###   ########.fr       */
/*   Updated: 2020/06/12 13:06:07 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# define APPLE 1
# else
# define APPLE 0
#endif
#ifndef SCOP_H
# define SCOP_H
# define VBO env->vbo
# define VAO env->vao
# define SHADERPROGRAM env->shProgram
# include <glad/glad.h>
# include "GLFW/glfw3.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct 		s_uvec4
{
	uint16_t		x;
	uint16_t		y;
	uint16_t		z;
	uint16_t		w;
}					t_uvec4;

typedef struct 		s_fvec3
{
	float 			x;
	float 			y;
	float 			z;
}					t_fvec3;

typedef struct 		s_vert
{
	t_fvec3 		v;
	struct s_vert	*next;
}					t_vert;


typedef struct 		s_faces
{
	t_uvec4 		uv;
	struct s_faces	*next;
}					t_faces;

typedef struct 		s_obj
{
	t_vert 			*verts;
	t_faces			*faces;
}					t_obj;

typedef struct 		s_env
{
	GLFWwindow      *window;
	unsigned int    vbo;
    unsigned int    vao;
	unsigned int    ebo;
	unsigned int 	texture;
	int             shProgram;

}			        t_env;

int	    shutdown(int err);
int	    setup_gl(t_env *env);
int     setup_shader(t_env *env);
int     setup_vertex(t_env *env);
int		setup_texture(t_env *env);
int	    load_vert(char *pth);
int	    load_frag(char *pth);
void 	set_uniform_4f(char *uniform, float r, float g, float b, float a);
void 	set_uniform_3f(char *uniform, float r, float g, float b);
void	printAndTerminate(char *str);
void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
void	processInput(GLFWwindow *win);
void	glShaderLogError(int shader, int shaderType);
void	glProgramLogError(int program);
t_env	*get_env(void);
t_obj 	*parse_obj(char *pth);
t_vert	*lst_vertnew(float x, float y, float z);
void	lst_vertdel(t_vert **list);
t_faces *lst_facenew(uint16_t a, uint16_t b, uint16_t c, uint16_t d);
void 	lst_facesdel(t_faces **list);

#endif
