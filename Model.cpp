#include "Model.h"

GOLModel::GOLModel()
{}

GOLModel::GOLModel(Cell **data)
{
    setData(data);
}

GOLModel::~GOLModel()
{}

Cell** GOLModel::getData() const
{
    return _data;
}

void GOLModel::setData(Cell **data)
{
    _data = data;
    if (event != nullptr) {
        event();
    }
}

void GOLModel::RegisterDataChangeHandler(DataChangeHandler handler) {
    event = handler;
}
