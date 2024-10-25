#pragma once

#include "entities/Entity.hpp"

#include <optional>
#include <string>
#include <string_view>

class ClassEntity : public Entity
{
private:
    std::optional<unsigned long> id;
    std::string name;

public:
    ClassEntity(std::string_view name);
    ClassEntity(unsigned long id);

    ClassEntity() = default;
    ~ClassEntity() = default;

    std::optional<unsigned long> getId() const override;
    void setId(unsigned long id) override;

    std::string getName() const;
    void setName(std::string_view name);

    std::string toString() const override;
};
