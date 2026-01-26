/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillymilly <phillymilly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:06:39 by fatkeski          #+#    #+#             */
/*   Updated: 2026/01/25 15:36:14 by phillymilly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		if(!runBSQ(stdin))
			fprintf(stderr, "map error\n");
	}
	else
	{
		for(int i = 1; i < argc; i++)
        {
            if(!readFile(argv[i]))
                fprintf(stderr, "map error\n");
            if(i < argc - 1)
                fprintf(stdout, "\n");
        }
	}
	return(0);
}