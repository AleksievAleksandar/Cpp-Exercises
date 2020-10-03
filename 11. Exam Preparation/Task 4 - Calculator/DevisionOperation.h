#ifndef DEVISION_OPERATION_H
#define DEVISION_OPERATION_H

#include "Operation.h"

#include <vector>

class DevisionOperation : public Operation
{
    std::vector<int> operands;
    int result;
public:
    void addOperand(int operand) override;

    bool isCompleted() override;

    int getResult() override;
};

#endif // !DEVISION_OPERATION_H
