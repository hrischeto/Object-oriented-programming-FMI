#pragma once

enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    OutOfBound
};

constexpr size_t MAX_LEN = 127;

class Employee
{
    char _name[MAX_LEN];
    char _position[MAX_LEN];
    double _salary;
    unsigned _id;

    void setSalary(double salary);

public:
    Employee() = default;
    Employee(unsigned id, const char* name, const char* position, double salary);

    double getSalary() const;
    unsigned getId() const;
    void setName(const char* name);
    void setPosition(const char* position);
    void setId(unsigned id);
    ErrorCode updateSalary(double amount);
    void print() const;
  
};