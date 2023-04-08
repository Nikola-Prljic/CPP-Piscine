/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:24:13 by nprljic           #+#    #+#             */
/*   Updated: 2023/03/23 13:48:41 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_class.hpp"

int main ( void )
{
    Input input;

    input.make_in_out();
    input.copy_file();
    input.in_file.close();
    input.out_file.close();
    
    return (0);
}