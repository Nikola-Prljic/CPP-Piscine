/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:37:54 by nprljic           #+#    #+#             */
/*   Updated: 2023/04/01 15:14:47 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char    ft_toupper(char c)
{
    if ( c >= 'a' && c <= 'z' )
        c -= ('a' - 'A');
    return (c);
}

int main(int argc, char **argv)
{
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    for(int i = 1; argv[i]; ++i)
        for(int x = 0; argv[i][x]; ++x)
            std::cout << ft_toupper(argv[i][x]);
    std::cout << std::endl;
    return 0;
}