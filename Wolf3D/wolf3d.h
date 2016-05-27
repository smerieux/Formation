/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 10:29:34 by smerieux          #+#    #+#             */
/*   Updated: 2014/01/19 19:07:20 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define WIDTH 800
# define HEIGHT 600
# define KP 2
# define KR 3
# define KPM (1L<<0)
# define KRM (1L<<1)
# define MOVE 0.04
# define ROT 0.015

typedef struct		s_coor
{
	double	x_cam;
	double	y_cam;
	double	vec_x;
	double	vec_y;
	double	plan_x;
	double	plan_y;
}					t_coor;

typedef struct		s_ray
{
	double	x_ray;
	double	y_ray;
	double	vec_x;
	double	vec_y;
	double	win_x;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	double	side_x;
	double	side_y;
	int		d_start;
	int		d_end;
	int		l_height;
	int		hit;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
}					t_ray;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*p_img;
	char	*img;
	int		side;
	int		bpp;
	int		size_line;
	int		endian;
	int		**map;
	int		up;
	int		down;
	int		left;
	int		right;
	t_ray	ray;
	t_coor	coor;
}					t_env;

int		*ft_getparams(int fd);
int		loop_hook(t_env *env);
int		**ft_init_tab(int col, int line);
int		**ft_parse(int fd, int *tab_params);
int		key_hook(int keycode, t_env *env);
int		ft_init_ptr(t_env *env);
int		which_key_press(int keycode, t_env *env);
int		which_key_release(int keycode, t_env *env);
int		ft_check_open(void);
void	ft_check_close(int fd);
void	ft_frseetab(int **tab);
void	ft_init_coor(t_env *env);
void	ft_img_draw_pxl(t_env *env, int x, int y, int color);
void	ft_ray_coor(t_env *env, int x);
void	ft_step_x_or_y(t_env *env);
void	ft_check_hit_ray(t_env *env);
void	ft_calculate(t_env *env);
void	ft_draw(t_env *env);
void	ft_draw_line(t_env *env, int x, int y);
void	ft_move_up(t_env *env);
void	ft_move_down(t_env *env);
void	ft_rot_right(t_env *env);
void	ft_rot_left(t_env *env);

#endif		/* !WOLF3D_H */
