#include <iostream>
#include <cstdint>
#include <ctime>

using namespace std;

/**
 * At this point we will only include the most essential properties for the block:
 * 
 * - index : The height of the block in the blockchain (ex: index[0] = genisisBlock)
 * - data: Any data that is included in the block
 * - timestamp: A timestamp (creation of block/any transactions)
 * - hash: The unique digital signature of the contents of the current block
 * - previousHash: The hash of all the previous block's info
 * 
**/

class Block
{
public:
  string previousHash;
  string GetHash();

  Block(uint32_t inputIndex, const string &inputData); // Parameters passed by reference, can't be changed. Improves efficiency + saves memory.
  void MineBlock(uint32_t miningDifficulty); // Still deciding on when to update the difficulty...  

private:
  uint32_t index;
  int64_t  nonce; // Single used number (hashed/encrypted)
  string data; // Could be transaction data: i.e.: To, From, Amount...
  string hash;
  time_t blockTime; // Wanted to call it just time, c++ function of that name already existed :(

  string CalculateHash() const; // Const means that can't change any variables inside this class. Useful for blockchain.
};

