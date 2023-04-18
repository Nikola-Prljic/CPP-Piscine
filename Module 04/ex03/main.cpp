#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"

int main( void )
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    /* src->learnMateria(new Cure()); */
    AMateria* ice;
    ice = new Ice();
    AMateria* ice1;
    ice1 = new Ice();

    ICharacter *fio = new Character("Fio");
    fio->equip(ice);
    fio->equip(ice1);
    fio->unequip(69);
    fio->use(1, *fio);
    fio->use(69, *fio);
    fio->unequip(1);
    delete fio;
    // AMateria a; should not work !

    
    return 0;
}