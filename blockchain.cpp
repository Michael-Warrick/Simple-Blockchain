#include "blockchain.h"

Blockchain::Blockchain()
{
  // Beginning of blockchain so no previous block. We give this first block the name Genesis Block.
  theChain.emplace_back(Block(0, "Genisis Block")); // Appends new element to the back of a vector

  // Sets the mining difficulty, the higher the number, the harder it becomes to mine.
  miningDifficulty = 1;
}

// Adding block to the blockchain...
void Blockchain::AddBlock(Block newBlock)
{
  newBlock.previousHash = getLastBlock().GetHash(); // Gets previous hash from last block's hash
  newBlock.MineBlock(miningDifficulty); // mine's that block with set difficulty

  theChain.push_back(newBlock); // Finally adds block to the "stack" or in our case, the chain
}

// Retrieval of the last block in the blockchain.
Block Blockchain::getLastBlock() const
{
  return theChain.back(); // returns last element on the stack (last block in the chain). 
}