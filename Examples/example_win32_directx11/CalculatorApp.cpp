#include "CalculatorApp.h"

#include <d3d10.h>

float val {0.0f};                                   // V will store this
float* V{&val};                                         // value inside InputScreen

float FirstVal{0.0f};
float SecondVal{0.0f};

namespace Calci
{
    choose_operation operationChooser{};

    void CalciButtonSetup()
    {
        ImVec2 ButnSize {ImVec2(34, 50)};

        ImGui::Button("7", ButnSize);
        ImGui::SameLine();
        ImGui::Button("8", ButnSize);
        ImGui::SameLine();
        ImGui::Button("9", ButnSize);
        ImGui::SameLine();
        ImGui::Button("=", ButnSize);

        ImGui::Button("4", ButnSize);
        ImGui::SameLine();
        ImGui::Button("5", ButnSize);
        ImGui::SameLine();
        ImGui::Button("6", ButnSize);
        ImGui::SameLine();
        ImGui::Button("+", ButnSize);

        ImGui::Button("1", ButnSize);
        ImGui::SameLine();
        ImGui::Button("2", ButnSize);
        ImGui::SameLine();
        ImGui::Button("3", ButnSize);
        ImGui::SameLine();
        ImGui::Button("-", ButnSize);

        ImGui::Button("*", ButnSize);
        ImGui::SameLine();
        ImGui::Button("0", ButnSize);
        ImGui::SameLine();
        ImGui::Button("/", ButnSize);
        ImGui::SameLine();
        ImGui::Button("C", ButnSize);
    }
    void CalciButtonSetupII()
    {
        ImVec2 ButnSize {ImVec2(34, 50)};
        int c{1};

        for (int i{}; i<4; i++)
        {
            for (int j{}; j<3; j++)
            {
                if (c != 1 && c != 4 && c != 7 && c != 10)
                    ImGui::SameLine();

                if (c >= 10)
                {
                    if (j == 1)
                    {
                        ImGui::PushID(c);
                        ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.1f, 0.6f, 0.6f, 0.025f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.1f, 0.7f, 0.7f, 0.1f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.1f, 0.8f, 0.8f, 0.25f));
                        if (ImGui::Button("0", ButnSize))
                        {
                            *V *= 10;
                        }
                        ImGui::PopStyleColor(3);
                        ImGui::PopID();
                    }
                    else if (j == 0)
                    {
                        ImGui::Dummy(ButnSize);
                        ImGui::SameLine();
                    }
                }
                else
                {
                    ImGui::PushID(c);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.1f, 0.6f, 0.6f, 0.025f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.1f, 0.7f, 0.7f, 0.1f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.1f, 0.8f, 0.8f, 0.25f));
                    if (ImGui::Button(std::to_string(c++).c_str(), ButnSize))
                    {
                        *V = *V * 10 + (c-1);
                    }
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }
            }
        }
    }
    void CalciInputScreen()
    {
        //static char str1[128] = "";
        ImGui::InputFloat("Ans", V);
    }
    void CalciOperationsSetup()
    {
        ImVec2 ButnSize {ImVec2(34, 50)};
        int c{0};

        for (int i{}; i<3; i++)
        {
            for (int j{}; j<3; j++)
            {
                if (c != 0 && c != 2 && c != 4 && c != 6)
                    ImGui::SameLine();
                ImGui::PushID(c);
                ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.4f, 0.6f, 0.6f, 0.025f));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.4f, 0.7f, 0.7f, 0.1f));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.4f, 0.8f, 0.8f, 0.25f));
                switch (c)
                {
                    case 0:
                        if (ImGui::Button("=", ButnSize))
                        {
                            std::cout << "pressed =\n";
                            CalculateWithOperator(equals);
                        }
                    break;
                    case 1:
                        if (ImGui::Button("+", ButnSize))
                        {
                            std::cout << "pressed +\n";
                            CalculateWithOperator(add);
                        }
                    break;
                    case 2:
                        if (ImGui::Button("-", ButnSize))
                        {
                            std::cout << "pressed -\n";
                            CalculateWithOperator(subtract);
                        }
                    break;
                    case 3:
                        if (ImGui::Button("*", ButnSize))
                        {
                            std::cout << "pressed *\n";
                            CalculateWithOperator(multiply);
                        }
                    break;
                    case 4:
                        if (ImGui::Button("/", ButnSize))
                        {
                            std::cout << "pressed /\n";
                            CalculateWithOperator(divide);
                        }
                    break;
                    case 5:
                        if (ImGui::Button(".", ButnSize))
                        {
                            std::cout << "pressed .\n";
                            CalculateWithOperator(decimal);
                        }
                    break;
                    case 6:
                        if (ImGui::Button("C", ButnSize))
                        {
                            std::cout << "pressed C\n";
                            CalculateWithOperator(clear);
                        }
                    break;
                    default:
                        break;
                }
                c++;
                ImGui::PopStyleColor(3);
                ImGui::PopID();
            }
        }
    }
    void SetUpBackgroundImage()
    {
        //ImGui::Image()
    }
    void CreateCalci()
    {
        ShowExampleAppDockSpace(nullptr);

        ImGui::Begin("Screen");
        // input screen
        CalciInputScreen();
        ImGui::End();

        // numbers
        ImGui::Begin("Numbers");
        CalciButtonSetupII();
        //ImGui::ShowDemoWindow();
        ImGui::End();

        // operations
        ImGui::Begin("Operations");
        CalciOperationsSetup();
        ImGui::End();
    }

    float OperateTwo(float one, float two)
    {
        float ans{};
        switch (operationChooser)
        {
            case equals:
                break;
            case add:
                ans = one + two;
                break;
            case subtract:
                ans = one - two;
                break;
            case multiply:
                ans = one * two;
                break;
            case divide:
                ans = one / two;
                break;
            case decimal:
                break;
            default:
                ans = 0.0f;
                break;
        }
        return ans;
    }
    void CalculateWithOperator(choose_operation operation)
    {
        if (operation != equals && operation != decimal && operation != clear)
        {
            operationChooser = operation;
            FirstVal = *V;
            *V = 0.0f;
        }
        else if (operation == equals)
        {
            SecondVal = *V;
            *V = OperateTwo(FirstVal, SecondVal);
            operationChooser = operation;
        }
        else if (operation == clear)
        {
            operationChooser = clear;
            *V = 0.0f;
        }
    }

    void ShowExampleAppDockSpace(bool* p_open)
{
    // If you strip some features of, this demo is pretty much equivalent to calling DockSpaceOverViewport()!
    // In most cases you should be able to just call DockSpaceOverViewport() and ignore all the code below!
    // In this specific demo, we are not using DockSpaceOverViewport() because:
    // - we allow the host window to be floating/moveable instead of filling the viewport (when opt_fullscreen == false)
    // - we allow the host window to have padding (when opt_padding == true)
    // - we have a local menu bar in the host window (vs. you could use BeginMainMenuBar() + DockSpaceOverViewport() in your code!)
    // TL;DR; this demo is more complicated than what you would normally use.
    // If we removed all the options we are showcasing, this demo would become:
    //     void ShowExampleAppDockSpace()
    //     {
    //         ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    //     }

    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else
    {
        dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    if (!opt_padding)
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", p_open, window_flags);
    if (!opt_padding)
        ImGui::PopStyleVar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    // Submit the DockSpace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Options"))
        {
            // Disabling fullscreen would allow the window to be moved to the front of other windows,
            // which we can't undo at the moment without finer window depth/z control.
            ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
            ImGui::MenuItem("Padding", NULL, &opt_padding);
            ImGui::Separator();

            if (ImGui::MenuItem("Flag: NoSplit",                "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0))                 { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
            if (ImGui::MenuItem("Flag: NoResize",               "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0))                { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
            if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0))  { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
            if (ImGui::MenuItem("Flag: AutoHideTabBar",         "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))          { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
            if (ImGui::MenuItem("Flag: PassthruCentralNode",    "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
            ImGui::Separator();

            if (ImGui::MenuItem("Close", NULL, false, p_open != NULL))
                *p_open = false;
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    ImGui::End();
}
}
