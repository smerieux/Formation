/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:01:46 by smerieux          #+#    #+#             */
/*   Updated: 2015/07/03 16:00:28 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdlib.h>
# include <libft.h>

void	ft_initcat(char *cat, int j);
void	ft_reduce(double *x, int rank);
void	ft_solve_r0(double x);
void	ft_solve_r2_detneg(double res, double det, double *x);
void	ft_solve_r2_detpos(double res, double det, double *x);
void	ft_solve_r2_det0(double res, double *x);
void	ft_solve(int rank, double *x);
void	ft_display_rank(int rank);
void	ft_display_det(double det);
void	ft_cant_solve(double *x, int rank);
void	ft_lets_solve(double *x, int rank);
double	ft_getxn_right(char **grid, double x, char *cat, int i);
double	ft_getx0(char **grid, double x);
double	ft_getxn(char **grid, double x, int j);
double	ft_sqrt(double x);
int		ft_getrank(char *str);
int		ft_ajust(int rank, double *x);
int		ft_check(char **grid);
int		ft_compute(char *str);

#endif
