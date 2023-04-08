/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:27 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/08 17:03:51 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

class HumanB
{
    private:
    
        std::string _name;
        Weapon*     _weapon;
    
    public:

        HumanB( std::string name );
        ~HumanB();
        void attack ( void ) const;
        void setWeapon ( Weapon& weapon );
};
