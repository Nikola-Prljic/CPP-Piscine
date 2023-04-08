/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:32:37 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/05 19:11:48 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];

    for(int i = 0; i < N; i++)
        horde[i].setname(name + ' ' + std::to_string(i + 1));
    return (horde);
}
