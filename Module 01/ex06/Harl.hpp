
#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>

enum lvl { DEFAULT, DEBUG, INFO, WARNING, ERROR };

class Harl
{
    private :

        void debug();
        void info();
        void warning();
        void error();
    
    public:
    
        Harl( void );
        ~Harl();
        void complain( std::string level );

};

#endif