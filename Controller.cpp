#include "Controller.h"
#include "State.h"
#include "Cell.h"
#include "common.h"

GOLController::GOLController(const GOLModel &model, const GOLView &view)
{
    setModel(model);
    setView(view);
}

GOLController::~GOLController()
{}

void GOLController::setModel(const GOLModel &model)
{
    _model = model;
}

void GOLController::setView(const GOLView &view)
{
    _view = view;
}

void GOLController::Load()
{
    _view.draw();

    // For testing proposes only generate 20 states
    for (int i = 0; i < 20; i++)
        generateNextState();
}

void GOLController::generateNextState()
{
    Cell **data = _model.getData();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (data[i][j].getState() == STATES::ALIVE) {
                uint32_t aliveNeighCount = aliveNeighboursCount(data, i, j);
                if (aliveNeighCount < 2) {
                    data[i][j].setNextState(STATES::DEAD);
                }
                else if (aliveNeighCount == 2 || aliveNeighCount == 3) {
                    data[i][j].setNextState(STATES::ALIVE);
                }
                else if (aliveNeighCount > 3) {
                    data[i][j].setNextState(STATES::DEAD);
                }
            }
            else {
                uint32_t aliveNeighCount = aliveNeighboursCount(data, i, j);
                if (aliveNeighCount == 3) {
                    data[i][j].setNextState(STATES::ALIVE);
                }
            }
        }
    }
    applyNextState(data);
}

uint32_t GOLController::aliveNeighboursCount(Cell** cells, int row, int column)
{
    uint32_t aliveNeighCount = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        if (i >= 0 && i < ROWS) {
            for (int j = column - 1; j <= column + 1; j++) {
                if (j >= 0 && j < COLUMNS) {
                    if (i == row && j == column)
                        continue;
                    if (cells[i][j].getState() == STATES::ALIVE)
                        ++aliveNeighCount;
                }
            }
        }
    }
    return aliveNeighCount;
}

void GOLController::applyNextState(Cell** cells)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cells[i][j].setState(cells[i][j].getNextState());
            cells[i][j].setNextState(STATES::DEAD);
        }
    }
    _model.setData(cells);
}
