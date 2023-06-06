#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        ShrubberyCreationForm();
        std::string writeAsciiTree( int how_much) const;
        void createFile( std::string target_name, std::string write_in_file ) const;

    public:
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        void execute( const Bureaucrat& executor) const;
};

#endif