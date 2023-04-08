/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:32:49 by nprljic           #+#    #+#             */
/*   Updated: 2023/03/23 13:40:58 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP

# include <iostream>
# include <fstream>

class Input
{
    public:

        std::string     s1;
        std::string     s2;
        std::fstream    in_file;
        std::string     in_filename;
        std::fstream    out_file;
        std::string     out_filename;
        
        Input( void );
        ~Input();
        void    make_in_out( void );
        void    copy_file( void );
        void    ft_replace( std::string& line );
};

int     error_test( std::fstream* file );

#endif