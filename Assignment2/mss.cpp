#include <iostream>
#include <time.h>
using namespace std;

int* maxSubSum1 ( int numbers[], int size)
{
	time_t start, endt;
	int maxSum = 0;
	start = clock();
	for(int i = 0; i<size; ++i)
	{
		for( int j = i; j<size; ++j)
		{
		int thisSum = 0;

		for(int k = i; k<=j; ++k)
		{
			thisSum += numbers[k];
		}
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		}
	}
	endt = clock();
	int* output = new int[2];
	output[0] = maxSum;
	output[1] = endt - start;
	return output;
}

int* maxSubSum2 ( int numbers[], int size)
{
        time_t start, endt;
        int maxSum = 0;
        start = clock();
        for(int i = 0; i<size; ++i)
        {
                int thisSum = 0;

		for( int j = i; j<size; ++j)
                {
                        thisSum += numbers[j];
                
                if(thisSum > maxSum)
                {
                        maxSum = thisSum;
                }
                }
        }
        endt = clock();
        int* output = new int[2];
        output[0] = maxSum;
        output[1] = endt - start;
        return output;
}

int max3( int num1, int num2, int num3)
{
	int temp_max = max(num1, num2);
	return max(temp_max, num3);
}

int maxSumRec( int numbers[], int left, int right)
{
	if(left==right)
		if(numbers[left] > 0)
			return numbers[left];
		else
			return 0;
	int center = (left + right) /2;
	int maxLeftSum = maxSumRec(numbers,left,center);
	int maxRightSum = maxSumRec(numbers, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for( int i = center; i >= left; --i)
	{
		leftBorderSum += numbers[i];
		if(leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}
	int maxRightBorderSum = 0, rightBorderSum = 0;
	for( int j = center + 1; j <= right; ++j)
	{
		rightBorderSum += numbers[j];
		if( rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3( maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int* maxSubSum3( int numbers[], int size)
      {
	      time_t start, endt;
	      start = clock(); 
	      int maxSum = maxSumRec( numbers, 0 , size-1);
	      endt = clock();
	      int* output = new int[2];
	      output[0] = maxSum;
	      output[1] = endt - start;
	      return output; 
      }

int* maxSubSum4( int numbers[], int size)
      {
              time_t start, endt;
              int maxSum = 0, thisSum = 0;
	      start = clock();
	      for( int j = 0; j < size; ++j)
	      {
		      thisSum += numbers[j];
		      if(thisSum > maxSum)
			      maxSum = thisSum;
		      else if(thisSum < 0)
			      thisSum = 0;
	      }
              endt = clock();
              int* output = new int[2];
              output[0] = maxSum;
              output[1] = endt - start;
              return output;
      }
int main() {
	int numbers[2500];
	cout<<"Please enter sequence integers:"<<endl;
	int i = 0;
	while (cin >> numbers[i])
		i++;
	int size = i;
	
	int* maxsum1 = maxSubSum1(numbers, size); 
	int* maxsum2 = maxSubSum2(numbers, size);
	int* maxsum3 = maxSubSum3(numbers, size);
	int* maxsum4 = maxSubSum4(numbers, size);
	cout << "Algorithm 1: " << maxsum1[0] << endl;
	cout << "Algorithm 2: " << maxsum2[0] << endl;
	cout << "Algorithm 3: " << maxsum3[0] << endl;	
	cout << "Algorithm 4: " << maxsum4[0] << endl;
	cout << "Final Results" << endl;
        cout << "Algorithm 1 O(n^3)     : " << maxsum1[1]*1000000/CLOCKS_PER_SEC << " ms" << endl;
	cout << "Algorithm 2 O(n^2)     : " << maxsum2[1]*1000000/CLOCKS_PER_SEC << " ms" << endl;
	cout << "Algorithm 3 O(n lg n)  : " << maxsum3[1]*1000000/CLOCKS_PER_SEC << " ms" << endl;
	cout << "Algorithm 4 O(n)	: " << maxsum4[1]*1000000/CLOCKS_PER_SEC << " ms" << endl;
}
