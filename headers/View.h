#ifndef __VIEW_H__
#define __VIEW_H__

#include <stdint.h>
#include "Model.h"

class GOLView
{
public:
    GOLView();
    GOLView(const GOLModel& model);
    ~GOLView();

    void draw() const;
    void setModel(const GOLModel& model);

private:
    void drawBorder() const;
    GOLModel _model;
};

#endif
