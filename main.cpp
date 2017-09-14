#include <iostream>
#include "Model.h"
#include "View.h"
#include "Controller.h"
#include "Cell.h"

#include "common.h"

GOLView *gView;
GOLModel *gModel;

void DataChange() {
    gView->draw();
}

int main()
{
    // Glinder setup
    Cell **input = new Cell*[ROWS];
    for (int i = 0; i < COLUMNS; i++) {
        input[i] = new Cell[COLUMNS];
    }
    input[0][1].setState(STATES::ALIVE);
    input[1][2].setState(STATES::ALIVE);
    input[2][0].setState(STATES::ALIVE);
    input[2][1].setState(STATES::ALIVE);
    input[2][2].setState(STATES::ALIVE);
    // End of Glinder setup

    gModel = new GOLModel(input);
    gView = new GOLView(*gModel);
    gModel->RegisterDataChangeHandler(&DataChange);

    GOLController controller(*gModel, *gView);
    controller.Load();

    for (int i = 0; i < COLUMNS; i++) {
        delete input[i];
    }
    delete []input;

    return 0;
}

