// Compile using g++ -o programName main.cpp
#include "blockchain.h"

int main(void)
{
  Blockchain blockchain = Blockchain();

  cout << "Mining block 1..." << endl;
  blockchain.AddBlock(Block(1, "Block 1's Data"));

  cout << "Mining block 2..." << endl;
  blockchain.AddBlock(Block(2, "Block 2's Data"));

  cout << "Mining block 3..." << endl;
  blockchain.AddBlock(Block(3, "Block 3's Data"));

  return 0;
}