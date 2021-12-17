#include "v2.cpp"
#include <gtest/gtest.h>

 
TEST(ClassTestSuite, StartsEmpty) {
    Student testStudent;
    ASSERT_EQ("", testStudent.pavarde());
    ASSERT_EQ("", testStudent.vardas());
    ASSERT_EQ(0, testStudent.galutinis());
    ASSERT_EQ(0, testStudent.galutinis_paz());
    ASSERT_EQ(0, testStudent.egz_paz());
}

struct StudentTest : testing::Test {
    Student* testStudent;
    StudentTest() {
        testStudent = new Student;
    }
    ~StudentTest() {
        delete testStudent;
    }
};

TEST(fTest, readStrTest) {
    readStr("vardas1 pavarde1 4 7 8 6 4 6 ");
    EXPECT_EQ(8, temp.size());
}

TEST_F(StudentTest, assignTest) {
    testStudent->setwordread(temp);
    testStudent->assign();
    EXPECT_EQ(6, testStudent->egz_paz());
}

// TEST_F(StudentTest, pazTest) {
//     testStudent->calcGalutinis();
//     EXPECT_EQ(10.0, testStudent->galutinis_paz());
// }
    
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }