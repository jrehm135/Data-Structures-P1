#include <string>
#include <vector>
#include <cxxtest/TestSuite.h>

#include "search.h"

class SearchTests : public CxxTest::TestSuite
{
public:
   //This function tests to see if linear search can find a valid middle value
	void testLinearSearch1( void )
   {
	 SearchResultType<int> searcher = linear_search(testVector, 4);
     TS_ASSERT(searcher.found == true);
	 TS_ASSERT(searcher.value == 4);
	 TS_ASSERT(searcher.index == 1);
   }
	//This function tests to see if linear search can find an invalid middle value
   void testLinearSearch2(void)
   {
	   SearchResultType<int> searcher = linear_search(testVector, 5);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 10);
	   TS_ASSERT(searcher.index == 4);
   }
   //This function uses linear search to see if other variable types can be used successfully
	void testLinearSearch3(void)
   {
	   std::string foo = "foo";
	   SearchResultType<std::string> searcher = linear_search(testVec, foo);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == "foo");
	   TS_ASSERT(searcher.index == 0);
   }
	//This function tests to see if linear search can find a valid start value
	void testLinearSearch4(void)
	{
		SearchResultType<int> searcher = linear_search(testVector, 2);
		TS_ASSERT(searcher.found == true);
		TS_ASSERT(searcher.value == 2);
		TS_ASSERT(searcher.index == 0);
	}
	//This function tests to see if iterative binary search can find a valid middle value
   void testIterativeSearch1(void)
   {
	   SearchResultType<int> searcher = iterative_binary_search(testVector, 4);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == 4);
	   TS_ASSERT(searcher.index == 1);
   }
   //This function tests to see if iterative binary search can find an invalid middle value
   void testIterativeSearch2(void)
   {
	   SearchResultType<int> searcher = iterative_binary_search(testVector, 5);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 4);
	   TS_ASSERT(searcher.index == 1);
   }
   //This function uses iterative binary search to see if other variable types can be used successfully
   void testIterativeSearch3(void)
   {
	   std::string foo = "hell";
	   SearchResultType<std::string> searcher = iterative_binary_search(testVec, foo);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == "bar");
	   TS_ASSERT(searcher.index == 1);
   }
   //This function tests to see if iterative binary search can find a valid start value
   void testIterativeSearch4(void)
   {
	   SearchResultType<int> searcher = iterative_binary_search(testVector, 2);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == 2);
	   TS_ASSERT(searcher.index == 0);
   }
   //This function tests to see if iterative binary search can find an invalid start value
   void testIterativeSearch5(void)
   {
	   SearchResultType<int> searcher = iterative_binary_search(testVector, 1);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 2);
	   TS_ASSERT(searcher.index == 0);
   }
   //This function tests to see if iterative binary search can find a valid end value
   void testIterativeSearch6(void)
   {
	   SearchResultType<int> searcher = iterative_binary_search(testVector, 10);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == 10);
	   TS_ASSERT(searcher.index == 4);
   }
   //This function tests to see if iterative binary search can find an invalid end value
   void testIterativeSearch7(void)
   {
	   SearchResultType<int> searcher = iterative_binary_search(testVector, 11);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 10);
	   TS_ASSERT(searcher.index == 4);
   }
   //This function tests to see if recursive binary search can find a valid middle value
   void testRecursiveSearch1(void)
   {
	   SearchResultType<int> searcher = recursive_binary_search(testVector, 4);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == 4);
	   TS_ASSERT(searcher.index == 1);
   }
   //This function tests to see if recursive binary search can find an invalid middle value
   void testRecursiveSearch2(void)
   {
	   SearchResultType<int> searcher = recursive_binary_search(testVector, 5);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 4);
	   TS_ASSERT(searcher.index == 1);
   }
   //This function uses recursive binary search to see if other variable types can be used
   void testRecursiveSearch3(void)
   {
	   std::string foo = "foo";
	   SearchResultType<std::string> searcher = recursive_binary_search(testVec, foo);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == "foo");
	   TS_ASSERT(searcher.index == 0);
   }
   //This function tests to see if recursive binary search can find a valid start value
   void testRecursiveSearch4(void)
   {
	   SearchResultType<int> searcher = recursive_binary_search(testVector, 2);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == 2);
	   TS_ASSERT(searcher.index == 0);
   }
   //This function tests to see if recursive binary search can find an invalid start value
   void testRecursiveSearch5(void)
   {
	   SearchResultType<int> searcher = recursive_binary_search(testVector, 1);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 2);
	   TS_ASSERT(searcher.index == 0);
   }
   //This function tests to see if recursive binary search can find an invalid end value
   void testRecursiveSearch6(void)
   {
	   SearchResultType<int> searcher = recursive_binary_search(testVector, 10);
	   TS_ASSERT(searcher.found == true);
	   TS_ASSERT(searcher.value == 10);
	   TS_ASSERT(searcher.index == 4);
   }
   //This function tests to see if recursive binary search can find an invalid end value
   void testRecursiveSearch7(void)
   {
	   SearchResultType<int> searcher = recursive_binary_search(testVector, 11);
	   TS_ASSERT(searcher.found == false);
	   TS_ASSERT(searcher.value == 10);
	   TS_ASSERT(searcher.index == 4);
   }
private:
	std::vector<int> testVector = { 2,4,6,8,10 };
	std::vector<std::string> testVec = { "foo", "bar", "hello", "world", "nope" };
};
