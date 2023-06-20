#include <iostream>
#include <vector>
#include "entidades.h"

class mapa  : public entidades{
    private:
        std::vector<entidades> entidad;
    public:
        void load_mapa();
        void load_entidad();
};