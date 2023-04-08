/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:23:04 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/06 17:24:15 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void )
{
    std::string name;
    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie zombi1(name);
    zombi1.announce();

    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie *zombi2 = newZombie(name);
    zombi2->announce();
    delete zombi2;

    std::cout << "Calling randomChump()." << std::endl;
    
    randomChump("Lenox");
    return (0);
}