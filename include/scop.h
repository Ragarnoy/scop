/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:33:16 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/18 16:01:36 by tlernoul         ###   ########.fr       */
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

typedef struct 		s_obj
{
	float 			*vertices;
	unsigned int	*indices;
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
int	    loadVert(char *pth);
int	    loadFrag(char *pth);
void 	set_uniform_4f(char *uniform, float r, float g, float b, float a);
void 	set_uniform_3f(char *uniform, float r, float g, float b);
void	printAndTerminate(char *str);
void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
void	processInput(GLFWwindow *win);
int	    loadVert(char *pth);
int	    loadFrag(char *pth);
void	glShaderLogError(int shader, int shaderType);
void	glProgramLogError(int program);
t_env	*get_env(void);
t_obj 	*parse_obj(char *pth);

#endif
