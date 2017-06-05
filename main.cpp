#include <iostream>
#include <vector>


int trotter(int);


int main()
{

	int x = trotter(46);

	std::cout << x << std::endl;

	return 0;
}


int trotter(int n)
{
  
  //Prevent 'insomnia'
  if(n == 0)
    return -1;

  //vector that holds all unique digits
  std::vector<int> numVec = {0,1,2,3,4,5,6,7,8,9};

  //Will modulus following num and compare
  //to digits of numVec
  int tempN = n;
  int multiplier = 1;
  
  //While digits are in numVec
  //Modulus tempN and cycle through vector
  //comparing each digit.  If matched, delete digit
  while(!numVec.empty())
  {
  
    while(tempN > 0)
    {
      int compareNum = tempN % 10;
      
      for(int i = 0; i < numVec.size(); i++)
      {
        if(compareNum == numVec[i])
        {
            numVec.erase(numVec.begin() + i);
            break;
        }
      }
      //Shift decimal point to left
      tempN /= 10;
    }
    
    if(numVec.empty())
      return n;

    //If no match
    //Add n to itself / multiplier (recursive addition technique)
    //inc multiplier and set tempN to newly set n
    n += n/multiplier;
    multiplier++;
    tempN = n;
  }
    
    //Means error occurred
    return -1;
    
}
