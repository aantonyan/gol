#ifndef __MODEL_H__
#define __MODEL_H__

#include <stdint.h>
#include "common.h"
#include "Cell.h"

class GOLModel
{
public:
    GOLModel();
    GOLModel(Cell **cells);
    ~GOLModel();

    Cell** getData() const;
    void setData(Cell **data);
    void RegisterDataChangeHandler(DataChangeHandler handler);

private:
    Cell **_data;
    DataChangeHandler event = nullptr;
};

#endif

