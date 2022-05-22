#include "block.h"
#include <vector>

using namespace std;

class Blockchain
{
public:
  Blockchain();
  void AddBlock(Block newBlock); // Creates a new block object from Block class.

private:
  uint32_t miningDifficulty;
  vector<Block> theChain;

  Block getLastBlock() const;
};