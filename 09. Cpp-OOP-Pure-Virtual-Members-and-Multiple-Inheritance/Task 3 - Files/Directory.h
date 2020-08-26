#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>

#include "FileSystemObjectsContainer.h"

using ObjectPtr = std::shared_ptr<FileSystemObject>;
using Objects = std::vector<ObjectPtr>;

class Directory : public FileSystemObject, public FileSystemObjectsContainer {
private:
    Objects items{ };

public:
    explicit Directory(std::string name) : FileSystemObject(std::move(name)) { }

    void add(const ObjectPtr& obj) override {
        this->items.push_back(obj);
    }

    size_t getSize() const override {
        size_t totalSize = 0;
        for (const auto& file : this->items) {
            totalSize += file->getSize();
        }
        return totalSize;
    }
};

#endif // !DIRECTORY_H