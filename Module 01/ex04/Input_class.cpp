/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:38:35 by nprljic           #+#    #+#             */
/*   Updated: 2023/03/23 15:38:51 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_class.hpp"

Input::Input( void )
{
    std::cout << "filename: ";
    std::cin >> this->in_filename;
    std::cout << "s1: ";
    std::cin >> this->s1;
    std::cout << "s2: ";
    std::cin >> this->s2;
    this->out_filename = this->in_filename + ".replace";
    return ;
}

Input::~Input( void )
{
    return ;
}

void    Input::make_in_out( void )
{
    this->in_file.open(this->in_filename, std::ios::in);
    error_test( &this->in_file );
    this->out_file.open(this->out_filename, std::ios::out);
    error_test( &this->out_file );
    return ;
}

int error_test( std::fstream* file )
{
    if(!file)
    {
        std::cout << "Error: file opening failed!\n";
        exit (EXIT_FAILURE);
    }
    if(!file->good())
    {
        std::cout << "Error: in file!\n";
        exit (EXIT_FAILURE);
    }
    return (0);
}

void    Input::copy_file( void )
{   
    for (std::string line ; std::getline(this->in_file, line); )
    {
        ft_replace(line);
        this->out_file << line << '\n';
    }
    return ;
}

void    Input::ft_replace( std::string& line )
{
    int x;
    int start;
    int s1_len;

    s1_len = this->s1.size();
    for(int i = 0; line[i];)
    {
        x = 0;
        start = i;
        if(line.compare(i, s1_len, this->s1) == 0)
        {
            line.erase(start, s1_len);
            line.insert(start, this->s2);
            i += this->s2.size();
        }
        else
            i++;
    }
    return ;
}
