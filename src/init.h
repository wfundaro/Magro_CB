#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

///// INSTALL INSTANCE  decomment if you use
#define INSTALL_KEYBOARD
#define INSTALL_MOUSE
#define IMAGE_ADDON
#define PRIMITIVES_ADDON
//#define FONT_ADDON
//#define TTF_ADDON
//#define INSTALL_AUDIO
//#define ACODEC_ADDON      /// Audio codecs addon wav, .flac, .ogg, .opus, .it, .mod, .s3m, .xm, .voc
//#define VIDEO_ADDON
//#define PHYSFS_ADDON      /// PhysicsFS integration
//#define NATIVE_DIALOG    /// Native dialogs support
//#define PLATFORM_SPECIFIC /// Platform-specific functions
//#define DIRECT3D          /// Direct3D integration
//#define OPENGL            /// OpenGL integration
//#define COLOR_ADDON       /// Color addon
//#define MEMFILE_ADDON     /// Memfile interface
////////// Include Allegro headers don't remove /////////////
#ifdef IMAGE_ADDON
#include <allegro5/allegro_image.h>
#endif // IMAGE_ADDON
#ifdef FONT_ADDON
#include <allegro5/allegro_font.h>
#endif // FONT_ADDON
#ifdef TTF_ADDON
#include <allegro5/allegro_ttf.h>
#endif // TTF_ADDON
#ifdef INSTALL_AUDIO
#include <allegro5/allegro_audio.h>
#endif // INSTALL_AUDIO
#ifdef ACODEC_ADDON
#include <allegro5/allegro_acodec.h>
#endif // ACODEC_ADDON
#ifdef PRIMITIVES_ADDON
#include <allegro5/allegro_primitives.h>
#endif // PRIMITIVES_ADDON
#ifdef VIDEO_ADDON
#include <allegro5/allegro_video.h>
#endif // VIDEO_ADDON
#ifdef PHYSFS_ADDON
#include <allegro5/allegro_physfs.h>
#endif // PHYSFS_ADDON
#ifdef NATIVE_DIALOG
#include <allegro5/allegro_native_dialog.h>
#endif // NATIVE_DIALOGS
#ifdef PLATFORM_SPECIFIC
#include <allegro5/allegro_windows.h>
#endif // PLATFORM_SPECIFIC
#ifdef DIRECT3D
#include <allegro5/allegro_direct3d.h>
#endif // DIRECT3D
#ifdef OPENGL
#include <allegro5/allegro_opengl.h>
#endif // OPENGL
#ifdef COLOR_ADDON
#include <allegro5/allegro_color.h>
#endif // COLOR_ADDON
#ifdef MEMFILE_ADDON
#include <allegro5/allegro_memfile.h>
#endif // MEMFILE_ADDON

#endif // INIT_H_INCLUDED
