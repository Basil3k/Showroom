#pragma comment(lib, "<..\\packages\Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1\build\native\include\gtest\gtest.h>")

#include "..\\packages\Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1\build\native\include\gtest\gtest.h"
#include <math.h>



double square(const double x)
{
   return sqrt(x);
}


TEST(Squa, PositiveNos)
{
   EXPECT_EQ(18.0, square(324.0));
   EXPECT_EQ(25.4, square(645.16));
   EXPECT_EQ(50.3321, square(2533.310224));
}

TEST(SquareRootTest, ZeroAndNegativeNos) 
{
   ASSERT_EQ(0.0, square(0.0));
   ASSERT_EQ(-1, square(-22.0));
}

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv); v
      return RUN_ALL_TESTS();
}