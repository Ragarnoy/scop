/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:33:16 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/04 19:08:56 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# ifdef __APPLE__
#  define APPLE 1
# else
#  define APPLE 0
# endif
# define IDENTITY 0x7FFFFFFF
# include <glad/glad.h>
# include <math.h>
# include "GLFW/glfw3.h"
# include "../libft/libft.h"
# include <math.h>

typedef enum		e_axis
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
}					t_axis;

typedef struct		s_mat4
{
	GLfloat			m[4 * 4];
}					t_mat4;

typedef struct		s_mat3
{
	GLfloat			m[3 * 3];
}					t_mat3;

typedef struct		s_fvec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_fvec4;

typedef struct		s_uvec4
{
	uint16_t		x;
	uint16_t		y;
	uint16_t		z;
	uint16_t		w;
}					t_uvec4;

typedef struct		s_fvec3
{
	float			x;
	float			y;
	float			z;
}					t_fvec3;

typedef struct		s_vert
{
	struct s_vert	*next;
	t_fvec3			v;
}					t_vert;

typedef struct		s_faces
{
	struct s_faces	*next;
	t_uvec4			uv;
}					t_face;

typedef struct		s_obj
{
	t_vert			*vertices;
	size_t			vsize;
	t_face			*indices;
	size_t			isize;
	t_fvec3			min;
	t_fvec3			max;
}					t_obj;

typedef struct		s_mvp
{
	t_mat4			model;
	t_mat4			proj;
	t_mat4			view;
}					t_mvp;

typedef struct		s_uniform
{
	GLint			model;
	GLint			proj;
	GLint			view;
	GLint			vtxcol;
	GLint			colmode;
	GLint			lerp;
}					t_uniform;

typedef struct		s_env
{
	t_obj			*obj;
	GLFWwindow		*window;
	t_mvp			mvp;
	t_uniform		uni;
	t_fvec3			cam;
	t_fvec3			rotdir;
	float			rotspeed;
	GLuint			vbo;
	GLuint			vao;
	GLuint			ebo;
	GLuint			texture;
	GLint			shader;
	GLfloat			lerp;
}					t_env;

/*
** LIBM
*/

/*
** Matrices
*/

t_mat4				m4_transpose(t_mat4 m);
t_mat4				m4_add(t_mat4 a, t_mat4 b);
t_mat4				m4_sub(t_mat4 a, t_mat4 b);
t_mat4				m4_mul(t_mat4 a, t_mat4 b);
t_mat4				m4_scale(t_mat4 m, float f);
t_mat4				m4_copy(t_mat4 *in, t_mat4 to_copy);
t_mat4				m4_rotate(t_mat4 mat, float angle, t_fvec3 ax);
t_mat4				m4_translate(t_mat4 mat, t_fvec3 vec);
void				m4_set(t_mat4 *m, float f);

/*
** Vectors
*/

t_fvec3				fv3_add(t_fvec3 a, t_fvec3 b);
t_fvec3				fv3_sub(t_fvec3 a, t_fvec3 b);
t_fvec3				fv3_mul(t_fvec3 a, t_fvec3 b);
t_fvec3				fv3_fmul(t_fvec3 a, float f);
t_fvec3				fv3_scale(t_fvec3 v, float f);
t_fvec3				fv3_cross(t_fvec3 a, t_fvec3 b);
t_fvec3				fv3_copy(t_fvec3 *in, t_fvec3 *to_copy);
t_fvec3				fv3_normalize(t_fvec3 v);
float				fv3_dot(t_fvec3 a, t_fvec3 b);
float				fv3_magnitude(t_fvec3 v);
void				fv3_set(t_fvec3 *v, float f);

/*
** Misc
*/

float				deg_to_rad(float deg);
float				rad_to_deg(float deg);

/*
** SCOP
*/

int					shutdown(int err);
int					setup_gl(t_env *env);
int					setup_shader(t_env *env);
int					setup_vertex(t_env *env);
int					setup_texture(t_env *env);
int					load_vert(char *pth);
int					load_frag(char *pth);
void				set_min(t_obj *obj, t_vert *tmp);
void				set_max(t_obj *obj, t_vert *tmp);
void				movement(t_env *env);
void				set_mvp(t_env *env);
void				set_color(t_env *env);
void				print_and_terminate(char *str);
void				frmbuff_size_cback(GLFWwindow *win, int width, int height);
void				process_input(t_env *env);
void				glshader_log_error(int shader, int shader_type);
void				glprogram_log_error(int program);
t_obj				*fill_list(int fd, t_obj *ret);
t_mat4				perspective(float fov, float aspect, float near, float far);
t_env				*get_env(void);
t_obj				*parse_obj(char *pth);
t_vert				*lst_vertnew(float x, float y, float z);
t_face				*lst_facenew(GLuint a, GLuint b, GLuint c, GLuint d);
void				vertice_add(t_vert *vert, t_obj *ret, t_vert **last_vert);
void				face_add(t_face *face, t_obj *ret, t_face **last_face);
float				*delist_verts(t_vert *start, size_t size);
size_t				count_verts(t_vert *verts);
size_t				count_faces(t_face *faces);
unsigned int		*delist_faces(t_face *start, size_t size, t_env *env);

#endif
