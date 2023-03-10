/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:45:19 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/10 14:01:44 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../includes/minishell.h"

/* The 2 following functions check if the quotes are closed
and moves our int pointer past the last quote found.*/

static void	ft_simple_quotes(char const *s, int *j)
{
	int	i;

	(*j)++;
	i = (*j);
	while (s[i] && s[i] != '\'')
		i++;
	if (s[i] == '\'')
		while (s[(*j)] && s[(*j)] != '\'')
			(*j)++;
}

static void	ft_double_quotes(char const *s, int *j)
{
	int	i;

	(*j)++;
	i = (*j);
	while (s[i] && s[i] != '\"')
		i++;
	if (s[i] == '\"')
		while (s[(*j)] && s[(*j)] != '"')
			(*j)++;
}

void	ft_quotes(char const *s, int *j)
{
	if (s[(*j)] == '"')
		ft_double_quotes(s, j);
	else if (s[(*j)] == '\'')
		ft_simple_quotes(s, j);
}

/* Returns 1 if character is a separator*/

int	ft_separator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

char	**ft_free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		ft_free_remove(global.m_free, strs[i]);
	ft_free_remove(global.m_free, strs);
	return (0);
}
