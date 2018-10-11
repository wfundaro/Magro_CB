#ifndef ATTRIBUTE_H_INCLUDED
#define ATTRIBUTE_H_INCLUDED
#include <allegro5/allegro.h>
#include <Scene.h>

namespace mg
{
        namespace __mg
    {
        Scene* scene = nullptr;
        typedef struct _sdisplay
        {
            int width;
            int height;
            int flag;
        }sdisplay;
        sdisplay display_settings;
        ALLEGRO_DISPLAY* display = nullptr;
    }

}

#endif // ATTRIBUTE_H_INCLUDED
