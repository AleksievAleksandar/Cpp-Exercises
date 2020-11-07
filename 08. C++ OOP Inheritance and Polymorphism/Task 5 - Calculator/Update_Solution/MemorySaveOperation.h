#ifndef MEMORY_SAVE_OPERATION_H
#define MEMORY_SAVE_OPERATION_H

#include "Operation.h"

#include <string>
#include <stack>

class MemorySaveOperation : public Operation
{
    std::stack<int>& clipboard;
public:
    MemorySaveOperation(std::stack<int>& clipboard) :
        clipboard(clipboard) {}

public:
    virtual void addOperand(int operand) override
    {
        this->clipboard.push(operand);
    }
    virtual int getResult() override
    {
        int currentNumber = this->clipboard.top();
       // this->clipboard.pop();
        return currentNumber;
    }
    virtual bool isCompleted() override
    {
        return false;
    }
};

#endif // !MEMORY_SAVE_OPERATION_H
