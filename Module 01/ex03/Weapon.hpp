/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:29:24 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/08 17:02:08 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    private:
    
        std::string type;
    
    public:

        Weapon( std::string type );
        ~Weapon();
        const std::string& getType( void );
        void setType(std::string newtype);
};

#endif