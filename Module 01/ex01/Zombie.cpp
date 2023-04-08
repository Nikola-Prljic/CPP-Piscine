/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:26:28 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/05 18:43:43 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
    return ;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
    return ;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void Zombie::setname( std::string name )
{
    this->_name = name;
    return ;
}