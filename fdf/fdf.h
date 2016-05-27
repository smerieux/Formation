/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 10:29:34 by smerieux          #+#    #+#             */
/*   Updated: 2015/12/14 07:25:59 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define CSTE 20
# define PLUS 0x45
# define MINUS 0x4E
# define ZERO 0x52
# define ESC 0x35
# define REZ 0x0F
# define ISO 0x22
# define PARA 0x23
# define LEFT 0x7B
# define UP 0x7E
# define RIGHT 0x7C
# define DOWN 0x7D
# define LWIDTH 2200
# define LHEIGHT 1300
# define SWIDTH 800
# define SHEIGHT 600
# define KP 2
# define KR 3
# define KPM (1L<<0)
# define KRM (1L<<1)
# define I env->data->i
# define J env->data->j
# define MAP env->data->map
# define TAB env->data->tab
# define TX env->trans->move_x
# define TY env->trans->move_y
# define TZ env->trans->move_z
# define CX env->trans->coef_x
# define CY env->trans->coef_y

# include <libft.h>
# include <mlx.h>

typedef struct		s_coor
{
	int		x;
	int		y;
	int		z;
	int		dx;
	int		dy;
}					t_coor;

typedef struct		s_data
{
	int		i;
	int		j;
	int		nb;
	int		*tab;
	t_coor	**map;
}					t_data;

typedef struct		s_trans
{
	int		coef_x;
	int		coef_y;
	double	move_x;
	double	move_y;
	double	move_z;
}					t_trans;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*p_img;
	char	*img;
	int		width;
	int		height;
	int		e2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		side;
	int		bpp;
	int		size_line;
	int		endian;
	int		iso;
	int		para;
	int		up;
	int		down;
	int		left;
	int		right;
	int		plus;
	int		minus;
	int		zero;
	int		rez;
	t_data	*data;
	t_trans	*trans;
}					t_env;

t_coor				**ft_init_tab(int nb, t_env *env);
int					ft_init_ptr(t_env *env);
int					loop_hook(t_env *env);
int					key_hook(int keycode, t_env *env);
int					which_key_press(int keycode, t_env *env);
int					which_key_release(int keycode, t_env *env);
int					ft_check_open(char *line);
void				ft_getparams(int fd, char *line, t_env *env);
void				ft_init_coor(t_env *env);
void				ft_init_data(t_env *env);
void				ft_init_map(t_data *data);
void				wkp_bis(int keycode, t_env *env);
void				ft_parse(int fd, char **line, t_env *env);
void				ft_usage(int argc);
void				ft_check_close(int fd);
void				ft_free(t_env *env);
void				ft_line(t_coor pt0, t_coor pt1, t_env *env);
void				ft_line_h(t_coor pt0, t_coor pt1, t_env *env);
void				ft_line_v(t_coor pt0, t_coor pt1, t_env *env);
void				ft_iso(t_env *env);
void				ft_para(t_env *env);
void				ft_img_draw_pxl(t_env *env, int x, int y, int color);
void				ft_calculate(t_env *env);
void				ft_draw(t_env *env);
void				ft_draw_map(t_env *env);
void				ft_move_up(t_env *env);
void				ft_move_down(t_env *env);
void				ft_move_right(t_env *env);
void				ft_move_left(t_env *env);
void				ft_zoom_in(t_env *env);
void				ft_zoom_out(t_env *env);
void				ft_zoom_reset(t_env *env);
void				ft_move_reset(t_env *env);

#endif
