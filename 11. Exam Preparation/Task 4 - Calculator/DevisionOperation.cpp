#include "DevisionOperation.h"

void DevisionOperation::addOperand(int operand)
{
    this->operands.push_back(operand);

    if (this->isCompleted()) {
        this->result = this->operands[0] / this->operands[1];
    }
}

bool DevisionOperation::isCompleted()
{
    return this->operands.size() == 2;
}

int DevisionOperation::getResult()
{
    return this->result;
}
