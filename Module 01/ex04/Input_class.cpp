/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:38:35 by nprljic           #+#    #+#             */
/*   Updated: 2023/08/03 17:27:02 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input_class.hpp"
#include <cstdlib>

Input::Input() {}

Input::Input( std::string filename, std::string s1, std::string s2 ) : s1(s1), s2(s2), in_file(NULL), in_filename(filename), out_file(NULL), out_filename(filename + ".replace")
{
    ft_open_infile();
    ft_open_outfile();
    copy_file();
    if(in_file)
        in_file.close();
    if(out_file)
        out_file.close();
}

Input::~Input( void ){}

void    Input::ft_open_infile( void )
{
    in_file.open(in_filename.c_str(), std::ios::in);
    if(!in_file)
    {
        std::perror("Error");
        std::exit(1);
    }
}

void    Input::ft_open_outfile( void )
{
    out_file.open(out_filename.c_str(), std::ios::out);
    if(!out_file)
    {
        std::perror("Error");
        std::exit(1);
    }
}

void    Input::copy_file( void )
{   
    for ( std::string line ; std::getline( in_file, line ); )
        ft_replace( line );
    return ;
}

void    Input::ft_replace( std::string& line )
{
    int x;
    int start;
    int s1_len;

    s1_len = s1.size();
    for(int i = 0; line[i];)
    {
        x = 0;
        start = i;
        if(line.compare(i, s1_len, s1) == 0)
        {
            line.erase(start, s1_len);
            line.insert(start, s2);
            i += s2.size();
        }
        else
            i++;
    }
    out_file << line + "\n";
}
