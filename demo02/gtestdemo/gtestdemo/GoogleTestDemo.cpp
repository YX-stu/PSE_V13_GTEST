//
// gtest: Defines the entry point for the console application
//

#include "Square-root.h"
#include"gtest/gtest.h"

 TEST(SquareRootTest, PositiveNos) {
	EXPECT_EQ(18.0, square_root(324.0));
	EXPECT_DOUBLE_EQ(25.4, square_root(645.16));
	EXPECT_EQ(16.0, square_root(256.0));
	//EXPECT_EQ(1, 1);
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}