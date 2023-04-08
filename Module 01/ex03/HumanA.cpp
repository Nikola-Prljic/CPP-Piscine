/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:28:19 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/08 17:06:26 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name , Weapon& weapon ) : _name(name) , _weapon(weapon)
{
    return ;
}

HumanA::~HumanA( void )
{
    return ;
}

void HumanA::attack( void ) const
{
    
    std::cout << _name <<" attacks with their " << this->_weapon.getType() << std::endl;
    return ;
}
