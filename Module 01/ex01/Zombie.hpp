/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:24:57 by nprljic           #+#    #+#             */
/*   Updated: 2023/08/04 12:35:51 by nprljic          ###   ########.fr       */
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

        Zombie( void );
        ~Zombie();
        void setname( std::string name );
        void announce( void );
};

Zombie  *zombieHorde( const int N, std::string name );

#endif