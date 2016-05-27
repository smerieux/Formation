/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:02:46 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:02:54 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RT_H
# define FT_RT_H

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_coef
{
	double			r;
	double			g;
	double			b;
}					t_coef;

typedef struct		s_obj
{
	double			a;
	double			b;
	double			c;
	float			delta;
	float			alpha1;
	float			alpha2;
}					t_obj;

typedef struct		s_vec
{
	t_vector		a;
	t_vector		b;
	t_vector		g;
	t_vector		d;
	t_vector		e;
}					t_vec;

typedef struct		s_material
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	float			diffuse;
	float			specular;
	float			shininess;
	float			transparent;
	float			reflective;
	float			refraction;
}					t_material;

typedef struct		s_object
{
	t_vector		pos;
	t_vector		axe;
	double			misc;
	double			hyp;
	char			*name;
	char			*type;
	t_material		material;
}					t_object;

typedef struct		s_camera
{
	t_vector		pos;
	t_vector		dir;
	t_vector		rot;
}					t_camera;

typedef struct		s_light
{
	t_vector		pos;
	t_vector		dir;
	float			coef;
	unsigned int	rgb[3];
}					t_light;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	t_object		*objects;
	int				nb_objects;
	t_light			*lights;
	int				nb_lights;
	t_camera		cam;
	int				width;
	int				height;
	float			fov;
	double			r;
	double			g;
	double			b;
}					t_data;

typedef struct		s_tab_obj
{
	char			*type;
	double			(*func)(t_object, t_vector, t_vector);
}					t_tab_obj;

typedef struct		s_file
{
	struct s_file	*next;
	char			*line;
}					t_file;

void				ft_raytracing(t_data *d);
double				ft_find_inter(t_data *d, int *i);
void				ft_destroy_data(t_data *d);
void				ft_find_color(double alpha, t_data *d, int i);
void				ft_color_normalize(t_data *d);
void				ft_coef_color(t_object obj, t_data *d, int i, t_vector n);
t_object			ft_parse(t_file **file, t_object new);
double				ft_diffuse_light(t_object obj, t_light light, t_vector n);
double				ft_specular_light(t_object obj, t_light light, \
					t_vector n1, t_vector n2);
t_file				*ft_init(t_file **file, t_data *d, char *str);
void				ft_parsing(t_file *file, t_data *d);
void				ft_get_light(t_file *file, t_data *d);
int					ft_check_float(char *str);
void				ft_add_file(t_file **file, char *line);
void				ft_init_object(t_object *new);
double				ft_plane(t_object obj, t_vector dir, t_vector o);
double				ft_sphere(t_object obj, t_vector dir, t_vector o);
double				ft_cylinder(t_object obj, t_vector dir, t_vector o);
double				ft_cone(t_object obj, t_vector dir, t_vector o);
double				ft_hyperboloid(t_object obj, t_vector dir, t_vector o);
double				ft_vector_dot(t_vector a, t_vector b);
double				ft_find_alpha(t_vector o, t_vector inter);
t_vector			ft_get_normal_cylinder(t_object obj, t_vector inter);
t_vector			ft_get_normal_cone(t_object obj, t_vector inter);
t_vector			ft_vector_add(t_vector a, t_vector b);
t_vector			ft_vector_sub(t_vector a, t_vector b);
t_vector			ft_vector_mult(t_vector a, double b);
t_vector			ft_vector_wedge(t_vector a, t_vector b);
t_vector			ft_vector_project(t_vector a, t_vector b);
t_vector			ft_vector_normalize(t_vector v);
t_vector			ft_vector_neg(t_vector v);
t_vector			ft_vector_intercept(t_vector v, t_vector o, double alpha);
t_vector			ft_vector_rotation_x(t_vector v, double alpha);
t_vector			ft_vector_rotation_y(t_vector v, double alpha);
t_vector			ft_vector_rotation_z(t_vector v, double alpha);

#endif
