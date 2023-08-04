/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:32:49 by nprljic           #+#    #+#             */
/*   Updated: 2023/08/04 12:33:44 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP

# include <iostream>
# include <fstream>

class Input
{
    private:
        std::string     s1;
        std::string     s2;
        std::fstream    in_file;
        std::fstream    out_file;
        Input( void );

        void    ft_open_infile( std::string in_filename );
        void    ft_open_outfile( std::string out_filename );
        void    copy_file( void );
        void    ft_replace( std::string& line );
    
    public:

        Input( std::string filename, std::string s1, std::string s2 );
        ~Input();
};

#endif