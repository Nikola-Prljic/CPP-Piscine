/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:32:37 by nprljic           #+#    #+#             */
/*   Updated: 2023/08/04 12:34:02 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

std::string ft_to_string( const int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

Zombie *zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];

    for(int i = 0; i < N; i++)
        horde[i].setname(name + ' ' + ft_to_string(i + 1));
    return (horde);
}
