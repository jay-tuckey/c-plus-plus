#include "ItemType.h"

struct NodeType;

// Two Exception Classes
class FullStack
{
};

class EmptyStack
{
};

class StackType
{
 public:
  StackType();
  ~StackType();
  void Push(ItemType);
  void Pop();
  ItemType Top();
  bool IsFull() const;
  bool IsEmpty() const;
 private:
  NodeType* topPtr;
};
