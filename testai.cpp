#include <gtest/gtest.h>
#include "funkcijos.cpp"
#include "struktura.cpp"

////////////////////////////////////////////////
//vidurkio ir medianos testavimas

vector<int> pazymiai = { 8,8,9,7 };
int n = pazymiai.size();

TEST(Vidurkis, RaskVidurki)
{
    EXPECT_EQ(RaskVidurki(n,pazymiai), 8);
}

TEST(Mediana, RaskMediana)
{
    EXPECT_EQ(RaskMediana(n,pazymiai), 8);
}


////////////////////////////////////////////////
//simboliu testavimas

string s = "123";
TEST(Simboliai, ArVienSkaiciai)
{
    EXPECT_EQ(ArVienSkaiciai(s), true);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}