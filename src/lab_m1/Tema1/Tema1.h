#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
     public:
         Tema1();
        ~Tema1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        glm::mat3 modelMatrix;
        float translateX,  translateY;
        float scaleX, scaleY;


        struct Object {
            bool draggable = false;
            int index, stars;
        }o;
        struct position{
            int px, py;
            int index = 0;
            float unghi = 0.0f;
            int scalex = 1, scaley = 1;
            float timp = 0.0f;
        }mat[3][3];
        
        struct hexagon {
            int py;
            int scalex = 1280, scalex2 = 1280;
            int index, pierdute = 0;
            float timp;
            float hexagontime = 0.0f;
        }hex[3];

        struct star {
            int px, py;
            float time = 0.0f;;
            float culeasa = false;
        }stars[3];

        float starstime = 0.0f;
        float timp_stele_romb = 0.0f;

        int distance_stars = 30;
        int nr_stelute = 12;

        float signS = 1;
        int vieti_pierdute = 0;


    };
}   // namespace m1
