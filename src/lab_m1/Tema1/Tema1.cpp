#include "lab_m1/Tema1/Tema1.h"

#include <cstdlib>
#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;

    translateX = 1280;
    translateY = 0;

    scaleX = 1;
    scaleY = 1;
    vieti_pierdute = 0;

    // matricea scena
    for (int i = 0;i < 3;i++) {
        int nry = 330 - i * 130;
        for (int j = 0;j < 3;j++) {
            int nrx = 140 + j * 130;
            mat[i][j] = { nrx, nry, 0 };
        }
    }
    // vectorul pt generare stele
    for (int i = 0;i <3;i++) {
        stars[i].px = rand() % (1260);
        stars[i].py = rand() % (700);
    }
    starstime = static_cast<float>(rand()) / RAND_MAX * (10.0f - 3.0f) + 3.0f;

    // vectorul pt generare hexagoane
    for (int i = 0;i <3;i++) {
        hex[i].py = mat[i][i].py;
        // dupa formula int randomNumber = rand() % (max - min + 1) + min;
        hex[i].index = rand() % (4 - 1 + 1) + 1;
        hex[i].timp = static_cast<float>(rand()) / RAND_MAX * (10.0f - 3.0f) + 3.0f;
    }

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1);
    Mesh* square2 = object2D::CreateSquare("square2", glm::vec3(0, 0, -1), squareSide, glm::vec3(0, 0, 0), false);
    AddMeshToList(square2);


    Mesh* rectangle1 = object2D::CreateRectangle("rectangle1", corner, squareSide * 3 + 60, squareSide / 2, glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle1);


    Mesh* romb1 = object2D::CreateRomb("romb1", glm::vec3(0, 0, 0.5f), squareSide/2.3f, glm::vec3(1, 0.5f, 0.2f), true);
    AddMeshToList(romb1);
    Mesh* romb2 = object2D::CreateRomb("romb2", glm::vec3(0, 0, 0.5f), squareSide / 2.3f, glm::vec3(0.1f, 0, 1), true);
    AddMeshToList(romb2);
    Mesh* romb3 = object2D::CreateRomb("romb3", glm::vec3(0, 0, 0.5f), squareSide / 2.3f, glm::vec3(1, 1, 0.2f), true);
    AddMeshToList(romb3);
    Mesh* romb4 = object2D::CreateRomb("romb4", glm::vec3(0, 0, 0.5f), squareSide / 2.3f, glm::vec3(1, 0.1f, 1), true);
    AddMeshToList(romb4);



    Mesh* hexagon1 = object2D::CreateHexagon("hexagon1", glm::vec3(0, 0, 0.5f), squareSide/2, glm::vec3(1, 0.5f, 0.2f), true);
    AddMeshToList(hexagon1);
    Mesh* hexagon2 = object2D::CreateHexagon("hexagon2", glm::vec3(0, 0, 0.5f), squareSide / 2, glm::vec3(0.1f, 0, 1), true);
    AddMeshToList(hexagon2);
    Mesh* hexagon3 = object2D::CreateHexagon("hexagon3", glm::vec3(0, 0, 0.5f), squareSide / 2, glm::vec3(1, 1, 0.2f), true);
    AddMeshToList(hexagon3);
    Mesh* hexagon4 = object2D::CreateHexagon("hexagon4", glm::vec3(0, 0, 0.5f), squareSide / 2, glm::vec3(1, 0.1f, 1), true);
    AddMeshToList(hexagon4);
    Mesh* hexagonmic = object2D::CreateHexagon("hexagonmic", glm::vec3(0, 0, 1), squareSide /3, glm::vec3(0.5f, 1, 1), true);
    AddMeshToList(hexagonmic);

    Mesh* star0 = object2D::CreateStar("star0", glm::vec3(0, 0, 2), squareSide / 2, glm::vec3(0.5f, 0.5f, 0.5f), true);
    AddMeshToList(star0);
    Mesh* star1 = object2D::CreateStar("star1", glm::vec3(0, 0, 2), squareSide / 2, glm::vec3(1, 0.5f, 0.2f), true);
    AddMeshToList(star1);
    Mesh* star2 = object2D::CreateStar("star2", glm::vec3(0, 0, 2), squareSide / 2, glm::vec3(0.1f, 0, 1), true);
    AddMeshToList(star2);
    Mesh* star3 = object2D::CreateStar("star3", glm::vec3(0, 0, 2), squareSide / 2, glm::vec3(1, 1, 0.2f), true);
    AddMeshToList(star3);
    Mesh* star4 = object2D::CreateStar("star4", glm::vec3(0, 0, 2), squareSide / 2, glm::vec3(1, 0.1f, 1), true);
    AddMeshToList(star4);
    Mesh* star5 = object2D::CreateStar("star5", glm::vec3(0, 0, 2), squareSide / 2, glm::vec3(1, 1, 1), true);
    AddMeshToList(star5);

    Mesh* heart1 = object2D::CreateHeart("heart1", glm::vec3(0, 0, -1), squareSide /9,  glm::vec3(1, 0, 0), true);
    AddMeshToList(heart1);

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.15f, 0.15f, 0.15f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
    
}


