
#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>

class Harl
{
    private :

        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void cmd(std::string a, std::string level, void(Harl::*func)());
    
    public:
    
        Harl( void );
        ~Harl();
        void complain( std::string level );

};

#endif