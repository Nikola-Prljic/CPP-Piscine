
#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>


class Harl
{
    private :

        enum lvl { DEFAULT, DEBUG, INFO, WARNING, ERROR };
        void debug();
        void info();
        void warning();
        void error();
        void cmd( std::string type, void(Harl::*func)() );
    
    public:
    
        Harl( void );
        ~Harl();
        void complain( std::string level );
        lvl getInput( std::string level );

};

#endif