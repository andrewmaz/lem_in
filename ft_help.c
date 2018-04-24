/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:26:16 by amazurok          #+#    #+#             */
/*   Updated: 2018/04/24 14:29:11 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_help(void)
{
	ft_printf("________________HELP_________________\n");
	ft_printf("| %-14s %-19s|\n", "-h", "<help>");
	ft_printf("| %-14s %-19s|\n", "-v", "<visualization>");
	ft_printf("| %-14s %-19s|\n", "-n", "<number of command>");
	ft_printf("| %-14s %-19s|\n", "-k", "<print command>");
	ft_printf("| %-14s %-19s|\n", "-f [file name]", "<input from file>");
	ft_printf("| %-14s %-19s|\n", "-c", "<colour of command>");
	ft_printf("| %-14s {green}%-19s{eoc}|\n", "", "<push>");
	ft_printf("| %-14s {blue}%-19s{eoc}|\n", "", "<swap>");
	ft_printf("| %-14s {cyan}%-19s{eoc}|\n", "", "<rotate>");
	ft_printf("| %-14s {yellow}%-19s{eoc}|\n", "", "<reverse rotate>");
	ft_printf("|___________________________________|\n");
}
