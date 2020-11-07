#ifndef MEMORY_RECALL_OPERATION_H
#define MEMORY_RECALL_OPERATION_H

#include "Operation.h"

#include <stack>

class MemoryRecallOperation : public Operation
{
    std::stack<int>& clipboard;
public:
    MemoryRecallOperation(std::stack<int>& clipboard) :
        clipboard(clipboard) {}

public:
    virtual void addOperand(int operand) override
    {
        //this->clipboard.push(operand);
    }
    virtual int getResult() override
    {
        int currentNumber = this->clipboard.top();
        this->clipboard.pop();
        return currentNumber;
    }
    virtual bool isCompleted() override
    {
        return !this->clipboard.empty();
    }
};

#endif // !MEMORY_RECALL_OPERATION_H
