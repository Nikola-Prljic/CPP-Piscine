#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        ShrubberyCreationForm();
        void createFile( std::string target_name, std::string write_in_file );
        std::string writeAsciiTree( int how_much);

    public:
        ShrubberyCreationForm( Bureaucrat& target);
        ~ShrubberyCreationForm();
};

#endif