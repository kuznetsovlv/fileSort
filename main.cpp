#include "fileArray.h"

int main()
{
	FileArray arr1("1.tmp", OUT, true), arr2("2.tmp", OUT, true), arr("arr.txt", OUT);

	arr1.push(1);
	arr1.push(2);
	arr2.push(3);
	arr2.push(4);

	arr.add(arr1);
	arr.add(arr2);

	arr.finalise();

	return 0;
}
