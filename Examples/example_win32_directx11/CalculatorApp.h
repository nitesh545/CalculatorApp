#pragma once
#include "imgui.h"
#include <string>
#include <iostream>
#include "stb_image.h"

namespace Calci
{
    // button layout of numbers and symbols
    void CalciButtonSetup();

    // button layout of numbers and symbols - second method
    void CalciButtonSetupII();

    // place to enter numbers
    void CalciInputScreen();

    // operations setup like +, -, etc.
    void CalciOperationsSetup();

    // choose and set background image
    void SetUpBackgroundImage();

    // initialise calci
    void CreateCalci();

    // enum to choose operaton
    enum choose_operation
    {
        equals = 0,
        add,
        subtract,
        multiply,
        divide,
        decimal,
        clear
    };

    // one function to handle all calculations
    float OperateTwo(float one, float two);

    // operation button function
    void CalculateWithOperator(choose_operation operation);

    void ShowExampleAppDockSpace(bool* p_open);
}
