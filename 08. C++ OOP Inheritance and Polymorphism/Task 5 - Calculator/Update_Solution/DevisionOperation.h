#ifndef DEVISION_OPERATION_H
#define DEVISION_OPERATION_H

#include "Operation.h"

#include <vector>

class DevisionOperation : public Operation
{
    std::vector<int> operands;
    int result;
public:
    void addOperand(int operand) override {
        this->operands.push_back(operand);

        if (this->isCompleted()) {
            this->result = this->operands[0] / this->operands[1];
        }
    }

    bool isCompleted() override {
        return this->operands.size() == 2;
    }

    int getResult() override {
        return this->result;
    }
};

#endif // !DEVISION_OPERATION_H
