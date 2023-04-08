/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:24:57 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/05 18:43:53 by nprljic          ###   ########.fr       */
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

Zombie  *zombieHorde( int N, std::string name );

#endif