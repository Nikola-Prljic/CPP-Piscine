/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:23:04 by nprljic           #+#    #+#             */
/*   Updated: 2023/02/05 19:28:45 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <limits>

int input_test(int max)
{
    int i;
    
    std::cout << "enter hore size:" << std::endl;
    while (true)
    {
        std::cin >> i;
        if (!std::cin || i > max || i < 1)
        {
            std::cout << "Just int < 21! Enter again:" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else 
            break;
    }
    return (i);
}

int main ( void )
{
    int N;
    Zombie *horde;
    
    N = input_test(20);
    std::cout << "Creating zombie horde of " << N << std::endl;
    horde = zombieHorde(N, "Lenox");
    for(int i = 0; i < N; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}
