#pragma once

class Class {
  public:
    Class() = default;
    Class(int value);
    int getValue() const;
    void setValue(int value);

  private:
    int _value;
    bool isRed() const;
};
