#pragma once

class Type {
 public:
  virtual ~Type() = 0;

  virtual int toInt() const = 0;
  virtual bool toBoolean() const = 0;
};


