#include "Model.h"
#include "View.h"

#include "State.h"
#include "Cell.h"

#include <iostream>

using namespace std;

GOLView::GOLView()
{}

GOLView::GOLView(const GOLModel& model)
{
    setModel(model);
}

GOLView::~GOLView()
{}

void GOLView::setModel(const GOLModel& model)
{
    _model = model;
}

void GOLView::draw() const
{
    Cell** data = _model.getData();
    drawBorder();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (data[i][j].getState() == STATES::DEAD) {
                cout << ".";
            }
            else if (data[i][j].getState() == STATES::ALIVE){
                cout << "X";
            }
        }
        cout << endl;
    }
    drawBorder();
}

void GOLView::drawBorder() const
{
    for (int i = 0; i < ROWS; i++) {
        cout << "=";
    }
    cout << endl;
}
