#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

class QueueOverflow : public std::exception {
public:
  QueueOverflow():
    reason("Queue Overflow!")
  {}

  [[nodiscard]] const char* what() const noexcept override
  {
    return reason;
  }

private:
  const char* reason;
};

class QueueUnderflow : public std::exception {
public:
  QueueUnderflow():
    reason("Queue Underflow!")
  {}

  [[nodiscard]] const char* what() const noexcept override
  {
    return reason;
  }

private:
  const char* reason;
};

class WrongQueueSize : public std::exception {
public:
  WrongQueueSize():
    reason("Wrong Queue Size!")
  {}

  [[nodiscard]] const char* what() const noexcept override
  {
    return reason;
  }

private:
  const char* reason;
};

#endif
