/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:28:19 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/08 17:06:31 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
    this->_weapon = NULL;
    return ;
}

HumanB::~HumanB( void )
{
    return ;
}

void HumanB::attack ( void ) const
{
    if(this->_weapon && this->_weapon->getType() != "")
        std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
    return ;
}

void HumanB::setWeapon( Weapon& weapon )
{
    this->_weapon = &weapon;
    return ;
}