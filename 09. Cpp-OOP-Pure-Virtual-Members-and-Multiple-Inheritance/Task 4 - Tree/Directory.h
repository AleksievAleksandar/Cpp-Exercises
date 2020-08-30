#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>

#include "FileSystemObjectsContainer.h"

using ObjectPtr = std::shared_ptr<FileSystemObject>;
using Objects = std::vector<ObjectPtr>;

class Directory : public FileSystemObject, public FileSystemObjectsContainer {
private:
    std::vector<std::shared_ptr<FileSystemObject> > nestedObjects;

public:
    explicit Directory(std::string name) : FileSystemObject(std::move(name)) { }

    void add(const ObjectPtr& obj) override {
        this->nestedObjects.push_back(obj);
    }

    size_t getSize() const override {
        size_t totalSize = 0;
        for (const auto& file : this->nestedObjects) {
            totalSize += file->getSize();
        }
        return totalSize;
    }

    std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override {
        return this->nestedObjects.begin();
    }

    std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override {
        return this->nestedObjects.end();
    }
};

#endif // !DIRECTORY_H