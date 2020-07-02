/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:33:16 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 17:07:45 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# ifdef __APPLE__
#  define APPLE 1
#  else
#  define APPLE 0
# endif
# define IDENTITY (float)0x7FFFFFFF
# include <glad/glad.h>
# include <math.h>
# include "GLFW/glfw3.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h> //TODO remove me and the rest

typedef enum 		e_axis
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
}					t_axis;

typedef struct 		s_mat4
{
	GLfloat			m[4 * 4];
}					t_mat4;

typedef struct 		s_mat3
{
	GLfloat			m[3 * 3];
}					t_mat3;

typedef struct 		s_fvec4
{
	float 			x;
	float 			y;
	float 			z;
	float 			w;
}					t_fvec4;

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
	t_vert 			*vertices;
	size_t 			vsize;
	t_faces			*indices;
	size_t 			isize;
	t_fvec3			min;
	t_fvec3			max;
}					t_obj;

typedef struct 		s_mvp
{
	t_mat4 			model;
	t_mat4 			proj;
	t_mat4 			view;
}					t_mvp;

typedef struct 		s_uniform
{
	GLint			model;
	GLint			proj;
	GLint			view;
	GLint			vtxcol;
	GLint			colmode;
	GLint			lerp;
}					t_uniform;

typedef struct 		s_env
{
	t_obj			*obj;
	GLFWwindow      *window;
	t_mvp			mvp;
	t_uniform		uni;
	t_fvec3			cam;
	t_fvec3			rot;
	float 			rotspeed;
	GLuint			vbo;
    GLuint			vao;
	GLuint			ebo;
	GLuint			texture;
	GLint			shader;
	GLfloat			lerp;
}			        t_env;

/*
 * LIBM
 */

/*
 * Matrices
 */

t_mat4 	m4_transpose(t_mat4 m);
t_mat4	m4_add(t_mat4 a, t_mat4 b);
t_mat4	m4_sub(t_mat4 a, t_mat4 b);
t_mat4	m4_mul(t_mat4 a, t_mat4 b);
t_mat4	m4_scale(t_mat4 m, float f);
t_mat4 	m4_copy(t_mat4 *in, t_mat4 to_copy);
t_mat4	m4_rotate_axis(t_mat4 m, t_axis axis, float angle);
t_mat4	m4_rotate(t_mat4 mat, float angle, t_fvec3 ax);
t_mat4	m4_translate(t_mat4 mat, t_fvec3 vec);
void	m4_set(t_mat4 *m, float f);

/*
 * Vectors
 */

t_fvec3 fv3_add(t_fvec3 a, t_fvec3 b);
t_fvec3 fv3_sub(t_fvec3 a, t_fvec3 b);
t_fvec3 fv3_mul(t_fvec3 a, t_fvec3 b);
t_fvec3 fv3_fmul(t_fvec3 a, float f);
t_fvec3	fv3_scale(t_fvec3 v, float f);
t_fvec3	fv3_cross(t_fvec3 a, t_fvec3 b);
t_fvec3	fv3_copy(t_fvec3 *in, t_fvec3 *to_copy);
t_fvec3	fv3_normalize(t_fvec3 v);
float	fv3_dot(t_fvec3 a, t_fvec3 b);
float	fv3_magnitude(t_fvec3 v);
void	fv3_set(t_fvec3 *v, float f);

/*
 * Misc
 */

float 	deg_to_rad(float deg);
float 	rad_to_deg(float deg);

/*
 * SCOP
 */

int				shutdown(int err);
int				setup_gl(t_env *env);
int				setup_shader(t_env *env);
int				setup_vertex(t_env *env);
int				setup_texture(t_env *env);
int				load_vert(char *pth);
int				load_frag(char *pth);
void			movement(t_env *env);
void			set_mvp(t_env *env);
void			set_color(t_env *env);
void			printAndTerminate(char *str);
void			framebuffer_size_callback(GLFWwindow* window, int width, int height);
void			processInput(t_env *env);
void			glShaderLogError(int shader, int shaderType);
void			glProgramLogError(int program);
t_mat4			look_at(t_fvec3 pos, t_fvec3 center, t_fvec3 up);
t_mat4		 	perspective(float fov, float aspect, float near, float far);
t_env			*get_env(void);
t_obj 			*parse_obj(char *pth);
t_vert			*lst_vertnew(float x, float y, float z);
void			lst_vertdel(t_vert **list);
t_faces			*lst_facenew(uint16_t a, uint16_t b, uint16_t c, uint16_t d);
void 			lst_facesdel(t_faces **list);
void			vertice_add(t_vert *vert, t_obj *ret, t_vert **last_vert);
void			face_add(t_faces *face, t_obj *ret, t_faces **last_face);
float			*delist_verts(t_vert *start, size_t size);
size_t 			count_verts(t_vert *verts);
size_t			count_faces(t_faces *faces);
unsigned int	*delist_faces(t_faces *start, size_t size, t_env *env);

#endif
