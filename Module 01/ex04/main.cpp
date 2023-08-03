/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:24:13 by nprljic           #+#    #+#             */
/*   Updated: 2023/08/03 17:09:17 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_class.hpp"

std::string read_input( std::string msg)
{
    std::cout << msg;
    std::getline( std::cin, msg );
    return msg;
}

int main ( void )
{
    std::string filename, s1, s2;

    filename = read_input( "filename: ");
    s1 = read_input( "s1: ");
    s2 = read_input( "s2: ");
    Input input( filename, s1, s2);
    return (0);
}