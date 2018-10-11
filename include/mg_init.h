#ifndef MG_INIT_H_INCLUDED
#define MG_INIT_H_INCLUDED
typedef float vtime;

namespace mg
{
    enum transition { none, fadeIn, fadeOut, fadeOutIn, mix , Tmove, Rmove, Dmove, Lmove, Tmove2, Rmove2, Dmove2, Lmove2, zoom, zoom2 };

    enum error_allegro
    {
        AL_INIT = 1, AL_INSTALL_KEYBOARD, AL_INSTALL_MOUSE, AL_IMAGE_ADDON, AL_FONT_ADDON, AL_TTF_ADDON,
        AL_INSTALL_AUDIO, AL_ACODEC_ADDON, AL_PRIMITIVES_ADDON, AL_VIDEO_ADDON, AL_NATIVE_DIALOG,
        AL_ERROR_CREATE_DISPLAY
    };
}


#endif // MG_INIT_H_INCLUDED
