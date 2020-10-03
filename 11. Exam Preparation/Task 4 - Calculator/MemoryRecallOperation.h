#ifndef MEMORY_RECALL_OPERATION_H
#define MEMORY_RECALL_OPERATION_H

#include "Operation.h"

#include <memory>
#include <stack>

class MemoryRecallOperation : public Operation
{
    std::shared_ptr<std::stack<int> > result;

public:
    MemoryRecallOperation(std::shared_ptr<std::stack<int> > result);

    void addOperand(int operand) override;
    int getResult() override;
    bool isCompleted() override;
};

#endif // !MEMORY_RECALL_OPERATION_H