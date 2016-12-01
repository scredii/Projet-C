/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:35:50 by ddufour           #+#    #+#             */
/*   Updated: 2016/09/19 18:22:10 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 50
# include "libft/libft.h"

typedef struct		s_file
{
	char			*content;
	int				file_descriptor;
	int				retour;
	struct s_file	*next;
}					t_content;

int					get_next_line(const int fd, char **line);

#endif
