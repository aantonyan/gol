#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "View.h"
#include "Model.h"

class GOLController
{
public:
    GOLController(const GOLModel &model, const GOLView &view);
    ~GOLController();

    void setModel(const GOLModel &model);
    void setView(const GOLView &view);

    void Load();

private:
    GOLModel _model;
    GOLView _view;

    void generateNextState();
    void applyNextState(Cell **data);
    uint32_t aliveNeighboursCount(Cell **data, int row, int column);
};

#endif
