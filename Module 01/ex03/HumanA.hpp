/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:12:27 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/08 17:04:01 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

class HumanA
{
    private:
    
        std::string _name;
        Weapon& _weapon;
        HumanA();
    
    public:

        HumanA( std::string name, Weapon& weapon);
        ~HumanA();
        void attack( void ) const;
};
