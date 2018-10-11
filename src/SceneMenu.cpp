#include "SceneMenu.h"
#include <Magro.h>
#include <iostream>
#include "SplashScreen.h"
void SceneMenu::load()
{

    background.load("media/ftl_menu.jpg");
    background.set_scale_to_screen();
    std::cout << "load SceneMenu" << std::endl;
}

bool SceneMenu::update(double dt) /// dt is in second
{
    static float time = 0.0;
    if(time >= 2.0)
    {
        time = 0.0;
        Scene* scene = new SplashScreen();
        mg::change_scene(scene, static_cast<mg::transition>(1+ rand() % mg::zoom2), 2.0, static_cast<mg::tweening>(rand() % mg::sinInOut));
        //mg::change_scene(scene, mg::zoom , 2.0, static_cast<mg::tweening>(rand() % mg::sinInOut));
    }
    time += dt;
	return false;
}

void SceneMenu::draw()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    background.draw();

}

void SceneMenu::unload()
{
    std::cout << "Unload SceneMenu" << std::endl;
}
