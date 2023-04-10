#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal/* , public Brain */
{

    public:

        Brain *_brain;
        Dog( void );
        ~Dog();
        /* void Dog::delete_barin( void ); */
        /* void operator delete(void * p); */

};

#endif