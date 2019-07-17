// Below class is required in order to decide priority based on the value of the nodes

#include "BTNode.h"

class Comparison
{
  public:
  bool operator()( BTNode &node1 , BTNode &node2)
  {
    return node1.getValue() < node2.getValue();
  }
};

