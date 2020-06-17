#include "pch.h"
////#include "pch.cpp"
////#include "gtest/gtest.h" 
//
double Square_root(const double a)
{
	if (a >= 0)
		return sqrt(a);
	else
		return -1;
}
//
//TEST(TestCaseName, TestName) {
//	TestBody();
//}
//
//TEST(TestCaseName, TestName1) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}
//
//TEST(TestCaseName, TestName2) {
//	ASSERT_EQ(1, 1);
//	ASSERT_TRUE(true);
//}
//
TEST(SquareRootTest, ZeroAndNegativeNos) {
ASSERT_EQ(0.1, Square_root(0.0));
ASSERT_EQ(0.0, Square_root(-22.0));
}

TEST(SquareRootTest, PositiveNos) {
	EXPECT_EQ(19.0, Square_root (324.0));
	EXPECT_EQ(15.0, Square_root(256.0));
	EXPECT_DOUBLE_EQ(25.4, Square_root (645.16));
}


//
////
//// Predicate Assertions
////
//TEST(TestCaseName, NearTest) {
//	EXPECT_NEAR(2.00001, 2.000011, 0.0000001);
//}
//
//testing::AssertionResult AssertNear(const char* a_expr, const char* f_expr, int a, int f) {
//	if (2.00001 - 2.000011 == 1e-007)
//		return testing::AssertionSuccess();
//	testing::Message msg;
//	msg << "The difference of " << a_expr << " should be: " << 2.00001 - 2.000011 << " but not: " << f_expr;
//	return testing::AssertionFailure(msg);
//}
//
//TEST(AssertSquareRootTest, HandleFail)
//{
//	EXPECT_PRED_FORMAT2(AssertNear, 2.00001 - 2.000011, 1e-007);
//}
//
////testing::AssertionResult AssertSquareRoot(const char* a_expr, const char* f_expr, int a, int f) {
////	if (Square_root(a) == f)
////		return testing::AssertionSuccess();
////	testing::Message msg;
////	msg << "The square root of " << a_expr << " should be: " << Square_root(a) << " but not: " << f_expr;
////	return testing::AssertionFailure(msg);
////}
////
////TEST(AssertSquareRootTest, HandleFail)
////{
////	EXPECT_PRED_FORMAT2(AssertSquareRoot, 256, 15);
////}
//
////
//// Type Check
////
template <typename T> class SquareRootType {
public:
	void Bar() { testing::StaticAssertTypeEq<double, T>; }
};

TEST(TypeAssertionTest, Demo)
{
	SquareRootType<bool> squareRootType;
	squareRootType.Bar();
}
//
////
//// Death Test
////
double squareroot(double num) {
	if (num < 0.0) {
		std::cerr << "Error: Negative Input\n";
		exit(-1);
		// Code for 0 and positive numbers follow
	}
}

TEST(SquareRootTest, ZeroAndNegativeNos1) {
	ASSERT_EQ(0.0, squareroot(0.0));
	ASSERT_EXIT(squareroot(-22.0), ::testing::ExitedWithCode(-1), "Error: Negative Input");
}
//
//
////
//// Global Case
////
class SquareRootEnviroment : public testing::Environment
{
public:
	virtual void SetUp()
	{
		std::cout << "SquareRoot SquareRootEnviroment SetUp" << std::endl;
	}
	virtual void TearDown()
	{
		std::cout << "SquareRoot SquareRootEnviroment TearDown" << std::endl;
	}
};
//
////
//// FixtureTest
////
class mySRTest : public testing::Test {
public:
	void SetUp() {
		std::cout << "SquareRoot Test start" << std::endl;
	}

	void TearDown() {
		std::cout << "SquareRoot Test end" << std::endl;
	}
};

TEST_F(mySRTest, UnitTest1)
{
	EXPECT_EQ(2.0, Square_root(4.0));
	EXPECT_EQ(-1, Square_root(-22.0));
}

TEST_F(mySRTest, UnitTest2)
{
	EXPECT_EQ(3.0, Square_root(9.0));
	EXPECT_EQ(-1, Square_root(-22.0));
}
//TEST_F(mySRTest, UnitTest2)
//{
//	// Test code 
//}
//
////
//// TestSuite
////
//class SR {
//public:
//	double calc(const double a) {
//		if (a >= 0)
//			return sqrt(a);
//		else
//			return -1;
//	}
//	void Init() {
//		std::cout << "SquareRoot Calculation start" << std::endl;
//	}
//	void Finalize() {
//		std::cout << "SquareRoot Evaluation end" << std::endl;
//	}
//};
//class SRTest :public testing::Test
//{
//protected:
//	virtual void SetUp()
//	{
//		srtest.Init();
//	}
//	virtual void TearDown()
//	{
//		srtest.Finalize();
//	}
//
//	SR srtest;
//};
//
//TEST_F(SRTest, HandleInput)
//{
//	EXPECT_EQ(2.0, srtest.calc(4.0));
//	EXPECT_EQ(-1, srtest.calc(-22.0));
//}
//
////TEST_F(SRTest, HandleNoneZeroInput_Error)
////{
////	EXPECT_EQ(-1, srtest.calc(-22.0));
////}
//
////
////  Parameter
////
////
// Returns true if n is a prime number.
bool IsPrime(int n)
{
	// Trivial case 1: small numbers
	if (n <= 1) return false;

	// Trivial case 2: even numbers
	if (n % 2 == 0) return n == 2;

	// Now, we have that n is odd and n >= 3.

	// Try to divide n by every odd number i, starting from 3
	for (int i = 3; ; i += 2) {
		// We only have to try i up to the square root of n
		if (i > n / i) break;

		// Now, we have i <= n/i < n.
		// If n is divisible by i, n is not prime.
		if (n % i == 0) return false;
	}
	// n has no integer factor in the range (1, n), and thus is prime.
	return true;
}

class IsPrimeParamTest : public::testing::TestWithParam<int>
{

};

INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));


TEST_P(IsPrimeParamTest, HandleTrueReturn)
{
	int n = GetParam();
	EXPECT_TRUE(IsPrime);
}
//
//
////
//// Main function 
////
int main(int argc, char** argv) {
	//testing::AddGlobalTestEnvironment(new SquareRootEnviroment);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
