#ifndef MEMORY_SAVE_OPERATION_H
#define MEMORY_SAVE_OPERATION_H

#include "Operation.h"

#include <memory>
#include <stack>

class MemorySaveOperation : public Operation
{
    std::shared_ptr<std::stack<int> > result;
    bool complete = false;
public:
    MemorySaveOperation(std::shared_ptr<std::stack<int> > result);

    void addOperand(int operand) override;
    int getResult() override;
    bool isCompleted() override;
};

#endif // !MEMORY_SAVE_OPERATION_H