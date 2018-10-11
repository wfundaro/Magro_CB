#include "SplashScreen.h"   /// class first Scene
#include <Magro.h>

int main(int argc, char **argv){
    /* display flags allegro. See al_set_new_display_flags in documentation allegro 5
    ALLEGRO_WINDOWED, ALLEGRO_FULLSCREEN, ALLEGRO_FULLSCREEN_WINDOW, ALLEGRO_RESIZABLE, ALLEGRO_OPENGL,
    ALLEGRO_OPENGL_3_0, ALLEGRO_DIRECT3D, ALLEGRO_NOFRAME
    */
    Scene* scene = new SplashScreen();  /// new class first Scene
    /// mg::start(start Scene*, screen_width, screen_height, framerate, allegro display flags) see al_set_display_flag() into the allegro doc
    switch(mg::start(scene, 1024, 768, 60.0, ALLEGRO_WINDOWED))
    {
    case mg::AL_INIT :
        /// al_init() fail
        break;
    case mg::AL_INSTALL_KEYBOARD :
        /// al_install_keyboard fail
        break;
    case mg::AL_INSTALL_MOUSE :
        /// al_install_mouse fail
        break;
    case mg::AL_IMAGE_ADDON :
        /// al_init_image_addon fail
        break;
    case mg::AL_FONT_ADDON :
        /// al_init_font_addon fail
        break;
    case mg::AL_TTF_ADDON :
        /// al_init_ttf_addon fail
        break;
    case mg::AL_INSTALL_AUDIO :
        /// al_install_audio fail
        break;
    case mg::AL_ACODEC_ADDON :
        /// al_init_acodec_addon fail
        break;
    case mg::AL_PRIMITIVES_ADDON :
        /// al_init_primitives_addon fail
        break;
    case mg::AL_VIDEO_ADDON :
        /// al_init_video_addon fail
        break;
    case mg::AL_NATIVE_DIALOG :
        /// al_init_native_dialog_addon fail
        break;
    case mg::AL_ERROR_CREATE_DISPLAY :
        /// al_create_display fail
        break;
    case 0 :
        break;
    }
    //std::system("PAUSE");
   return 0;
}