void Tema1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();
    if (vieti_pierdute != 3) {
        glm::vec3 corner = glm::vec3(0, 0, 0);
        float squareSide = 100;

        // desenare scena

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(40, 200);
        RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(mat[i][j].px, mat[i][j].py);
                RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
            }
        }

        // STELE
        // dreapta la inimi
        if (nr_stelute > 12) {
            nr_stelute = 12;
        }
        for (int i = 0;i < nr_stelute;i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(930 + distance_stars * i, 600);
            modelMatrix *= transform2D::Scale(0.2f, 0.2f);
            RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);

        }

        // prima arma
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(60, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        // arma 2
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(240, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(270, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        // arma 3
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(420, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(450, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        // arma 4
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(600, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(630, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(660, 590);
        modelMatrix *= transform2D::Scale(0.2f, 0.2f);
        RenderMesh2D(meshes["star0"], shaders["VertexColor"], modelMatrix);

        // GUI
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(100, 660);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(280, 660);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["romb2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(460, 660);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["romb3"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(640, 660);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);

        // inimi rosii, vieti + pulsarea lor
        if (scaleX > 1.2 || scaleX < 1)
            signS *= -1;
        scaleX += deltaTimeSeconds * 0.25 * signS;
        scaleY = scaleX;

        vieti_pierdute = hex[0].pierdute + hex[1].pierdute + hex[2].pierdute;

        // suma hexagoanelor pierdute pe cele 3 linii, determina starea vietilor/ inimilor

        if (vieti_pierdute != 3) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(970, 680);
            modelMatrix *= transform2D::Scale(scaleX, scaleY);
            RenderMesh2D(meshes["heart1"], shaders["VertexColor"], modelMatrix);
        }

        if (vieti_pierdute != 2 && vieti_pierdute != 3) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(1080, 680);
            modelMatrix *= transform2D::Scale(scaleX, scaleY);
            RenderMesh2D(meshes["heart1"], shaders["VertexColor"], modelMatrix);
        }

        if (vieti_pierdute != 1 && vieti_pierdute != 2 && vieti_pierdute != 3) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(1190, 680);
            modelMatrix *= transform2D::Scale(scaleX, scaleY);
            RenderMesh2D(meshes["heart1"], shaders["VertexColor"], modelMatrix);
        }
        ///// stele random de cules
        // animatie cand apar cele 3 stele
        if (!(stars[0].culeasa && stars[1].culeasa && stars[2].culeasa))
            starstime = static_cast<float>(rand()) / RAND_MAX * (5.0f - 2.0f) + 2.0f;

        for (int i = 0;i < 3;i++) {
            stars[i].time += deltaTimeSeconds;
            if (stars[i].time > starstime) {

                // daca nu a fost apasat butonul stang al mouse-ului
                if (stars[i].culeasa == false) {
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(stars[i].px, stars[i].py);
                        modelMatrix *= transform2D::Scale(0.5f, 0.5f);
                        RenderMesh2D(meshes["star5"], shaders["VertexColor"], modelMatrix);
                }
            }
            if (stars[0].culeasa && stars[1].culeasa && stars[2].culeasa) {
                // astept ca toate stelele sa fie culese pentru a da alte evalori random pt toate caracteristicile
                for (int i = 0;i < 3;i++) {
                    stars[i].px = rand() % (1260);
                    stars[i].py = rand() % (700);
                    stars[i].culeasa = false;
                    stars[i].time = 0.0f;
                }
                // setam alta perioada la care sa apara stelele
                starstime = static_cast<float>(rand()) / RAND_MAX * (5.0f - 2.0f) + 2.0f;
            }
        }


        ///// scena cu romburile puse
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                if (mat[i][j].index != 0) {
                    modelMatrix = glm::mat3(1);
                    modelMatrix *= transform2D::Translate(mat[i][j].px, mat[i][j].py);
                    RenderMesh2D(meshes["romb" + std::to_string(mat[i][j].index)], shaders["VertexColor"], modelMatrix);

                    timp_stele_romb += deltaTimeSeconds;
                    // trimite proiectil doar daca inamicul e de acceasi culoare
                    if (mat[i][j].index == hex[i].index) {

                        mat[i][j].unghi += deltaTimeSeconds * 5;
                        modelMatrix = glm::mat3(1);
                        modelMatrix *= transform2D::Translate(mat[i][j].scalex, 0);
                        modelMatrix *= transform2D::Translate(mat[i][j].px + 60, mat[i][j].py);
                        modelMatrix *= transform2D::Scale(0.3f, 0.3f);
                        modelMatrix *= transform2D::Rotate(mat[i][j].unghi);
                        mat[i][j].scalex += 5;
                        RenderMesh2D(meshes["star" + std::to_string(mat[i][j].index)], shaders["VertexColor"], modelMatrix);
                    }
                }
            }
        }

        // hexagoanele care apar random
        for (int i = 0;i < 3;i++) {
            hex[i].hexagontime += deltaTimeSeconds;
            if (hex[i].hexagontime > hex[i].timp) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(hex[i].scalex, hex[i].py);
                hex[i].scalex -= deltaTimeSeconds * 50;
                modelMatrix *= transform2D::Rotate(60);
                RenderMesh2D(meshes["hexagon" + std::to_string(hex[i].index)], shaders["VertexColor"], modelMatrix);

                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(hex[i].scalex2, hex[i].py);
                hex[i].scalex2 -= deltaTimeSeconds * 50;
                modelMatrix *= transform2D::Rotate(60);
                RenderMesh2D(meshes["hexagonmic"], shaders["VertexColor"], modelMatrix);
            }
            if (hex[i].scalex == 0) {

                // hexagonul a ajuns la capat => dau alt evalori random pt toate caracteristicile

                hex[i].pierdute++;
                hex[i].py = mat[i][i].py;

                // dupa formula int randomNumber = rand() % (max - min + 1) + min;

                hex[i].index = rand() % (4 - 1 + 1) + 1;
                hex[i].timp = static_cast<float>(rand()) / RAND_MAX * (12.0f - 3.0f) + 3.0f;
                hex[i].scalex = hex[i].scalex2 = 1280;
                hex[i].hexagontime = 0.0f;
            }
        }

        // aplic rombul pe cursorul mouse-ului

        modelMatrix = glm::mat3(1);
        glm::vec2 cursor = window->GetCursorPosition();
        if (o.draggable) {
            modelMatrix *= transform2D::Translate(cursor.x, resolution.y - cursor.y);
            RenderMesh2D(meshes["romb" + std::to_string(o.index)], shaders["VertexColor"], modelMatrix);
        }
    }
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    glm::ivec2 resolution = window->GetResolution();

    // verific pentru cele 4 romburi (arme), pozitia cursorului

    if (resolution.y - mouseY >= 610 && resolution.y - mouseY <= 710) {
            if (mouseX >= 50 && mouseX <= 150) {

                if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
                {
                    o.draggable = true;
                    o.index = 1;
                    o.stars = 1;
                }
            }
            if (mouseX >= 230 && mouseX <= 330) {

                if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
                {
                    o.draggable = true;
                    o.index = 2;
                    o.stars = 2;
                }
            }
            if (mouseX >= 410 && mouseX <= 510) {
                if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
                {
                    o.draggable = true;
                    o.index = 3;
                    o.stars = 2;
                }
            }

            if (mouseX >= 590 && mouseX <= 690) {
                if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
                {
                    o.draggable = true;
                    o.stars = 3;
                    o.index = 4;
                }
            }
    }

    for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                int pox = mat[i][j].px;
                int poy = mat[i][j].py;

                // daca cursorul se afla in unul dintre patratele verzi si daca exista un romb la acea pozitie
                if (resolution.y - mouseY >= poy - 30 && resolution.y - mouseY <= poy + 30 && mouseX >= pox - 30 && mouseX <= pox + 30 && mat[i][j].index != 0) {

                    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) {

                        mat[i][j].index = 0;
                        mat[i][j].scalex = 0;
                        mat[i][j].scaley = 0;
                    }

                }
            }
    }

    for (int i = 0;i < 3;i++) {
         int pox = stars[i].px;
         int poy = stars[i].py;
         if (resolution.y - mouseY >= poy - 30 && resolution.y - mouseY <= poy + 30 && mouseX >= pox - 30 && mouseX <= pox + 30) {
             if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {
                 stars[i].culeasa = true;
                 nr_stelute++;
             }
         }
    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    glm::ivec2 resolution = window->GetResolution();
    if (o.draggable == true) {
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                int pox = mat[i][j].px;
                int poy = mat[i][j].py;
                if (resolution.y - mouseY >= poy - 30 && resolution.y - mouseY <= poy + 30 && mouseX >= pox - 30 && mouseX <= pox + 30 && mat[i][j].index == 0) {

                    // buton 1 inseamna stanga && daca sunt destule stelute disponibie
                    if (button == 1 && nr_stelute >= o.stars) {
                        o.draggable = false;
                        nr_stelute -= o.stars;
                        mat[i][j].index = o.index;
                    }
                    // buton 2 inseamna dreapta
                    if (button == 2) {
                        mat[i][j].index = 0;
                        mat[i][j].scalex = 0;
                        mat[i][j].scaley = 0;


                    }
                }
            }
        }
        o.draggable = false;
    }
    for (int i = 0;i < 3;i++) {
        int pox = stars[i].px;
        int poy = stars[i].py;
        if (resolution.y - mouseY >= poy - 30 && resolution.y - mouseY <= poy + 30 && mouseX >= pox - 30 && mouseX <= pox + 30) {

            // butonul stang
            if (button == 1) {

                stars[i].culeasa = true;
            }
        }
    }
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
