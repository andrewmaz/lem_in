/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:26:16 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/04 12:41:46 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_help(void)
{
	ft_printf("__________________HELP__________________\n");
	ft_printf("| %-37s|\n", "  usage: ./lem-in [key] < mapfile");
	ft_printf("| %-37s|\n", "               Key:");
	ft_printf("| %-14s %-22s|\n", "-h", "<help>");
	ft_printf("| %-14s %-22s|\n", "-l", "<length road>");
	ft_printf("| %-14s %-22s|\n", "-n", "<number of iterations>");
	ft_printf("| %-14s %-22s|\n", "-r", "<print road>");
	ft_printf("| %-14s %-22s|\n", "-f [file name]", "<input from file>");
	ft_printf("| %-14s %-22s|\n", "-o [file name]", "<output to file>");
	ft_printf("| %-14s %-22s|\n", "-c", "<colour mod>");
	ft_printf("| %-14s {red}%-22s{eoc}|\n", "", "<START>");
	ft_printf("| %-14s {green}%-22s{eoc}|\n", "", "<END>");
	ft_printf("|______________________________________|\n");
}
