#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        ShrubberyCreationForm();
        void createFile( std::string file_name );
        std::string writeAsciiTree( int how_much);

    public:
        ShrubberyCreationForm( Bureaucrat& target);
        ~ShrubberyCreationForm();

        void tmp();
};

#endif