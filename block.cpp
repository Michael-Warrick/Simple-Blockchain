#include "block.h"
#include "sha256.h"
#include <sstream>

// Repeating the signature we specified in block.h + copying parameter contents into variables
Block::Block(uint32_t inputIndex, const string &inputData) : index(inputIndex), data(inputData)
{
  nonce = -1;
  blockTime = time(nullptr); // Current time
}

// Creation of block's hash accessor
string Block::GetHash()
{
  return hash;
}

/*
* For valid block creation + reward, miner must create valid crypto hash of desired block
* which must match requirements for valid hash at that time.
*
* Achieved by counting number of zero's at beginning of hash, if number of 0's is >= difficulty
* level set by network, block is valid.
*
* If hash not valid, nonce variable is incremented and hashed again. Process known as PoW
* (Proof of Work) and is repeated until hash is valid.
*/

// Actual mining...
void Block::MineBlock(uint32_t miningDifficulty)
{
  char *cstr = new char [miningDifficulty + 1]; // Made it a pointer because C++ was bitching about it not being a constant.

  for (uint32_t i = 0; i < miningDifficulty; ++i)
  {
    cstr[i] = '0';
  }
  
  string str(cstr);

  // We compare front portion of string to array of 0's. Loop repeats until match found.
  do
  {
    nonce++;
    hash = CalculateHash();
  } while (hash.substr(0, miningDifficulty) != str);
  
  // This only gets printed once match is found.
  cout << "Block mined: " << hash << endl;
}

// Calculating the hash, we use inline because it makes the code more efficient.
inline string Block::CalculateHash() const
{
  stringstream sStream;

  // Loading all our values into one stream.
  sStream << index << blockTime << data << nonce << previousHash;

  // Returning our output from sha256 using our stream data.
  return sha256(sStream.str());
}