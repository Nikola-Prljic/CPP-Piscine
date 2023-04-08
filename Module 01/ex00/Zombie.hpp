/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:24:57 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/03 21:52:11 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
    
        std::string _name;
    
    public:

        Zombie( std::string name );
        ~Zombie();
        void announce( void );
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif