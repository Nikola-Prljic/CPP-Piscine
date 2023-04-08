/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:38:14 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/08 17:07:28 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
    this->setType(type);
    return ;
}

Weapon::~Weapon( void )
{
    return ;
}

const std::string &Weapon::getType( void )
{
    return(this->type);
}

void Weapon::setType(std::string newtype)
{
    this->type = newtype;
    return ;
}
