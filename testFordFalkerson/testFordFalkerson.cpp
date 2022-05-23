#include "pch.h"
#include "CppUnitTest.h"
#include"..\kurs sem 4\edge.h"
#include"..\kurs sem 4\FordFalkerson.h"
#include"..\kurs sem 4\list.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testFordFalkerson
{
	TEST_CLASS(testFordFalkerson)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{/*
S O 3
S P 3
O Q 3
O P 2
P R 2
Q R 4
Q T 2
R T 3 
         *         3
		 *		O-----Q        
		 *	 3/	|     | \2
		 *	S	|2    |2 T========== QT+RT=5
		 *	 3\ |     | /3
		 *		P-----R
		 *        2        
		 */		
			List<Edge> listEdg;
			listEdg.pushBack(Edge{ "S","O",3,0,1 });
			listEdg.pushBack(Edge{ "S","P",3,0,2 });
			listEdg.pushBack(Edge{ "O","Q",3,1,3 });
			listEdg.pushBack(Edge{ "O","P",2,1,2 });
			listEdg.pushBack(Edge{ "P","R",2,2,4 });
			listEdg.pushBack(Edge{ "Q","R",4,3,4 });
			listEdg.pushBack(Edge{ "Q","T",2,3,5 });
			listEdg.pushBack(Edge{ "R","T",3,4,5 });
			List<string> listStr;
			listStr.pushBack("S");  listStr.pushBack("O"); listStr.pushBack("P"); listStr.pushBack("Q"); listStr.pushBack("R"); listStr.pushBack("T");
			Assert::AreEqual(5, fordFalkerson(&listEdg,&listStr));
		}
		TEST_METHOD(TestMethod2)
		{/*
S O 3
S P 3
O Q 3
P R 2
Q T 2
R T 3              
		 *         3
		 *		O-----Q
		 *	 3/	        \2
		 *	S	        T========== QT+PR=4
		 *	 3\         /3
		 *		P-----R
		 *        2
		 */
			List<Edge> listEdg;
			listEdg.pushBack(Edge{ "S","O",3,0,1 });
			listEdg.pushBack(Edge{ "S","P",3,0,2 });
			listEdg.pushBack(Edge{ "O","Q",3,1,3 });
			listEdg.pushBack(Edge{ "P","R",2,2,4 });
			listEdg.pushBack(Edge{ "Q","T",2,3,5 });
			listEdg.pushBack(Edge{ "R","T",3,4,5 });
			List<string> listStr;
			listStr.pushBack("S");  listStr.pushBack("O"); listStr.pushBack("P"); listStr.pushBack("Q"); listStr.pushBack("R"); listStr.pushBack("T");
			Assert::AreEqual(4, fordFalkerson(&listEdg, &listStr));
		}
		TEST_METHOD(TestMethod3)
		{/*
S O 3
S P 3
O Q 3
P R 2
R T 3
		 *         3
		 *		O-----Q
		 *	 3/	        
		 *	S	        T========== PR=4
		 *	 3\         /3
		 *		P-----R
		 *        2
		 */
			List<Edge> listEdg;
			listEdg.pushBack(Edge{ "S","O",3,0,1 });
			listEdg.pushBack(Edge{ "S","P",3,0,2 });
			listEdg.pushBack(Edge{ "O","Q",3,1,3 });
			listEdg.pushBack(Edge{ "P","R",2,2,4 });
			listEdg.pushBack(Edge{ "R","T",3,4,5 });
			List<string> listStr;
			listStr.pushBack("S");  listStr.pushBack("O"); listStr.pushBack("P"); listStr.pushBack("Q"); listStr.pushBack("R"); listStr.pushBack("T");
			Assert::AreEqual(2, fordFalkerson(&listEdg, &listStr));
		}
		TEST_METHOD(TestMethod4)
		{/*
S O 3
S P 3
O Q 3
P R 2
R T 3
		 *         3
		 *		O-----Q
		 *	 3/
		 *	S	        T========== PR=4
		 *	 3\         /0
		 *		P-----R
		 *        2
		 */
			List<Edge> listEdg;
			listEdg.pushBack(Edge{ "S","O",3,0,1 });
			listEdg.pushBack(Edge{ "S","P",3,0,2 });
			listEdg.pushBack(Edge{ "O","Q",3,1,3 });
			listEdg.pushBack(Edge{ "P","R",2,2,4 });
			listEdg.pushBack(Edge{ "R","T",0,4,5 });
			List<string> listStr;
			listStr.pushBack("S");  listStr.pushBack("O"); listStr.pushBack("P"); listStr.pushBack("Q"); listStr.pushBack("R"); listStr.pushBack("T");
			Assert::AreEqual(0, fordFalkerson(&listEdg, &listStr));
		}
	};
}
