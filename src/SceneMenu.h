#ifndef SCENEMENU_H
#define SCENEMENU_H
#include <Scene.h>
#include <Magro.h>
#include <iostream>
class SceneMenu : public Scene
{
    public:
        SceneMenu(){};
        virtual void load() override;
        virtual void unload() override;
        virtual bool update(double dt) override;
        virtual void draw() override;
        virtual ~SceneMenu() { unload();};
    private:
        Sprite background = Sprite();
};

#endif // SCENEMENU_H
