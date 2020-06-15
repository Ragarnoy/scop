/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:33:16 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/11 17:04:23 by tlernoul         ###   ########.fr       */
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
# include <glad/glad.h>
# include "GLFW/glfw3.h"
# include "../libft/libft.h"

typedef struct 		s_env
{
	GLFWwindow      *window;
	unsigned int    vbo;
    unsigned int    vao;
	unsigned int    ebo;
	int             shProgram;

}			        t_env;

int	    shutdown(int err);
int	    setup_gl(t_env *env);
int     setup_shader(t_env *env);
int     setup_vertex(t_env *env);
int	    loadVert(char *pth);
int	    loadFrag(char *pth);
void	printAndTerminate(char *str);
void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
void	processInput(GLFWwindow *win);
int	    loadVert(char *pth);
int	    loadFrag(char *pth);
void	glShaderLogError(int shader, int shaderType);
void	glProgramLogError(int program);
t_env	*get_env(void);

#endif
