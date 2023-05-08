#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm( Bureaucrat& target);
        ~ShrubberyCreationForm();

        void tmp();
};

#endif